package sender;
import util.*;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.*;
import java.util.Random;

public class SenderPhysicalLayer {
    private static final Random RANDOM = new Random();
    private static final String HOST = "localhost";
    private static final int TIMER = 10;
    private static int resendCount = 0 ;

    private SenderPhysicalLayer() {
        throw new UnsupportedOperationException("Utility Class.");
    }

    public static void  sendFrameStopWait(Frame frame , int  portNumber){
            boolean resend = true;
            String originalFrame = frame.getFrame();
            while (resend){
                try(Socket s= new Socket(HOST,portNumber)) {
                    ObjectOutputStream  objectOutputStream = new ObjectOutputStream(s.getOutputStream());
                    ObjectInputStream objectInputStream = new ObjectInputStream(s.getInputStream());
                    resendCount++;
                    //injectError(frame);
                    System.out.println("Sending frame "+frame.getFrame());
                    Channel.send(frame, objectOutputStream);
                    objectOutputStream.writeObject(frame);
                    System.out.println("Frame sent. Waiting for ACK.");
                    resend = shouldResend(s,objectInputStream,frame , originalFrame);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        System.out.println("Resent frame "+resendCount+" times.");
        resendCount = 0 ;
    }
    private static void injectError(Frame frame) {
        boolean shouldInject = RANDOM.nextBoolean();
        if(shouldInject){
            System.out.println("Frame before error injection "+frame.getFrame());
            int switchCase = RANDOM.nextInt(2);
            switch (switchCase){
                case 0:
                    System.out.println("Injecting Single Bit error.");
                    Channel.injectSingleBitError(frame);
                    break;
                case 1:
                    System.out.println("Injection Burst Error.");
                    Channel.injectBurstError(frame);
                    break;
                default:
                    //do nothing
            }
            System.out.println("Frame after error injection "+frame.getFrame());
        }
    }

    private static boolean shouldResend(Socket socket, ObjectInputStream objectInputStream, Frame frame, String originalFrame) throws IOException, ClassNotFoundException {
        socket.setSoTimeout(TIMER);
        try{
            AckPackage ackPackage  = (AckPackage) objectInputStream.readObject();
            System.out.println("ACK received with status "+ackPackage.getStatus());
            if(ackPackage.getStatus().equals("resend")){
                frame.setFrame(originalFrame);
                System.out.println("Resending Frame.");
                return  true;
            }else{
                return false;
            }
        }catch (SocketTimeoutException socketTimeoutException){
            System.out.println("Tired of waiting for ACK. Resending the frame.");
            return true;
        }

    }
}
