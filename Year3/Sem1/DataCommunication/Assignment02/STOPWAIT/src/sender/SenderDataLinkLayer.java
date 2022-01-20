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
    public static int totalSent = 0 ;
    public  static  int totalUsefullSent = 0 ;
    private static final String SOURCE_MAC = "80:91:33:93:B7:7F"; //17
    private static final String DESTINATION_MAC = "80:91:33:93:B7:7F"; //17
    private static final String FIELD_DIVIDER = "-";
    private static final String NORMAL_FRAME_TYPE = "N";
    private static final String END_FRAME_TYPE = "E";
    public static final int CRC_LEN = 20 ;
    private static final int MAX_MSG_LEN = 20; //20
    public static ArrayList<Long> rtt = new ArrayList<>();

    public  static  long usefulTime = 0 ;

    private static final int FRAME_SIZE = 85;

    private SenderDataLinkLayer() { throw  new UnsupportedOperationException("Util Class.");}

    public static void main(String[] args){
        String line ;
        try {
            line = new String(Files.readAllBytes(Paths.get(".\\Data\\sentData.txt")));
            long start = System.nanoTime();
            sendMessageStopWait(line);
            long end = System.nanoTime();
            long totalExecution = end - start;
            System.out.println("Time taken to send "+totalUsefullSent+" frames of  including wait and queue time is "+totalExecution+" NanoSeconds.");
            double elapsedTimeInSecond = (double) totalExecution/ 1_000_000_000;
            int  noOfBytes= FRAME_SIZE * totalUsefullSent;
            double bps = noOfBytes/elapsedTimeInSecond;
            System.out.println("Total no. of bytes sent are "+noOfBytes+" and total time taken in sending the bytes is "+elapsedTimeInSecond+"sec ("+totalExecution+"ns)");
            System.out.println("Hence speed of the system is "+bps+" Bytes/sec.");
            double generated = totalSent/elapsedTimeInSecond;
            double sent = totalUsefullSent/elapsedTimeInSecond;
            System.out.println("No of frames generated in unit time are  "+generated);
            System.out.println("Successfully sent among the total generated are "+sent);
            System.out.println("Efficiency of the system is "+((sent/generated)*100));
            double temp = (double)usefulTime/(double) totalExecution*100;
            System.out.println("Utilization of the channel is "+temp);

        } catch (IOException  e) {
            e.printStackTrace();
        }
    }
    private static void createAllFrames(ArrayList<String> frames, String message) {
        int j = 0 ;
        while(message.length() > MAX_MSG_LEN){
            String temp = message.substring(0,MAX_MSG_LEN);
            frames.add(createFrame(temp,NORMAL_FRAME_TYPE,j));
            j++;
            message = message.substring(MAX_MSG_LEN);
        }
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

        for(int i = 0 ; i < noOfFrames ; ++i){
            System.out.println("Sending frame "+(i+1));
            SenderPhysicalLayer.sendFrameStopWait(new Frame(frames.get(i),i),5555);
        }
        int count = 0 ;
        int size = rtt.size();
        for(long lo : rtt){
            count += lo;
        }
        var avg = count/size;
        System.out.println("Avg Rtt is :"+avg);
        System.out.println(totalUsefullSent);
        System.out.println(totalSent);
        double chk =(double) totalUsefullSent/(double)totalSent;
        System.out.println(chk);
        double perc = chk*100;
        System.out.println("Performance of the system is "+perc);
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
