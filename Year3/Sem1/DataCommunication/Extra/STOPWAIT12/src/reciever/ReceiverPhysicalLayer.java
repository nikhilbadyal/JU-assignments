package reciever;
//server

import util.*;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;


public class ReceiverPhysicalLayer {
    private static final String CONNECTION_ESTABLISHED = "Connection Established.";
    static DataLinkLayer dataLinkLayer ;

    public static void main(String[] args) {
        
        receiveStopWait();
    }

    private static int getNoFrame(ServerSocket serverSocket, BufferedWriter bufferedWriter) {
        int noOfFrames = -1;
        try{
            System.out.println("Waiting for Client to send frame number.....");
            Socket s1 = serverSocket.accept();
            System.out.println(CONNECTION_ESTABLISHED);
            DataInputStream dataInputStream = new DataInputStream(s1.getInputStream());
            noOfFrames = dataInputStream.readInt();
            System.out.println("No. of frames are " + noOfFrames);
            dataLinkLayer = new DataLinkLayer(noOfFrames);
            bufferedWriter.write("Started Frame writing at " + new Date());
            bufferedWriter.newLine();
            bufferedWriter.flush();
        }catch (Exception e){
            e.printStackTrace();
        }
        return noOfFrames;
    }

    public  static void receiveStopWait(){
    File file = new File(".\\Data\\STOPWAITReceivedData.txt");
    try(ServerSocket serverSocket = new ServerSocket(5555);FileWriter fileWriter = new FileWriter(file,true);BufferedWriter bufferedWriter = new BufferedWriter(fileWriter)){
        if (!file.exists() && !file.getParentFile().mkdirs() && !file.createNewFile()) {
            throw new IOException("Error making file.");
        }
        int frameCount = getNoFrame(serverSocket,bufferedWriter);
        if(frameCount == -1 ){
            throw new ImplementationError("Unable to get Frame Count.");
        }
        boolean more = true;
        while (more){
            System.out.println("Waiting for Client to send frame.");
            Socket s2 = serverSocket.accept();
            System.out.println("Connection established.");
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(s2.getOutputStream());
            ObjectInputStream objectInputStream = new ObjectInputStream(s2.getInputStream());
            Frame frame = (Frame) objectInputStream.readObject();
            System.out.println("Frame received "+frame.getFrame());
            AckPackage ackPackage = dataLinkLayer.receiveStopWait(frame.getFrame());
            if(sendAckStopWait(ackPackage,objectOutputStream)){
                if(ackPackage.getStatus().equals("end")){
                    more = false;
                }
            }else{
                System.out.println("Asked to resend package.");
            }
        }

    }catch (Exception e){
        e.printStackTrace();
    }
}
    private static boolean sendAckStopWait(AckPackage ackPackage, ObjectOutputStream objectOutputStream) {
        System.out.println("Sending ACK with status "+ackPackage.getStatus());
        String crc = CRC.getCrc(ackPackage.getStatus());
        ackPackage.setCrc(crc);
        try {
          //  Channel.addDelay();
            objectOutputStream.writeObject(ackPackage);
            System.out.println("ACK sent.");
            if(ackPackage.getStatus().equals("next") || ackPackage.getStatus().equals("end")){
                return true;
            }
        }catch (Exception e) {
            try {
                throw new ImplementationError("Error Connecting.");
            } catch (ImplementationError implementationError) {
                implementationError.printStackTrace();
            }
        }
        return  false;
    }
}

