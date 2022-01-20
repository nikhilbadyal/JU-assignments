package Util;

import java.util.Random;

public class Channel {
    public static String InjectSingleBitError(String frame, int mtu) {
        Random r = new Random();
        char errorChar = (char) (r.nextInt(93)+'!');
        int posForError = r.nextInt(mtu);
        frame = frame.substring(0,posForError)+errorChar+frame.substring(posForError+1);
        return frame;
    }

    public static String InjectBrustError(String frame , int mtu ) {
        Random r = new Random();
        int noOfErrors = r.nextInt(mtu+1);
        System.out.println(noOfErrors);
        for(int i =1 ; i < noOfErrors ; ++i){
            char errorChar = (char) (r.nextInt(93)+'!');
            int posForError = r.nextInt(mtu);
            frame = frame.substring(0,posForError)+errorChar+frame.substring(posForError+1);
        }
        return frame;

    }
}
