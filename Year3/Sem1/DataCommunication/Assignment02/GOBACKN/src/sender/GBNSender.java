package sender;

import utilclasses.Packet;
import utilclasses.TimerPacket;
import utilclasses.Util;

import java.io.FileInputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.time.Duration;
import java.time.Instant;
import java.util.*;
import java.util.concurrent.Semaphore;

public class GBNSender {

    private static final int ACK_SIZE = 12;
    private static final int BUFFER_SIZE = 500;
    private static final int HEADER_SIZE = 12;
    private static final int SEQNUM_MODULO = 256;
    private static final Semaphore available = new Semaphore(10);

    private FileInputStream fileStream;

    private DatagramSocket socket;
    private InetAddress channelAddress;
    private int port;

    private Deque<Packet> queue;
    private static final Object queueLock = new Object();

    private Timer timer;
    private int timeout;
    private static final Object timerLock = new Object();

    private volatile int base;
    private volatile int nextSeqNum;

    private volatile boolean sendFinished;

    private Map<Integer, Instant> map;
    private  ArrayList<Long> rtt ;
    long timeElapsed ;

    GBNSender(String file, String hostname, int port, int timeout) throws Exception {
        this.port = port;
        this.timeout = timeout;
        base = 0;
        nextSeqNum = 0;
        channelAddress = InetAddress.getByName(hostname);
        queue = new ArrayDeque<>();
        map = new HashMap<>();
        rtt= new ArrayList<>();
        fileStream = new FileInputStream(file);
        sendFinished = false;
    }

    class TimeoutTask extends TimerTask {
        public void run() {
            // when timeout, retransmit all packets in the window
            synchronized (queueLock) {
                Iterator<Packet> itr = queue.iterator();
                while (itr.hasNext()) {
                    Sender.totalSent++;
                    Util.sendData(itr.next(), channelAddress, port, socket);
                }
            }

            // schedule a new timeout task
            synchronized (timerLock) {
                timer.schedule(new TimeoutTask(), timeout);
            }
        }
    }

    private void receivePackets() {
        byte[] buffer = new byte[ACK_SIZE];
        DatagramPacket receiveDatagram = new DatagramPacket(buffer, buffer.length);
        Packet packet;

        while (!sendFinished || !queue.isEmpty()) {
            try {
                // get ack number
                socket.receive(receiveDatagram);
                packet = Packet.getPacket(receiveDatagram.getData());
                System.out.println(String.format("PKT RECV ACK %s %s", packet.getLength(), packet.getSeqNum()));
                int ackNum = packet.getSeqNum();

                if(map.containsKey(ackNum)){
                    Instant start = map.get(ackNum);
                    Instant end = Instant.now();
                    timeElapsed = Duration.between(start, end).toMillis();
                    rtt.add(timeElapsed);
                    timeElapsed = 0 ;

                }

                // calculate the number of received packets
                int rcvNum = ackNum - base + 1;
                if (ackNum < base) {
                    rcvNum += SEQNUM_MODULO;
                }

                // remove the received packet in the window
                if (rcvNum <= 10) {
                    synchronized (queueLock) {
                        for (int i = 0; i < rcvNum; i++) {
                            queue.poll();
                            available.release();
                        }
                    }
                    base = (ackNum + 1) % SEQNUM_MODULO;
                }

                // reset timer
                if (base == nextSeqNum) {
                    timer.cancel();
                } else {
                    startTimer();
                }

            } catch (Exception e) {
                System.out.println("Exception when receiving datagram packet");
            }
        }
    }

    private void startTimer() {
        synchronized (timerLock) {
            timer.cancel();
            timer = new Timer();
            timer.schedule(new TimeoutTask(), timeout);
        }
    }

    public void start() throws Exception {

        // create a new timer
        timer = new Timer();

        // create socket to send and receive data
        socket = new DatagramSocket();

        // create new thread to receive ACK packets
        Thread receiveThread = new Thread(new Runnable() {
            @Override
            public void run() {
                receivePackets();
            }
        });
        receiveThread.start();

        // send file data
        System.out.println("Start to send file data");
        while (true) {
            // make packet
           // Thread.sleep(100);
            Sender.totalUsefullSent++;
            byte[] buffer = new byte[BUFFER_SIZE];
            int readNum = fileStream.read(buffer, 0, BUFFER_SIZE);
            if (readNum < 0){
                System.out.println("Read Num"+buffer.length);
                sendFinished = true;
                break;
            }
            Packet packet = new Packet(0, readNum + HEADER_SIZE, nextSeqNum, buffer);

            // send the packet
            available.acquire();
            synchronized (queueLock) {
                queue.offer(packet);
                map.put(nextSeqNum,Instant.now());
                Sender.totalSent++;
            }

            Util.sendData(packet, channelAddress, port, socket);

            // reset timer
            if (base == nextSeqNum) {
                startTimer();
            }

            // update nextSeqNum
            nextSeqNum = (nextSeqNum + 1) % SEQNUM_MODULO;
        }

        // join the receive thread
        receiveThread.join();
        // end sender session
        Util.endSenderSession(base, channelAddress, port, socket);
        System.out.println("Finish sending file");
        socket.close();
        fileStream.close();
        timer.cancel();
        int count = 0 ;
        int size = rtt.size();
        for(long lo : rtt){
            count += lo;
        }
        var avg = count/size;
        System.out.println("Avg Rtt is :"+avg);
        System.out.println(Sender.totalUsefullSent);
        System.out.println(Sender.totalSent);
        double chk =(double) Sender.totalUsefullSent/(double)Sender.totalSent;
        System.out.println(chk);
        double perc = chk*100;
        System.out.println("Performance of the system is "+perc);
    }
}