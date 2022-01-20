package Sender;

import Support.CRC;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
public class SenderDataLinkLayer implements Runnable{
    private String data;
    private final int PAYLOAD_LENGTH = 8;
    public final String NORMAL_FRAME_TYPE = "N";
    public final String END_FRAME_TYPE = "E";
    public static final int CRC_LEN = 20 ;


    public void run(){
        stopWait();
    }
    public String extractData(String fileName){
        String s = "";
        try{
            File dataFile = new File(fileName);
            Scanner myReader = new Scanner(dataFile);
            while(myReader.hasNextLine()){
                s = s + myReader.nextLine();
            }
        }catch(FileNotFoundException e){
            System.out.println("File not found" + e);
        }
        return s;
    }

    public String makeF(String payload, String type){
        String frame;
        String destination = "dest";
        String Divider = "-";
        String Source = "src";
        //System.out.println(payload);
        int length = payload.length();
        if(payload.length() < PAYLOAD_LENGTH){
            int l = PAYLOAD_LENGTH - payload.length();
            for(int i=0;i<l;i++){
                payload = 'x' + payload;
            }
        }

        frame = destination + Divider + Source + Divider + length + Divider +type + Divider + payload + Divider ;
        frame = frame + CRC.getCrc(frame);
        return frame;
    }
    public ArrayList<String> makeFrames(String data){
        ArrayList<String>dataFragments = new ArrayList<>();

        for(int i=0; i<data.length();i++){
            String s = "";
            for(int j=0;j<PAYLOAD_LENGTH && i<data.length();j++){
                s = s + data.charAt(i);
                i++;
            }
            dataFragments.add(s);
            i--;
        }
        System.out.println();
        System.out.println();
        ArrayList<String>  frames = new ArrayList<>();
        for(int i=0;i<dataFragments.size()-1;i++){
            String frame = makeF(dataFragments.get(i), NORMAL_FRAME_TYPE);
            frames.add(frame);
        }

        String frame =  makeF(dataFragments.get(dataFragments.size()-1), END_FRAME_TYPE);
        frames.add(frame);
        return frames;
    }

    public void stopWait(){
        String fileName = "E:\\BCSE 3RD YEAR\\SARBANI MAM\\LAB\\Assignment2\\Assignment2_code\\src\\Data\\sender"+Thread.currentThread().getName()+".txt";
        data = extractData(fileName);
        System.out.println(data);
        ArrayList<String>frames = makeFrames(data);


        SenderPhysicalLayer senderPhysicalLayer= new SenderPhysicalLayer();
        senderPhysicalLayer.sendFramesStopWait(frames);
        System.out.println("called");

    }

    public static void main(String[] args){
        int noOfSenders = 3;
        for(int i=1;i<=noOfSenders;i++){
            Thread thread = new Thread(new SenderDataLinkLayer(), Integer.toString(i));
            thread.start();
        }
    }
}
