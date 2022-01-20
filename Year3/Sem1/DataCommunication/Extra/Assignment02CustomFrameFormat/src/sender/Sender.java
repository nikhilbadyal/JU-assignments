package sender;

import Util.CheckSum;

import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;

public class Sender {

    private static final String START_OF_FRAME = "<";
    private static final String END_OF_FRAME = ">";
    private static final String NORMAL_FRAME_TYPE = "N";
    private static final String END_FRAME_TYPE = "E";
    private static final String FIELD_DIVIDER = "-";
    private static final int MAX_TRANSMISSION_UNIT = 24;
    private static final int CHECK_SUMLEN = 4 ;
    private static final int SEG_LEN = 2;
    private static final int SEQUENCE_NUMBER_LEN = 2;

    public static void main(String[] args){
        String line ;
        try {
            line = new String(Files.readAllBytes(Paths.get(".\\Data\\sentData.txt")));
            sendMessage(line);
        } catch (IOException e) {
            e.printStackTrace();
        }
        //sendMessage("nd Kashmi");


    }
    private static void sendMessage(String message){

        ArrayList<String> frames = new ArrayList<>();
        int prefixLen = START_OF_FRAME.length() + SEQUENCE_NUMBER_LEN + FIELD_DIVIDER.length() + NORMAL_FRAME_TYPE.length() + FIELD_DIVIDER.length() + SEG_LEN + FIELD_DIVIDER.length();
        int suffixLen = FIELD_DIVIDER.length()+ CHECK_SUMLEN + END_OF_FRAME.length();
        int maxMessageLength = MAX_TRANSMISSION_UNIT - prefixLen -suffixLen ;
        int j = 0 ;
        while(message.length() > maxMessageLength){
            String temp = message.substring(0,maxMessageLength);
            frames.add(createFrame(temp, NORMAL_FRAME_TYPE,j));
            j++;
            message = message.substring(maxMessageLength);
        }
        frames.add(createFrame(message, END_FRAME_TYPE,j));

        int noOfFrames = frames.size();

        System.out.println("Client started to send frame no.");
        try(Socket s= new Socket("localhost",4444)) {
            DataOutputStream dataOutputStream = new DataOutputStream(s.getOutputStream());
            dataOutputStream.writeInt(noOfFrames);
        } catch (Exception e) {
            System.out.println("Receiver not responding.");
            return;
        }
        String getStatus ;
        int i = 1;
        while (i != noOfFrames+1){
            getStatus = PhysicalLayer.sendFrame(frames.get(i-1),5555,i);
            if(getStatus.equalsIgnoreCase("next") || getStatus.equalsIgnoreCase("end")) {
                i += 1;
            }else{
                System.out.println("Resending the frame.");
            }
        }
    }
    private static String createFrame(String message, String frameType, int sequenceNumber){
        return START_OF_FRAME + formattedSeqNum(sequenceNumber) + FIELD_DIVIDER  + frameType + FIELD_DIVIDER + getPayloadLen(message) + FIELD_DIVIDER + message + FIELD_DIVIDER + CheckSum.getChecksum(message) + END_OF_FRAME;
    }

    private static String formattedSeqNum(int sequenceNumber) {
        String seqString = Integer.toString(sequenceNumber);
        if(sequenceNumber < 10 ){
            seqString = "0" + seqString;
        }
        return  seqString;
    }

    private static String getPayloadLen(String segment) {
        int len = segment.length();
        String segLen = Integer.toString(len);
        if(len < 10){
            segLen = "0" + segLen;
        }
        return  segLen;
    }

}
