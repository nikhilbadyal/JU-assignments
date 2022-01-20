package Reciever;

import Support.Channel;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class RecieverPhysicalLayer implements Runnable {
    RecieverDataLinkLayer recieverDataLinkLayer;
    Channel channel;

    public  RecieverPhysicalLayer(){
        recieverDataLinkLayer = new RecieverDataLinkLayer();
        channel = new Channel();
    }

    public void  run(){
        recieverStopWait();
    }
    public void sendAck(ObjectOutputStream objectOutputStream, String ack)  {
        try{
            //channel.addDelay();
            objectOutputStream.writeObject(ack);
        }catch(IOException e){
            System.out.println("Can't send ack" + e);
        }
    }
    public void recieverStopWait(){
        int port = (int)(5000 + Thread.currentThread().getId());
        try{
            ServerSocket serverSocket = new ServerSocket(port);
            System.out.println("Waiting for connection");
            Socket s2 = serverSocket.accept();
            System.out.println("Connection Established");
            ObjectInputStream objectInputStream = new ObjectInputStream(s2.getInputStream());
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(s2.getOutputStream());

            boolean goOn = true;

            while(goOn){
                String frame = (String)objectInputStream.readObject();
                System.out.println(frame);

                if(!recieverDataLinkLayer.checkValidity(frame)){
                    System.out.println("Writing resend");
                    sendAck(objectOutputStream, "resend"); //Sending ack
                }else{
                    System.out.println("Writing next");
                    sendAck(objectOutputStream, "next"); //Sending ack
                    if(recieverDataLinkLayer.getFrameType(frame).equals("E")){
                        goOn = false;
                    }
                }

            }


        }catch(Exception e){
            System.out.println("Exception");
            e.printStackTrace();
        }

        System.out.println("\n\n\n\n"+recieverDataLinkLayer.getData());

    }
    public static void main(String[] args){
        int noOfRecievers = 3;
        for(int i=1;i<=noOfRecievers;i++){
            Thread thread = new Thread(new RecieverPhysicalLayer(), Integer.toString(i));
            thread.start();
        }

    }
}
