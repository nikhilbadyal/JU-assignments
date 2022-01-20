package Sender;

import Support.Channel;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.net.SocketException;
import java.net.SocketTimeoutException;
import java.util.ArrayList;
import java.util.Random;

public class SenderPhysicalLayer {
    Channel channel;

    public SenderPhysicalLayer(){
        channel= new Channel();
    }
    public String injectError(String frame){
        Random random = new Random();
        boolean insertOrNot = random.nextBoolean();
        if(insertOrNot){
            int choice = random.nextInt(2);
            System.out.println("Choice           : " + choice);
            switch (choice) {
                case 0 -> {
                    System.out.println("Inserting Single bit error");
                    frame = channel.addSingleBitError(frame);
                }
                case 1 -> {
                    System.out.println("Inserting Burst error");
                    frame = channel.addBurstError(frame);
                }
                default ->{
                    //do nothing
                }
            }
        }
        return frame;
    }
    public boolean getAck(ObjectInputStream objectInputStream, Socket s) throws IOException, ClassNotFoundException {
        s.setSoTimeout(1000);

        try{
            System.out.println("Waiting for acknowledgement");
            String ack = (String)objectInputStream.readObject();
            if(ack.equals("resend")){
                return true;
            }else{
                return false;
            }
        }catch(SocketTimeoutException socketTimeoutException){
            System.out.println("SomeThing bad happened, data lost (no ack, Timeout)\n\n\n");
            return true;
        }
    }

    public void sendFramesStopWait(ArrayList<String> frames){
        int port = (int)(5000+Thread.currentThread().getId());
        try{
            Socket s  = new Socket("localhost", port);
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(s.getOutputStream());
            ObjectInputStream objectInputStream = new ObjectInputStream(s.getInputStream());
            for(String frame : frames){
                System.out.println("Frame before error insertion : " + frame);

                String originalFrame = frame;
                frame = injectError(frame);
                System.out.println("Frame after error  insertion : " + frame);
                System.out.println("Writing frame    ("+ frame+")");

                objectOutputStream.writeObject(frame);
                while(getAck(objectInputStream, s)){
                    System.out.println("Sending : " +originalFrame);
                    objectOutputStream.writeObject(originalFrame);
                }
            }

        }catch(Exception e){
            System.out.println("exception");
            System.out.println(e);
        }

    }
}
