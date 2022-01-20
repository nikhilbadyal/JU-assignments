import java.util.*;

interface Channel {
    int FREE = 0;  //Indicates Channel is free
    int OCCUPIED = 1; //Indicates Channel is being used
 }

class OnePersistence implements Channel {
    public static final List<Long> throughput= Collections.synchronizedList(new ArrayList<>());
    public static final Map<String, List<Long>> forwardDelay = Collections.synchronizedMap(new HashMap<>());

    public static void main(String[] args) {


        Scanner sc = new Scanner(System.in);
        Sender.ChannelStatus = FREE;                      //initially channel is free
        System.out.println("Enter number of stations");
        int NumberOfStations = sc.nextInt();
        Sender[] ArrayOfObjects = new Sender[NumberOfStations+1]; //Creating array of Senders equal to the input taken
        int[] FrameArray = new int[NumberOfStations+1];   // FrameArray will store the number of frames for each sender
        for(int i = 1;i<=NumberOfStations;i++)
        {
            System.out.println("Enter number of frames for Station " + i);
            FrameArray[i] = sc.nextInt();

        }

        for(int i = 1;i<=NumberOfStations;i++){
            ArrayOfObjects[i] = new Sender("Station "+ i, FrameArray[i]);
            System.out.println("hello");
        }


        try {
           // wait for stations to complete transmission
           for(int i=1;i<=NumberOfStations;i++)
                ArrayOfObjects[i].t.join();
        }
        catch (InterruptedException e) {
            System.out.println("Main Thread Interrupted");
        }
        System.out.println("Transmission completed.");
        //calculation throughput
        long SumThroughput = 0L;
        for(int i=0;i<throughput.size();i++){
            //System.out.println(i+1 + " " + throughput.get(i));
            SumThroughput = SumThroughput + throughput.get(i);
        }
        long avg;
        avg = SumThroughput/throughput.size();
        System.out.println("Throughput: " + ((85*8*1000)/avg) + " bits/sec");

        //System.out.println("transmission time: ");
        long sumTransmission = 0L;
        int count = 0;
        for(int i = 1; i<= forwardDelay.size(); i++){
            //System.out.println("Station "+i);
            //System.out.println("size of Station "+i+" "+ forwardDelay.get("Station "+i).size());
            for(int j=0;j<forwardDelay.get("Station "+i).size();j++){
                sumTransmission = sumTransmission+ forwardDelay.get("Station "+i).get(j);
                //System.out.println(forwardDelay.get("Station "+i).get(j));
                count++;
            }


        }

        System.out.println("Average forwarding Delay: " + sumTransmission/ count +"millisec");


    }
}
