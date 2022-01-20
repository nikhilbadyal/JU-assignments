import utiliclasses.MyPacket;

import java.io.FileOutputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.util.Arrays;

public class Receiver {
    private final static int FIX_PORT = 1234;
    private static final int BUFFER_SIZE = 100;

    private static String getHostName() {
        try {
            return InetAddress.getLocalHost().getHostName();
        } catch (Exception e) {
            return "localhost";
        }
    }
    public static void main(String[] args) throws Exception {
        int port = FIX_PORT;
        DatagramSocket socket;
        while(true) {
            try {
                socket = new DatagramSocket(port);
                break;
            } catch (SocketException e) {
                port++;
            }
        }
        try {
            String recvInfo = getHostName() + " " + port;
            FileOutputStream out = new FileOutputStream("recvInfo");
            out.write(recvInfo.getBytes());
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        byte[] buffer = new  byte[BUFFER_SIZE];
        CDMA cdma = new CDMA();
        cdma.setUp(8);
        DatagramPacket receiveDatagram = new DatagramPacket(buffer, buffer.length);
        System.out.println(Arrays.toString(buffer));
        socket.receive(receiveDatagram);
        System.out.println("GOt packet");
        MyPacket myPacket = MyPacket.getPacket(receiveDatagram.getData());
        String file = "out.txt";
        FileOutputStream fout = new FileOutputStream(file);
        String data = new String(myPacket.getData());
        System.out.println(data+" is ");
        cdma.receiver(8,data);
        fout.write(myPacket.getData());
        fout.close();
        socket.close();

    }
}
