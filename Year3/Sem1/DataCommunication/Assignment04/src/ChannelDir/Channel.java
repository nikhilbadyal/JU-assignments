package ChannelDir;

import java.io.FileReader;
import java.io.FileWriter;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.DatagramChannel;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.util.*;


public class Channel {
    static int maxDelay;
    static double discardProb;
    static long currentTime;
    static Random r;

    static {
        Channel.maxDelay = 1;
        Channel.discardProb = 0.0;
    }

    public static int getPort() {
        Random random;
        int i;
        for (random = new Random(), i = random.nextInt(65535); i < 20000; i = random.nextInt(65535)) {
        }
        return i;
    }

    public static DatagramChannel createDataOutSocket(final Selector selector, final String fileName, final boolean b) {
        DatagramChannel open = null;
        String next = null;
        int nextInt = 0;
        try {
            open = DatagramChannel.open();
            open.configureBlocking(false);
            open.socket().bind(new InetSocketAddress(getPort()));
            open.register(selector, 1, new Record());
        } catch (Exception ex) {
            System.err.println("FWD socket creation failed");
            System.exit(1);
        }
        try {
            final FileReader source = new FileReader(fileName);
            final Scanner scanner = new Scanner(source);
            next = scanner.next();
            nextInt = scanner.nextInt();
            scanner.close();
            source.close();
        } catch (Exception ex2) {
            System.err.println("ERROR: cannot find or read file " + fileName);

            System.exit(1);
        }
        try {
            ((Record) open.keyFor(selector).attachment()).clientAddress = new InetSocketAddress(next, nextInt);
        } catch (Exception ex3) {
            System.err.println("FWD socket 'connection' failed");
            System.exit(1);
        }
        if (b) {
            System.out.println("DATA socket `connected' to " + next + "/" + nextInt);
        }
        return open;
    }

    public static DatagramChannel createDataInSocket(final Selector sel, final String fileName, final boolean b) {
        DatagramChannel open = null;
        String hostAddress = null;
        int port = 0;
        try {
            open = DatagramChannel.open();
            open.configureBlocking(false);
        } catch (Exception ex) {
            System.err.println("ERROR: RET socket creation failed");
            System.exit(1);
        }
        try {
            port = getPort();
            open.socket().bind(new InetSocketAddress(port));
            open.register(sel, 1, new Record());
        } catch (Exception ex2) {
            System.err.println("ERROR: cannot bind ACK socket to local port " + port);
            System.exit(1);
        }
        try {
            hostAddress = InetAddress.getLocalHost().getHostAddress();
        } catch (Exception ex3) {
            System.err.println("ERROR: cannot obtain local address");
            System.exit(1);
        }
        try {
            final FileWriter fileWriter = new FileWriter(fileName);
            fileWriter.write(hostAddress + " " + port);
            fileWriter.flush();
            fileWriter.close();
        } catch (Exception ex4) {
            System.out.println("ACK socket bound to " + hostAddress + "/" + port);
            ;
            System.exit(1);
        }
        if (b) {
            System.out.println("ACK socket bound to " + hostAddress + "/" + port);

        }
        return open;
    }

    public static Packet receivePacket(final SelectionKey selectionKey, final boolean b, final boolean b2) {
        final String s = b ? "RET" : "FWD";
        final Packet packet = new Packet();
        final DatagramChannel datagramChannel = (DatagramChannel) selectionKey.channel();
        final Record record = (Record) selectionKey.attachment();
        record.buffer.clear();
        try {
            record.clientAddress = datagramChannel.receive(record.buffer);
            System.out.println(Arrays.toString(record.buffer.array()));
        } catch (Exception ex) {
            ex.printStackTrace();
            System.exit(1);
        }
        record.buffer.flip();
        final int limit = record.buffer.limit();
        if (limit < 4) {
            System.err.println("error reading from " + s + " socket");
            System.exit(1);
        }
        System.out.println("Got packet");
        packet.length = record.buffer.getInt();
        System.out.println("Packet length is "+packet.length);
        record.buffer.get(packet.data, 0, packet.length - 4);
        return packet;
    }

