package nonpersistent;

import utilclasses.ChannelConstants;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Date;
import java.util.Scanner;

class NonPersistent implements ChannelConstants {
    private  static int totalChannelAttempt = 0 ;
    private  static int totalDoneAttempt = 0 ;
    public static long forwarding_delay = 0 ;
    private static long FRAME_SIZE = 520 ;


    public static synchronized void  updateTotalCount(){
        totalChannelAttempt++;
    }
    public static  synchronized  void updateDoneCount(){
        totalDoneAttempt++;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        NPChannel.channelStatus = FREE; //initially channel is free
        System.out.println("Enter number of stations");
        int numberOfStations = sc.nextInt();
        NPChannel[] npChannels = new NPChannel[numberOfStations+1];
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
        long start = System.nanoTime();
        for(int i = 1;i<=numberOfStations;i++)
            npChannels[i] = new NPChannel("Station "+i,noOfFramesInChannel[i],fileWriter);

        try{
           for(int i=1;i<=numberOfStations;i++)
                npChannels[i].t.join();
        } catch (InterruptedException e) {
            System.out.println("Main Thread Interrupted");
            Thread.currentThread().interrupt();
            System.exit(1);
        }
        long end = System.nanoTime();
        long totalExecution = end - start;
        int count = 0 ;
        for(int i = 0 ;  i < numberOfStations; ++i){
            count += noOfFramesInChannel[i];
        }
        System.out.println("Time taken to send "+count+" frames of "+numberOfStations+" channel including wait and queue time is "+totalExecution+" NanoSeconds.");
        double elapsedTimeInSecond = (double) forwarding_delay/ 1_000_000_000;
        long noOfBytes= FRAME_SIZE * count;
        double bps = noOfBytes/elapsedTimeInSecond;
        System.out.println("Total no. of bytes sent are "+noOfBytes+" and total time taken in sending the bytes is "+elapsedTimeInSecond+"sec ("+forwarding_delay+"ns)");
        System.out.println("Hence speed of the system is "+bps+" Bytes/sec.");
        double generated = totalChannelAttempt/elapsedTimeInSecond;
        double sent = totalDoneAttempt/elapsedTimeInSecond;
        System.out.println("No of frames generated in unit time are  "+generated);
        System.out.println("Successfully sent among the total generated are "+sent);
        System.out.println("Efficiency of the system is "+((sent/generated)*100));
        try {
            fileWriter.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("Transmission completed.");
    }
}
