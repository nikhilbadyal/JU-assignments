package utiliclasses;


import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Util {

    public static void sendPacket(byte[] bytes, InetAddress address, int port, DatagramSocket socket) {
        try {
            DatagramPacket sendPacket = new DatagramPacket(bytes, bytes.length, address, port);
            socket.send(sendPacket);
        } catch (Exception e) {
            System.out.println("Exception when sending packet");
        }
    }

    public static void sendData(MyPacket myPacket, InetAddress channelAddress, int port, DatagramSocket socket) {
        Util.sendPacket(myPacket.getBytes(), channelAddress, port, socket);
    }

}