    public static void sendPacket(final Packet packet, final SelectionKey selectionKey, final boolean b, final boolean b2) {
        final String s = b ? "RET" : "FWD";
        if (b2) {
            System.out.println(b + " send packet " + packet.toString());
        }
        final DatagramChannel datagramChannel = (DatagramChannel) selectionKey.channel();
        final Record record = (Record) selectionKey.attachment();
        record.buffer.clear();
        record.buffer.putInt(packet.length);
        record.buffer.put(packet.data, 0, packet.length - 4);
        record.buffer.flip();
        try {
            System.out.println("Sending packet");
            System.out.println(Arrays.toString(record.buffer.array()));
            datagramChannel.send(record.buffer, record.clientAddress);
        } catch (Exception ex) {
            ex.printStackTrace();
            System.err.println("Error writing to " + s + " socket");

            System.exit(1);
        }
    }

    public static void main(final String[] array) {
        long long1 = 0L;
        boolean b = false;
        long n = 0L;
        final TreeSet<Packet> set = new TreeSet<Packet>(new PacketComparator());
        if (array.length < 4) {
            System.err.println("usage: channel <max delay> <discard probability> <random seed> <verbose>");
            System.exit(1);
        }
        try {
            Channel.maxDelay = Integer.parseInt(array[0]);
            if (Channel.maxDelay < 0 || Channel.maxDelay > 999) {
                throw new IllegalArgumentException();
            }
        } catch (Exception ex2) {
            System.err.println("invalid delay: " + array[0]);
            System.exit(1);
        }
        try {
            Channel.discardProb = Double.parseDouble(array[1]);
            if (Channel.discardProb < 0.0 || Channel.discardProb > 1.0) {
                throw new IllegalArgumentException();
            }
        } catch (Exception ex3) {
            System.err.println("invalid discard probability: " + array[1]);
            System.exit(1);
        }
        try {
            long1 = Long.parseLong(array[2]);
        } catch (Exception ex4) {
            System.err.println("invalid discard probability: " + array[2]);
            System.exit(1);
        }
        if (long1 == 0L) {
            Channel.r = new Random();
        } else {
            Channel.r = new Random(long1);
        }
        try {
            if (Integer.parseInt(array[3]) != 0) {
                b = true;
            }
        } catch (Exception ex5) {
            System.err.println("invalid verbose: " + array[3]);
            System.err.println("invalid verbose: " + array[3]);
            System.exit(1);
        }
        Selector open = null;
        try {
            open = Selector.open();
        } catch (Exception ex6) {
            System.err.println("Socket select error");
            System.exit(1);
        }
        final DatagramChannel dataOutSocket = createDataOutSocket(open, "recvInfo", b);
        final DatagramChannel dataInSocket = createDataInSocket(open, "channelInfo", b);
        int n2 = 0;
        int i = 0;
        int select = 0;
        while (i == 0) {
            try {
                select = open.select(n);
            } catch (Exception ex) {
                ex.printStackTrace();
                System.err.println("Select failed");
                System.exit(1);
            }
            Channel.currentTime = System.currentTimeMillis();
            if (select != 0) {
                final Iterator<SelectionKey> iterator = open.selectedKeys().iterator();
                while (iterator.hasNext()) {
                    final SelectionKey selectionKey = iterator.next();
                    if (selectionKey.isReadable()) {
                        final Packet processPacket = receivePacket(selectionKey, selectionKey.channel() == dataInSocket, b);
                        System.out.println(Arrays.toString(processPacket.data));
                        set.add(processPacket);
                        selectionKey.interestOps(1);
                    }
                    iterator.remove();
                }
            }
            n = 0L;
            while (!set.isEmpty()) {
                final Packet packet = set.first();
                set.pollFirst();
                if (set.isEmpty()) {
                    System.out.println(Arrays.toString(packet.data));
                    System.out.println("Set is empty now");
                }
                sendPacket(packet, dataOutSocket.keyFor(open), false, b);
                i = 1;
            }
        }
    }

    static class Record {
        public SocketAddress clientAddress;
        public ByteBuffer buffer;

        Record() {
            this.buffer = ByteBuffer.allocate(100);
        }
    }
}
