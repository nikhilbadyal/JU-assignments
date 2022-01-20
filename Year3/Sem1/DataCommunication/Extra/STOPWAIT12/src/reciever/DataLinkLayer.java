package reciever;

import util.CRC;
import util.AckPackage;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class DataLinkLayer {
    private static final String SOURCE_MAC = "80-91-33-93-B7-7F"; //17
    private static final String DESTINATION_MAC = "80-91-33-93-B7-7F"; //17
    private static final String FIELD_DIVIDER = "-";
    private static final String NORMAL_FRAME_TYPE = "N";
    private static final  String RESEND = "resend";
    private static final int SEG_LEN = 2; //2
    private static final  int SEQ_LEN = 2;
    private static final int CRC_LEN = 20 ; //
    private  final ArrayList<String> frames ;

    public DataLinkLayer(int noOfFrames) {
        frames = new ArrayList<>(noOfFrames);
        for(int i = 0 ; i < noOfFrames ; ++i){
            frames.add("");
        }
    }
    private void writeData(File file, int frameNo , String msg) throws IOException {
        if (!file.exists() && !file.getParentFile().mkdirs() && !file.createNewFile()) {
            throw new IOException("Error making file.");
        }
        try(FileWriter fileWriter = new FileWriter(file,true);
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter)){
            frames.set(frameNo,msg);
            for(String frameStr : frames){
                bufferedWriter.write(frameStr);
            }
            bufferedWriter.newLine();
            bufferedWriter.flush();
        }
    }

    public AckPackage receiveStopWait(String frame) throws IOException {
        int prefixLen = DESTINATION_MAC.length() + FIELD_DIVIDER.length() + SOURCE_MAC.length() + FIELD_DIVIDER.length() + NORMAL_FRAME_TYPE.length() + FIELD_DIVIDER.length() + SEQ_LEN + FIELD_DIVIDER.length() +  SEG_LEN +FIELD_DIVIDER.length() ;
        int suffixLen = FIELD_DIVIDER.length()+ CRC_LEN ;
        int frameLen = frame.length();
        if(frameLen < (suffixLen + suffixLen)){
            System.out.println(1);
            return new AckPackage(RESEND);
        }

        String perfix = frame.substring(0,prefixLen);
        String sufix = frame.substring(frameLen-suffixLen);
        int frameNo = extractFrameNo(perfix);
        System.out.println("Frame No is "+frameNo);
        if(frameNo == -1){
            return new AckPackage(RESEND);
        }
        String frameType = getFrameType(perfix);
        String msg = getMsg(frame,prefixLen, suffixLen);
        String checksum = extractCrc(sufix);
        boolean msgCrcSum = checkChecksum(perfix+msg,checksum);
        if(!msgCrcSum){
            return new AckPackage(RESEND);
        }else if(frameType.equals("E")){
            File file = new File(".\\Data\\STOPWAITReceivedData.txt");
            writeData(file,frameNo,msg);
            return new AckPackage("end");
        }else{
          //  System.out.println("Adding frame at Pos "+frameNo);
            frames.set(frameNo,msg);
        }
        return new AckPackage("next");
    }

    private int extractFrameNo(String perfix) {
        int frameNo = -1;
        try{
            frameNo = Integer.parseInt(perfix.substring(2*(DESTINATION_MAC.length()+FIELD_DIVIDER.length())+NORMAL_FRAME_TYPE.length() + FIELD_DIVIDER.length(),2*(DESTINATION_MAC.length()+FIELD_DIVIDER.length())+NORMAL_FRAME_TYPE.length() + FIELD_DIVIDER.length()+SEG_LEN));
        }catch (NumberFormatException numberFormatException){
            //Do nothing.
        }
        return frameNo;
    }

    private boolean checkChecksum(String msg, String checksum) {
        return CRC.getCrc(msg).equals(checksum);
    }

    private String extractCrc(String sufix) {
        return sufix.substring(FIELD_DIVIDER.length());
    }
    private String getMsg(String frame, int preLen, int sufLen) {
        return frame.substring(preLen,frame.length()-sufLen);
    }

    private String getFrameType(String perfix) {
        return perfix.substring(2 * (DESTINATION_MAC.length() + FIELD_DIVIDER.length()) ,2 * (DESTINATION_MAC.length() + FIELD_DIVIDER.length() )+ NORMAL_FRAME_TYPE.length());
    }

}
