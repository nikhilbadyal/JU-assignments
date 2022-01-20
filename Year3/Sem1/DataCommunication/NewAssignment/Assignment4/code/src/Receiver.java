
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.*;

import java.util.Scanner;

public class Receiver {

    public static void sendAck(String ack, ObjectOutputStream objectOutputStream){
        try {
            objectOutputStream.writeObject(ack);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        int port = (5000);
        try{
            int noOfRecievers;
            Scanner scanner = new Scanner(System.in);
            System.out.println("Enter numbeer of reccievers : ");
            noOfRecievers = scanner.nextInt();

            ServerSocket serverSocket = new ServerSocket(port);
            System.out.println("Waiting for connection");
            Socket s2 = serverSocket.accept();
            System.out.println("Connection Established");
            ObjectInputStream objectInputStream = new ObjectInputStream(s2.getInputStream());
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(s2.getOutputStream());

            boolean goOn = true;


            String[] allReceiverData = new String[noOfRecievers];
            CDMA cdma = new CDMA();
            cdma.setUp(noOfRecievers);
            while(goOn){
                String frame = (String)objectInputStream.readObject();
                System.out.println(frame);

                String data = frame.substring(1);

                cdma.receiver(noOfRecievers, data, allReceiverData);
//                System.out.println("Writing next");

                sendAck("next", objectOutputStream);//Sending ack

                if(frame.charAt(0) == 'e'){
//                    System.out.println("hello");
                    goOn = false;
                }
            }
            System.out.println("RECEIVED DATA IS : ");
            for(int i=0;i<allReceiverData.length;i++){
                System.out.println("Sender " + (i+1) + " sends : " + allReceiverData[i]);
            }
        }catch(Exception e){
            System.out.println("Exception");
            e.printStackTrace();
        }

    }
}
