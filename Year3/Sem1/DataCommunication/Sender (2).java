import java.util.ArrayList;
import java.util.Random;
import java.util.concurrent.atomic.*;

class Sender implements Runnable, Channel {
    String StationNumber;
    Thread t;
    static int messageTransmitting, stat=0,frame;
    static int ChannelStatus; //Indicates if channel is being used
    int FrameNumber,MaxFrameNumber;
    private final AtomicBoolean CheckIfSuccessfulTransmission; // atomic means no two threads access this simultaneously
    static int tfr=50; //Transmission time
    private int NumberOfAttempts;  //if this exceed than 15 loop will break
    private long startThroughput;

    Sender(String threadName, int MaxFrameNumber) {
        StationNumber = threadName;
        t = new Thread(this, StationNumber);
        FrameNumber = 1;
        this.MaxFrameNumber=MaxFrameNumber;
        CheckIfSuccessfulTransmission = new AtomicBoolean();

        startThroughput = System.currentTimeMillis();
        t.start();

    }


    public void run() {
        Random rand = new Random();
        while (!CheckIfSuccessfulTransmission.get()) {
            NumberOfAttempts++;
            long startDelay = System.currentTimeMillis();  // time start frame ready to be sent
            while(FrameNumber <= MaxFrameNumber) {
                if (NumberOfAttempts < 15) { //15 is the maximum number of attempts
                    try {
                        if (ChannelStatus == OCCUPIED) {


                            System.out.println(StationNumber + " is using non-Persistent sensing, channel is busy");
                            try {
                                Thread.sleep(rand.nextInt(50)+1000); // In Non-persistent sensing, Sender will wait for random amount of time
                            }
                            catch (InterruptedException e) {
                                System.out.println(("Interrupt"));
                            }
                        }
                        else {
                            System.out.println(StationNumber + " is trying to transmit frame number : " + FrameNumber);

                            System.out.println();
                            System.out.println("Thread name : " + Thread.currentThread().getName() + " distance : "+ messageTransmitting + " channel status" + ChannelStatus);
                            System.out.println();
                            if (ChannelStatus == FREE && messageTransmitting == 0) {//Successful transmission
                                stat = CheckThreads.checking(Thread.currentThread().getName());
                                frame = this.FrameNumber;
                                ChannelStatus = OCCUPIED;//set channel to in use
                                for (; messageTransmitting < 9000000; messageTransmitting++)
                                    for(int i =0;i<1000;i++); //simulate transmission over some distance


                                System.out.println(StationNumber + " frame " + FrameNumber + " is successful");
                                CheckIfSuccessfulTransmission.set(true);
                                FrameNumber++;
                                messageTransmitting = 0; //reset distance for next frame's transmission
                                ChannelStatus = FREE;    // setting channel back to free


                                long end = System.currentTimeMillis();
                                long time = end - startThroughput;
                                startThroughput = end;
                                synchronized(NonPersistence.throughput){
                                    NonPersistence.throughput.add(time);


                                    if(!NonPersistence.forwardDelay.containsKey(StationNumber)){
                                        NonPersistence.forwardDelay.put(StationNumber, new ArrayList<>());
                                    }
                                    NonPersistence.forwardDelay.get(StationNumber).add(System.currentTimeMillis()-startDelay);
                                    startDelay = System.currentTimeMillis();
                                }



                            }
                            else {//Collision has occurred
                                System.out.println();
                                System.out.println("Thread name : " + Thread.currentThread().getName() + " distance : "+ messageTransmitting + " channel status " + ChannelStatus);
                                System.out.println();
                                System.out.println("Collision for frame " + FrameNumber + " of " +
                                        StationNumber + " and frame " + frame + " of Station " + stat);

                                System.out.println("Retransmitting Station " + stat + "'s frame " + frame);
                                CheckIfSuccessfulTransmission.set(false);
                                ChannelStatus = FREE;

                                NumberOfAttempts++;
                                try {
                                    int R = rand.nextInt((int) (Math.pow(2, NumberOfAttempts - 1)));
                                    int BackOffTime = R * tfr;
                                    Thread.sleep(BackOffTime);

                                } catch (InterruptedException e) {
                                    System.out.println("Interrupted");
                                }
                            }
                            Thread.sleep(1000);
                        }
                    }catch (InterruptedException e) {
                        System.out.println(StationNumber + "Main Interrupted");
                    }
                }
                else {
                    CheckIfSuccessfulTransmission.set(true);
                    System.out.println("Too many attempts for frame " + FrameNumber+ "of " +
                            StationNumber + ". Transmission stopped");
                }

            }
        }
    }
}
