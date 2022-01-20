package reciever;

import Util.CheckSum;
import Util.Pair;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Receiver{
    private static final String START_OF_FRAME = "<";
    private static final String END_OF_FRAME = ">";
    private static final String NORMAL_FRAME_TYPE = "N";
    private static final String END_FRAME_TYPE = "E";
    private static final String FIELD_DIVIDER = "-";
    private static  final int MAX_TRANSMISSION_UNIT = 24;
    private static final int CHECK_SUMLEN = 4 ;
    private static final int SEG_LEN = 2;
    private static final int SEQUENCE_NUMBER_LEN = 2;
    private static final  String RESEND = "resend";

    public Pair receive(String frame, int noOfFrames) throws IOException {

        int prefixLen = START_OF_FRAME.length() + SEQUENCE_NUMBER_LEN + FIELD_DIVIDER.length() + NORMAL_FRAME_TYPE.length() + FIELD_DIVIDER.length() + SEG_LEN + FIELD_DIVIDER.length();
        int suffixLen = FIELD_DIVIDER.length()+ CHECK_SUMLEN + END_OF_FRAME.length();
        int maxMessageLength = MAX_TRANSMISSION_UNIT - suffixLen - prefixLen ;

        int frameLen = frame.length();
        if(frameLen < (suffixLen + suffixLen)){
            return new Pair(true, RESEND);
        }
        if(frameLen > maxMessageLength + suffixLen + prefixLen){
            return new Pair(true, RESEND);
        }

        String perfix = frame.substring(0,prefixLen);
        String sufix = frame.substring(frameLen-suffixLen);
        if(!isvalidFrame(frame,sufix,suffixLen,perfix,prefixLen)){
            return new Pair(true, RESEND);
        }
        int sequenceNo = getSequenceNumber(perfix);
        String frameType = getFrameType(perfix);
        String messageLen = getMsgLen(perfix,prefixLen);
        String msg = getMsg(frame,prefixLen, suffixLen);
        String checksum = extractChecksum(sufix,suffixLen);
        boolean sequenceCheck = checkSeq(sequenceNo,noOfFrames);
        boolean msgLenCheck = checkMsgLen(messageLen,msg);
        boolean msgCheckSum = checkChecksum(msg,checksum);
        if(!msgCheckSum || !msgLenCheck || !sequenceCheck){
            return new Pair(true, RESEND);
        }else{
            File file = new File(".\\Data\\receivedData.txt");
            if(!file.exists()){
                if(file.getParentFile().mkdirs()){
                    if(!file.createNewFile()){
                        throw new IOException("Unable to create file.");
                    }
                }

            }
            try(FileWriter fileWriter = new FileWriter(file,true);
                BufferedWriter bufferedWriter = new BufferedWriter(fileWriter)){
                bufferedWriter.write(msg);
                bufferedWriter.flush();
                if(frameType.equals("E")){
                    bufferedWriter.newLine();
                    bufferedWriter.flush();
                    return new Pair(false,"end");
                }
            }catch (Exception e) {
                e.printStackTrace();
            }
        }
        return new Pair(true, "next");
    }

    private boolean checkSeq(int sequenceNo, int noOfFrames) {
        if(sequenceNo == -1 ){
            return  false;
        }
        return sequenceNo <= noOfFrames;
    }

    private int getSequenceNumber(String perfix) {
        int seqNo = -1 ;
        try{
            String seqStr = perfix.substring(START_OF_FRAME.length(),SEG_LEN+FIELD_DIVIDER.length());
            seqNo = Integer.parseInt(seqStr);
        } catch (Exception e) {
            //do nothing
        }
        return seqNo;
    }

    private String extractChecksum(String sufix , int suffixLen) {
        return sufix.substring(suffixLen - CHECK_SUMLEN - FIELD_DIVIDER.length(), suffixLen - FIELD_DIVIDER.length());
    }

    private boolean checkChecksum(String msg , String checksum) {
        String  generatedChecksum = CheckSum.getChecksum(msg);
        return  generatedChecksum.equals(checksum);
    }

    private boolean checkMsgLen(String msglen, String msg) {
        int msglength ;
        try{
            msglength = Integer.parseInt(msglen);
        }catch (Exception e){
            //throw new ImplementationError("Segment Length not a 2 digit decimal Number.");
            return  false;
        }
        return msglength == msg.length();
    }

    private String getMsg(String frame, int preLen, int sufLen) {
        return frame.substring(preLen,frame.length()-sufLen);
    }

    private String getMsgLen(String perfix,int perfixLen) {
        return perfix.substring(perfixLen - SEG_LEN - FIELD_DIVIDER.length(),perfixLen - FIELD_DIVIDER.length());
    }

    private String getFrameType(String perfix) {
        return perfix.substring(START_OF_FRAME.length()+ SEQUENCE_NUMBER_LEN + FIELD_DIVIDER.length() , START_OF_FRAME.length()+SEQUENCE_NUMBER_LEN + FIELD_DIVIDER.length() + NORMAL_FRAME_TYPE.length());
    }

    private boolean isvalidFrame(String frame, String sufix ,int sufLen , String perfix , int  perLen) {
        boolean ans = true;
        if((containMoreThanOnce(frame, START_OF_FRAME) || containMoreThanOnce(frame, END_OF_FRAME) )|| !correctPerfixFormat(perfix,perLen) || !correctSufixFormat(sufix,sufLen)){
            ans = false;
        }
        return ans;
    }

    private  boolean correctSufixFormat(String suffix,int sufLen){
        String divider = suffix.substring(0, FIELD_DIVIDER.length());
        String frameEnd = suffix.substring(suffix.length()  - END_OF_FRAME.length());
        boolean ans = true;
        if(suffix.length() != sufLen || (!divider.equals(FIELD_DIVIDER) || ! frameEnd.equals(END_OF_FRAME))){
            ans = false;
        }
        return ans ;
    }
    private boolean correctPerfixFormat(String perfix, int perLen) {
        String frameType = getFrameType(perfix);
        String firstDivider = perfix.substring(perfix.length()- NORMAL_FRAME_TYPE.length() -SEG_LEN -(3* FIELD_DIVIDER.length()),perfix.length()- NORMAL_FRAME_TYPE.length() -  SEG_LEN -(2 * FIELD_DIVIDER.length()));
        String secondDivider = perfix.substring(perfix.length()- SEG_LEN - (2 * FIELD_DIVIDER.length()),perfix.length()-SEG_LEN - FIELD_DIVIDER.length() );
        String thirdDivider = perfix.substring(perfix.length()-FIELD_DIVIDER.length());
        boolean ans = true;
        if(perLen!= perfix.length()|| (!frameType.equals(NORMAL_FRAME_TYPE) && ! frameType.equals(END_FRAME_TYPE)) || (!firstDivider.equals(FIELD_DIVIDER) || ! secondDivider.equals(FIELD_DIVIDER) || !thirdDivider.equals(FIELD_DIVIDER))){
            ans = false;
        }

        //System.out.println(ans);
        return  ans;
    }

    private boolean containMoreThanOnce(String frame, String frameDelim) {
        int count = 0 ;
        boolean ans = false;
        for(Character c : frame.toCharArray()){
            boolean b =  frameDelim.equals(Character.toString(c));
            if(b){
                count++;
            }
            if(count > 1 ){
                ans = true;
                break;
            }
        }
        if(count == 0){
            ans = true;
        }
        return ans;
    }

}
