package ppersistent;

import utilclasses.ChannelConstants;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.concurrent.atomic.*;

class PChannel implements Runnable, ChannelConstants {
    String stationNumber;
    Thread t;
    static int distance;
    static int stat=0;
    static int frame;
    static int channelStatus; //Indicates if channel is being used
    int currentFrameNumber;
    int maxFrameNumber;
    private final AtomicBoolean checkIfSuccessfulTransmission;
    static int tfr=50; //Transmission time
    private int numberOfAttempts;
    Random rand ;
    private static final  Object distanceLock = new Object();
    private static final Object channelUpdateLock = new Object();
    private static final Object getStatLock = new Object();
    FileWriter fileWriter ;
    private static final double prob = 0.1;

    PChannel(String threadName, int maxFrameNumber, FileWriter fileWriter) {
        stationNumber = threadName;
        t = new Thread(this, stationNumber);
        currentFrameNumber = 1;
        this.maxFrameNumber =maxFrameNumber;
        checkIfSuccessfulTransmission = new AtomicBoolean();
        this.fileWriter = fileWriter;
        t.start();
    }
    public void run() {
        rand = new Random();
        while (!checkIfSuccessfulTransmission.get()) {
            numberOfAttempts++;
            while(currentFrameNumber <= maxFrameNumber) {
                PPersistent.updateTotalCount();
                if (numberOfAttempts < 15) { //15 is the maximum number of attempts
                    try {
                        if (channelStatus == INUSE) {
                            System.out.println(stationNumber + " is using 1 Persistent sensing, channel is busy");
                            synchronized (this){
                                try {
                                    wait(); //***Waits forever.***
                                }
                                catch (InterruptedException e) {
                                    System.out.println(("Interrupt"));
                                    Thread.currentThread().interrupt();
                                    System.exit(1);
                                }
                            }

                        }
                        else {
                            System.out.println(stationNumber + " is trying to transmit frame number : " + currentFrameNumber);

                            if (channelStatus == FREE && distance == 0) {//Successful transmission
                                if(rand.nextDouble() < prob){
                                    continue;
                                }
                                synchronized (getStatLock){
                                    stat = PChannelThreads.checking(Thread.currentThread().getName());
                                    if(stat == -1){
                                        System.out.println("Error Setting up stat.");
                                        System.exit(1);
                                    }
                                    frame = this.currentFrameNumber;
                                }
                                synchronized (channelUpdateLock){
                                    channelStatus = INUSE;
                                }
                                long start = System.nanoTime();
                                synchronized (distanceLock){
                                  /*  for (; distance < 9000000; distance++)
                                        for(int i =0;i<1000;i++){
                                            //simulate transmission over some distance
                                    }*/
                                    distanceLock.wait(1000);
                                    //Thread.sleep(1000);
                                }
                                long end = System.nanoTime();
                                synchronized (this){
                                    PPersistent.forwarding_delay += end-start;
                                }
                                PPersistent.updateDoneCount();
                                fileWriter.write(stationNumber + " frame " + currentFrameNumber + " is successful.\n");
                                fileWriter.flush();
                                System.out.println(stationNumber + " frame " + currentFrameNumber + " is successful.");
                                checkIfSuccessfulTransmission.set(true);
                                currentFrameNumber++;
                                synchronized (distanceLock){
                                    distance = 0;
                                }
                                synchronized (channelUpdateLock){
                                    channelStatus = FREE;
                                }
                                synchronized (this){
                                    try{
                                        notifyAll(); /// ***Notify All doesnt works.***
                                    } catch (Exception e) {
                                        e.printStackTrace();
                                    }
                                }
                            }
                            else {//Collision has occurred
                                System.out.println("Collision for frame " + currentFrameNumber + " of " +
                                        stationNumber + " and frame " + frame + " of Station " + stat);

                                System.out.println("Retransmitting Station " + stat + "'s frame " + frame);
                                checkIfSuccessfulTransmission.set(false);
                                synchronized (channelUpdateLock){
                                    channelStatus = FREE;
                                }

                                numberOfAttempts++;
                                /*
                                try {
                                    int anInt = rand.nextInt((int) (Math.pow(2,(double) numberOfAttempts - 1)));
                                    int backOffTime = anInt * tfr;
                                    Thread.sleep(backOffTime);

                                } catch (InterruptedException e) {
                                    System.out.println("Interrupted");
                                    Thread.currentThread().interrupt();
                                }*/
                            }
                        //    Thread.sleep(1000);


                        }
                    } catch (InterruptedException | IOException e) {
                        System.out.println(stationNumber + "Main Interrupted");
                        Thread.currentThread().interrupt();
                    }
                }
                else {
                    checkIfSuccessfulTransmission.set(true);
                    System.out.println("Too many attempts for frame " + currentFrameNumber + "of " +
                            stationNumber + ". Transmission stopped");
                }

            }
        }
    }
}