package sender;


import util.CRC;
import util.Frame;

import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;

public class SenderDataLinkLayer {
    private static final String SOURCE_MAC = "80:91:33:93:B7:7F"; //17
    private static final String DESTINATION_MAC = "80:91:33:93:B7:7F"; //17
    private static final String FIELD_DIVIDER = "-";
    private static final String NORMAL_FRAME_TYPE = "N";
    private static final String END_FRAME_TYPE = "E";
    public static final int CRC_LEN = 20 ;
    private static final int MAX_MSG_LEN = 20; //20
    static int frameMod = 100;

    private SenderDataLinkLayer() { throw  new UnsupportedOperationException("Util Class.");}

    public static void main(String[] args){
        String line ;
        try {
            line = new String(Files.readAllBytes(Paths.get(".\\Data\\sentData.txt")));
            sendMessageStopWait(line);
        } catch (IOException  e) {
            e.printStackTrace();
        }
    }
    private static void createAllFrames(ArrayList<String> frames, String message) {
        int j = 0 ;
        while(message.length() > MAX_MSG_LEN){
            j = j % frameMod;
            String temp = message.substring(0,MAX_MSG_LEN);
            frames.add(createFrame(temp,NORMAL_FRAME_TYPE,j));
            j++;
            message = message.substring(MAX_MSG_LEN);
        }
        j = j % frameMod;
        frames.add(createFrame(message,END_FRAME_TYPE,j));

    }

    private static void sendFrameCount(int noOfFrames) {
        System.out.println("Sending No. of frames ");
        try(Socket s= new Socket("localhost",5555)) {
            DataOutputStream dataOutputStream = new DataOutputStream(s.getOutputStream());
            dataOutputStream.writeInt(noOfFrames);
            System.out.println("Sent no. of frames."+ noOfFrames);
        } catch (Exception e) {
            System.out.println("Receiver PhysicalLayer not responding.");
        }

    }

    public static void sendMessageStopWait(String message){
        ArrayList<String> frames = new ArrayList<>();
        createAllFrames(frames,message);
        int noOfFrames = frames.size();
        sendFrameCount(noOfFrames);
        int i= 0 ;
        for(int j = 0 ; j < noOfFrames ; ++j){
            i = i % frameMod;
            System.out.println("Sending frame "+i);
            SenderPhysicalLayer.sendFrameStopWait(new Frame(frames.get(i),i),5555);
            i++;
        }
    }


    private static String createFrame(String message, String frameType, int sequenceNumber){
        if(message.length() < 10 ){
            message = padString(message,message.length());
        }
        String payload = DESTINATION_MAC + FIELD_DIVIDER + SOURCE_MAC + FIELD_DIVIDER + frameType + FIELD_DIVIDER + formatSeq(sequenceNumber) + FIELD_DIVIDER +  getPayloadLen(message) + FIELD_DIVIDER + message ;
        return payload + FIELD_DIVIDER +  CRC.getCrc(payload);
    }

    private static String formatSeq(int sequenceNumber) {
        String seqStr = Integer.toString(sequenceNumber);
        if(sequenceNumber < 10 ){
            seqStr = "0" + sequenceNumber;
        }
        return seqStr;
    }

    private static String padString(String message, int length) {
        char pad = 'x';
        char [] rep = new char[10-length];
        Arrays.fill(rep,pad);
        message += new String(rep);
        return  message;
    }

    private static String getPayloadLen(String segment){
        int len = segment.length();
        String segLen = Integer.toString(len);
        if(len < 10){
            segLen = "0" + segLen;
        }
        return  segLen;
    }

}
