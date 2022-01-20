package reciever;
//server

import util.*;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Date;
import java.util.Timer;
import java.util.TimerTask;


public class ReceiverPhysicalLayer {
    private static final String CONNECTION_ESTABLISHED = "Connection Established.";
    static DataLinkLayer dataLinkLayer ;
    static Timer timer ;

    static ArrayList<Integer> throughList = new ArrayList<>();
    private static final Object throughLock = new Object();
    private static  int noOfFrames = 0 ;

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

    static class SayHello extends TimerTask {
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
        timer = new Timer();
        timer.schedule(new SayHello(), 0, 100);
        while (more){
            System.out.println("Waiting for Client to send frame.");
            Socket s2 = serverSocket.accept();
            System.out.println("Connection established.");
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(s2.getOutputStream());
            ObjectInputStream objectInputStream = new ObjectInputStream(s2.getInputStream());
            Frame frame = (Frame) objectInputStream.readObject();
            synchronized (throughLock){
                noOfFrames++;
            }
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

