package util;

import java.io.IOException;
import java.io.ObjectOutputStream;

import java.util.Random;

public class Channel {
    private static final Random RANDOM = new Random();


    private Channel() {
        throw new UnsupportedOperationException("Util Class.");
    }

    public static void injectSingleBitError(Frame frameObj) {
        String frame = frameObj.getFrame();
        int mtu = frame.length();
        char errorChar = (char) (RANDOM.nextInt(93) + '!');
        int posForError = RANDOM.nextInt(mtu);
        System.out.println("Injection Error at pos " + posForError);
        frame = frame.substring(0, posForError) + errorChar + frame.substring(posForError + 1);
        frameObj.setFrame(frame);
    }

    public static void injectBurstError(Frame frameObj) {
        String frame = frameObj.getFrame();
        int mtu = frame.length();
        int noOfErrors = RANDOM.nextInt(mtu + 1);
        for (int i = 1; i < noOfErrors; ++i) {
            char errorChar = (char) (RANDOM.nextInt(93) + '!');
            int posForError = RANDOM.nextInt(mtu);
            frame = frame.substring(0, posForError) + errorChar + frame.substring(posForError + 1);
        }
        frameObj.setFrame(frame);
    }

    public static void addDelay() {
        try {
            boolean shouldInject = RANDOM.nextBoolean();
            if (shouldInject) {
                int switchCase = RANDOM.nextInt(2);
                switch (switchCase) {
                    case 0:
                        Thread.sleep(100);
                        break;
                    case 1:
                        //Do nothing.
                        break;
                    default:
                        //do nothing
                }
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
            Thread.currentThread().interrupt();
        }

    }

    public static void sendAck(AckPackage ack, ObjectOutputStream objectOutputStream) {
        try {
            objectOutputStream.writeObject(ack);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }




    public static void injectError(Frame frame) {

        Random random = new Random();

        boolean insertOrNot = random.nextBoolean();
        if (insertOrNot) {
            int choice = random.nextInt(2);
            System.out.println("Choice           : " + choice);
            switch (choice) {
                case 0:{
                    System.out.println("Inserting Single bit error");
                    injectSingleBitError(frame);
                }
                case 1: {
                    System.out.println("Inserting Burst error");
                    injectBurstError(frame);
                }
                case 3 :{
                    System.out.println("Adding delay ");
                    addDelay();
                }
                default: {
                    //do nothing
                }
            }
        }
    }


    public static void send (Frame frame, ObjectOutputStream objectOutputStream){


        injectError(frame);

        try {
            System.out.println("Sending frame from channel");
            objectOutputStream.writeObject(frame);
            System.out.println(frame);

        } catch (IOException e) {
            System.out.println("IOException " + e);
        }
    }

}
