package onepersistent;

import utilclasses.ChannelConstants;

import java.io.*;
import java.util.ArrayList;
import java.util.Random;
import java.util.concurrent.atomic.*;

class OneChannel implements Runnable, ChannelConstants {
    String stationNumber;
    Thread t;
    static int distance;
    static int stat=0;
    static int frame;
    static int channelStatus;
    int currentFrameNo;
    int noOfFrames;
    private final AtomicBoolean checkIfSuccessfulTransmission;
    static int tfr=50; //Transmission time
    private int numberOfAttempts;
    Random rand ;
    private static final  Object distanceLock = new Object();
    private static final Object channelUpdateLock = new Object();
    private static final Object getStatLock = new Object();
    private final double prob = 0.33;
    private String fileName ;
    FileReader fileReader ;
    FileWriter fileWriter ;
    private int MAX_ALLOWED_ATTEMPTS = 15 ;

    OneChannel(String threadName, int noOfFrames, FileWriter fileWriter,int fileCount) throws FileNotFoundException {
        stationNumber = threadName;
        t = new Thread(this, stationNumber);
        currentFrameNo = 0;
        this.numberOfAttempts = 0 ;
        checkIfSuccessfulTransmission = new AtomicBoolean();
        this.fileWriter = fileWriter;
        this.noOfFrames = noOfFrames;
        this.fileName = "Station "+fileCount+".txt";
        System.out.println("File Name in One channel is "+fileName);
        this.fileReader = new FileReader(fileName);
        t.start();

    }
    public void run() {
        rand = new Random();
      //  System.out.println("No. of frames in "+stationNumber+" is "+maxFrameNumber);
        while (!checkIfSuccessfulTransmission.get()) {
            numberOfAttempts++;
            while(currentFrameNo < noOfFrames) {
                if (numberOfAttempts <= MAX_ALLOWED_ATTEMPTS) {
                        if (channelStatus == INUSE) {
                            System.out.println(stationNumber + " is using  OnePersistent sensing, channel is busy");
                            synchronized (this){
                                try {
                                    wait();
                                }
                                catch (InterruptedException e) {
                                    System.out.println(("Interrupt"));
                                    Thread.currentThread().interrupt();
                                    System.exit(1);
                                }
                            }

                        }
                        else {
                            System.out.println(stationNumber + " is trying to transmit frame number : " + currentFrameNo);
                            if (channelStatus == FREE && distance == 0) {
                                if(rand.nextDouble() > prob){
                                    System.out.println("Not sending frame in spite of free channel to avoid collisions.");
                                    continue;
                                }
                                distance++;
                                synchronized (channelUpdateLock){
                                    channelStatus = INUSE;
                                }
                                synchronized (getStatLock){
                                    stat = OneChannelThreads.checking(Thread.currentThread().getName());
                                    if(stat == -1){
                                        System.out.println("Error Setting up stat.");
                                        System.exit(1);
                                    }
                                    frame = this.currentFrameNo;
                                }
                                synchronized (distanceLock){
                                    //SenderPhysicalLayer.sendFrameStopWait(new Frame(frames.get(frameNumber),frameNumber),5555);
                                    //SenderPhysicalLayer.sendFrameStopWait(new Frame(frames.get(currentFrameNo), currentFrameNo),5555);
                                    try {
                                        distanceLock.wait(1000);
                                    } catch (InterruptedException e) {
                                        e.printStackTrace();
                                        Thread.currentThread().interrupt();
                                        System.exit(1);
                                    }
                                }
                                try {
                                    fileWriter.write(stationNumber + " frame " + currentFrameNo + " is successful.\n");
                                    fileWriter.flush();
                                } catch (IOException e) {
                                    e.printStackTrace();
                                    System.exit(1);
                                }
                                System.out.println(stationNumber + " frame " + currentFrameNo + " is successful.");
                                checkIfSuccessfulTransmission.set(true);
                                currentFrameNo++;
                                synchronized (distanceLock){
                                    distance = 0;
                                }
                                synchronized (this){
                                    try{
                                        notifyAll();
                                    } catch (Exception e) {
                                        e.printStackTrace();
                                    }
                                }
                                synchronized (channelUpdateLock){
                                    channelStatus = FREE;
                                }

                            }
                            else {
                                System.out.println("Collision for frame " + currentFrameNo + " of " +
                                        stationNumber + " and frame " + frame + " of Station " + stat);

                                System.out.println("Retransmitting Station " + stat + "'s frame " + frame);
                                checkIfSuccessfulTransmission.set(false);
                                synchronized (channelUpdateLock){
                                    channelStatus = FREE;
                                }

                                numberOfAttempts++;
                               /* try {
                                    int anInt = rand.nextInt((int) (Math.pow(2,(double) numberOfAttempts - 1)));
                                    int backOffTime = anInt * tfr;
                                    Thread.sleep(backOffTime);

                                } catch (InterruptedException e) {
                                    System.out.println("Interrupted");
                                    Thread.currentThread().interrupt();
                                }*/
                            }

                        }

                }
                else {
                    checkIfSuccessfulTransmission.set(true);
                    System.out.println("Too many attempts for frame " + currentFrameNo + "of " +
                            stationNumber + ". Transmission stopped");
                }

            }
        }
    }
}
