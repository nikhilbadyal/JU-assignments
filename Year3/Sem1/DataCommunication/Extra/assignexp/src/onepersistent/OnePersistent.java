package onepersistent;

import utilclasses.ChannelConstants;

import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Date;
import java.util.Scanner;
/*

interface ChannelConstants{ int FREE = 0;  //Indicates Channel is free
    int INUSE = 1; //Indicates Channel is being used
 }
*/

class OnePersistent implements ChannelConstants {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        OneChannel.channelStatus = FREE; //initially channel is free
        System.out.println("Enter number of stations");
        int numberOfStations = sc.nextInt();
        OneChannel[] channels= new OneChannel[numberOfStations+1];
        int[]  noOfFramesInChannel = new int[numberOfStations+1];

        for(int i = 1;i<=numberOfStations;i++)
        {
            System.out.println("Enter number of frames for Station " + i);
            noOfFramesInChannel[i] = sc.nextInt();
        }
        FileWriter fileWriter = null;
        try {
            fileWriter = new FileWriter("logs.txt",true);
            fileWriter.write("Started Frame writing at "+new Date()+"\n");
            fileWriter.flush();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
        try {
            for(int i = 1;i<=numberOfStations;i++)
                channels[i] = new OneChannel("Station "+i,noOfFramesInChannel[i], fileWriter,i);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            System.exit(1);
        }

        try {
// wait for stations to complete transmission
           for(int i=1;i<=numberOfStations;i++)
                channels[i].t.join();
        }
        catch (InterruptedException e) {
            System.out.println("Main Thread Interrupted");
            Thread.currentThread().interrupt();
        }
        try {
            fileWriter.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("Transmission completed.");
    }
}
