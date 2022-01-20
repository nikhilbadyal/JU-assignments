
import utiliclasses.MyPacket;
import utiliclasses.Util;

import java.io.BufferedReader;
import java.io.FileReader;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Arrays;
import java.util.Scanner;


public  class Sender {
    private static final int HEADER_SIZE = 4;
    public static void main(String[] args) throws Exception {
        FileReader fileReader = new FileReader("channelInfo");
        BufferedReader bufferedReader = new BufferedReader(fileReader);
        String line = bufferedReader.readLine();
        if (line == null) {
            throw new Exception("empty channel info");
        }
        String[] tokens = line.split("\\s");
        String hostName = tokens[0];
        InetAddress channelAddress = InetAddress.getByName(hostName);
        int port = Integer.parseInt(tokens[1]);
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of stations");
        int numberOfStations = sc.nextInt();
        int[] dataInEachStation = new int[numberOfStations ];
        {
            int i = 0;
            while (i < numberOfStations) {
                System.out.println("Enter data for Station " + i);
                dataInEachStation[i] = sc.nextInt();

                i++;
            }
        }
        CDMA cdma = new CDMA();
        String data = cdma.setUp(dataInEachStation,numberOfStations);
        System.out.println("String data is "+data);
        byte[] buffer = data.getBytes();
        System.out.println(Arrays.toString(buffer));
        int payLoadSize = buffer.length;
        System.out.println(payLoadSize);
      /*  DatagramSocket socket = new DatagramSocket();
        MyPacket myPacket = new MyPacket(payLoadSize+HEADER_SIZE,  buffer);
                Util.sendData(myPacket, channelAddress, port, socket);
*/
        MyPacket myPacket = MyPacket.getPacket(buffer);
        String data1 = new String(myPacket.getData());
        cdma.receiver(8,data1);

    }
}