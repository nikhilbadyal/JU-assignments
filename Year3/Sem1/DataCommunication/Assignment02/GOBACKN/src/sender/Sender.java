package sender;

import java.io.*;

public class Sender {

    public static int totalSent = 0 ;
    public  static  int totalUsefullSent = 0 ;
    private static int  FRAME_SIZE = 512;
    public  static  long usefulTime = 0 ;

    public static void main(String[] args) throws Exception {
        // check argument number
        if (args.length != 3 || args[0].equals("") || args[1].equals("") || args[2].equals("")) {
            System.out.println("Usage: java Sender <protocol selector> <timeout> <filename>");
            return;
        }

        // get input arguments
        int protocolType = Integer.parseInt(args[0]);
        int timeout = Integer.parseInt(args[1]);
        String fileName = args[2];

        // read channel info
        FileReader fileReader = new FileReader("channelInfo");
        BufferedReader bufferedReader = new BufferedReader(fileReader);
        String line = bufferedReader.readLine();
        if (line == null) {
            throw new Exception("empty channel info");
        }
        String[] tokens = line.split("\\s");
        String hostName = tokens[0];
        int port = Integer.parseInt(tokens[1]);
        bufferedReader.close();

        // check input file
        File f = new File(fileName);
        if (!f.exists() || !f.canRead()) {
        }

        // use appropriate protocol type to send file data
        if (protocolType == 0) {
            System.out.println("GBN protocol");

            GBNSender sender = new GBNSender(fileName, hostName, port, timeout);
            long start = System.nanoTime();
            sender.start();
            long end = System.nanoTime();
            long totalExecution = end - start;
            System.out.println("Time taken to send "+totalUsefullSent+" frames of  including wait and queue time is "+totalExecution+" NanoSeconds.");
            double elapsedTimeInSecond = (double) totalExecution/ 1_000_000_000;
            int  noOfBytes= FRAME_SIZE * totalUsefullSent;
            double bps = noOfBytes/elapsedTimeInSecond;
            System.out.println("Total no. of bytes sent are "+noOfBytes+" and total time taken in sending the bytes is "+elapsedTimeInSecond+"sec ("+totalExecution+"ns)");
            System.out.println("Hence speed of the system is "+bps+" Bytes/sec.");
            double generated = totalSent/elapsedTimeInSecond;
            double sent = totalUsefullSent/elapsedTimeInSecond;
            System.out.println("No of frames generated in unit time are  "+generated);
            System.out.println("Successfully sent among the total generated are "+sent);
            System.out.println("Efficiency of the system is "+((sent/generated)*100));
            double temp = (double)usefulTime/(double) totalExecution*100;
          //  System.out.println("Utilization of the channel is "+temp);
        } else if (protocolType == 1) {
            System.out.println("SR protocol");
            SRSender sender = new SRSender(fileName, hostName, port, timeout);
            long start = System.nanoTime();
            sender.start();
            long end = System.nanoTime();
            long totalExecution = end - start;
            System.out.println("Time taken to send "+totalUsefullSent+" frames of  including wait and queue time is "+totalExecution+" NanoSeconds.");
            double elapsedTimeInSecond = (double) totalExecution/ 1_000_000_000;
            int  noOfBytes= FRAME_SIZE * totalUsefullSent;
            double bps = noOfBytes/elapsedTimeInSecond;
            System.out.println("Total no. of bytes sent are "+noOfBytes+" and total time taken in sending the bytes is "+elapsedTimeInSecond+"sec ("+totalExecution+"ns)");
            System.out.println("Hence speed of the system is "+bps+" Bytes/sec.");
            double generated = totalSent/elapsedTimeInSecond;
            double sent = totalUsefullSent/elapsedTimeInSecond;
            System.out.println("No of frames generated in unit time are  "+generated);
            System.out.println("Successfully sent among the total generated are "+sent);
            System.out.println("Efficiency of the system is "+((sent/generated)*100));
            double temp = (double)usefulTime/(double) totalExecution*100;
            //System.out.println("Utilization of the channel is "+temp);
        } else {
            throw new Exception("invalid protocol type");
        }
    }
}
