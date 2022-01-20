package Reciever;

import Sender.SenderDataLinkLayer;
import Support.CRC;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class RecieverDataLinkLayer {
    String data;


    public String getPayLoad(String frame){
        String payload;
        String[] dataFragments = frame.split("-");

        payload = dataFragments[4];
        return payload;
    }

    public String getFrameType(String frame){
        String type;
        String[] dataFragments = frame.split("-");
        type = dataFragments[3];
        return type;
    }

    public boolean checkValidity(String Frame) throws IOException {
        String[] dataFragments = Frame.split("-");
        if(dataFragments.length != 6){
            return false;
        }
        String toBeCrc = dataFragments[5];

        System.out.println("tobecrc : " + toBeCrc);

        String frameWithoutCrc = Frame.substring(0, Frame.length() - SenderDataLinkLayer.CRC_LEN);

        String producedCrc = CRC.getCrc(frameWithoutCrc);
        System.out.println("produced crc : " + producedCrc);
        if(producedCrc.equals(toBeCrc)){
            System.out.println("returning true");
            writeData(Frame);
            return true;
        }
        System.out.println("returning false");
        return false;
    }
    public void writeData(String Frame) throws IOException {
        File recievedDataFile = new File("E:\\BCSE 3RD YEAR\\SARBANI MAM\\LAB\\Assignment2\\Assignment2_code\\src\\Data\\reciever"+Thread.currentThread().getName()+".txt");
        if(!recievedDataFile.exists() && !recievedDataFile.getParentFile().mkdirs() && !recievedDataFile.createNewFile()){
            throw new IOException("IOException");
        }
        try{
            FileWriter fileWriter = new FileWriter(recievedDataFile, true);
            String s = getPayLoad(Frame);
            fileWriter.write(s);
            data = data + s;
            fileWriter.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public String getData() {
        return data;
    }
}
