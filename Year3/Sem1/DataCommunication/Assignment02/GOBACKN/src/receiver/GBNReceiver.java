package receiver;

import utilclasses.Packet;
import utilclasses.Util;

import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.ArrayList;
import java.util.Timer;
import java.util.TimerTask;

public class GBNReceiver {

    private static final int BUFFER_SIZE = 512;
    private static final int SEQNUM_MODULO = 256;

    private int expectedSeqNum;

    private DatagramSocket socket;
    private FileOutputStream fout;
    Timer timer ;

    private InetAddress channelAddress;
    private int channelPort;
    private boolean getChannelInfo;

    private static  int noOfFrames = 0 ;

    ArrayList<Integer>throughList = new ArrayList<Integer>();
    private final Object throughLock = new Object();

    class SayHello extends TimerTask {
        public void run() {

            synchronized (throughLock){
                try {
                   // System.out.println("Time out."+noOfFrames);
                   // FileWriter fileWriter = new FileWriter("Through.txt",true);
                    throughList.add(noOfFrames);
                    noOfFrames = 0 ;
                } catch (Exception e) {
                    e.printStackTrace();
                    System.exit(1);
                }
            }
        }
    }

    // And From your main() method or any other method


    GBNReceiver(DatagramSocket socket, String file) throws Exception {
        this.socket = socket;
        fout = new FileOutputStream(file);
        expectedSeqNum = 0;
        getChannelInfo = false;
    }
    public void start() throws Exception {

        timer = new Timer();
        timer.schedule(new SayHello(), 0, 100);

        byte[] buffer = new byte[BUFFER_SIZE];
        DatagramPacket receiveDatagram = new DatagramPacket(buffer, buffer.length);

        System.out.println("Start to receive data");
        while(true) {
            // receive packet

            socket.receive(receiveDatagram);
            Packet packet = Packet.getPacket(receiveDatagram.getData());
            System.out.println("Got Packet.");
            synchronized (throughLock){
                noOfFrames++;
            }
            // get channel info
            if (!getChannelInfo) {
                channelAddress = receiveDatagram.getAddress();
                channelPort = receiveDatagram.getPort();
                getChannelInfo = true;
            }

            if (packet.getType() == 2) {
                // end receiver session when receiving EOT
                Util.endReceiverSession(packet, channelAddress, channelPort, socket);
                break;

            } else if (packet.getType() == 0){
                // process data packet
                System.out.printf("PKT RECV DAT %s %s%n", packet.getLength(), packet.getSeqNum());
                if (packet.getSeqNum() == expectedSeqNum) {
                    fout.write(packet.getData());
                    Util.sendACK(expectedSeqNum, channelAddress, channelPort, socket);
                    expectedSeqNum = (expectedSeqNum + 1) % SEQNUM_MODULO;
                } else {
                    Util.sendACK(((expectedSeqNum + SEQNUM_MODULO - 1) % SEQNUM_MODULO),
                            channelAddress, channelPort, socket);
                }
            }
        }

        // close socket and file outputstream
        System.out.println("Finish receiving file");
        fout.close();
        socket.close();
        int count = 0 ;
        int size = 0;
        for(Integer integer : throughList){
            if(integer != 0 ){
               // System.out.println(integer);
                count += integer;
                size++;
            }
        }
        var avg = count/size;
        System.out.println("Avg ThroughPut is :"+avg);
        timer.cancel();
    }
}
