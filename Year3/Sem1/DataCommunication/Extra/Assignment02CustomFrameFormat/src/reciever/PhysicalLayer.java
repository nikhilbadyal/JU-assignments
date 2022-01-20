package reciever;
//server

import Util.Pair;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;


public class PhysicalLayer {
    static Receiver dataLinkLayer = new Receiver();

    public static void main(String[] args) {
        receive();
    }
    public  static void receive(){

        System.out.println("Waiting for Client to send frame number.....");
        File file = new File(".\\Data\\receivedData.txt");
        try(ServerSocket ss1 = new ServerSocket(4444);
            ServerSocket ss2 = new ServerSocket(5555);
            FileWriter fileWriter = new FileWriter(file,true);
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter)){
            if (!file.exists() && !file.getParentFile().mkdirs() && !file.createNewFile()) {
                throw new IOException("Error making file.");
            }
            Socket s1 = ss1.accept();
            System.out.println("Connected with client.");
            DataInputStream dataInputStream = new DataInputStream(s1.getInputStream());
            int noOfFrames = dataInputStream.readInt();
            System.out.println("No. of frames are "+noOfFrames);
            bufferedWriter.write("Started frame writing at "+new Date());
            bufferedWriter.newLine();
            bufferedWriter.flush();

            for(int i =0 ; i < noOfFrames ; ++i){
                System.out.println("Waiting for Client for Frame "+(i+1));
                Socket s2 = ss2.accept();
                System.out.println("Connected with client.");
                DataInputStream dataInputStream1 = new DataInputStream(s2.getInputStream());
                String frame = dataInputStream1.readUTF();
                System.out.println("Frame received "+frame);
                Pair status =  dataLinkLayer.receive(frame,noOfFrames);
                DataOutputStream dataOutputStream = new DataOutputStream(s2.getOutputStream());
                dataOutputStream.writeUTF(status.getKey());
                System.out.println("Acknowledgment sent for frame "+(i+1)+" with "+status.getKey());
                if(status.getKey().equalsIgnoreCase("resend")){
                    i -= 1;
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
