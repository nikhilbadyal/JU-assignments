import java.io.*;

import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

import static java.lang.System.exit;


public  class Sender {

    private static final int FRAME_SIZE = 6;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of stations");
        int numberOfStations = sc.nextInt();

        ArrayList<String> fileContent = new ArrayList<>(numberOfStations);

        int maxDataLength = Integer.MIN_VALUE;

        //reading all data from all files and creating a 2D array wrt to their number
        for(int i=1;i<=numberOfStations;i++){
            try {
                File file = new File("Sender" + i +".txt");
                Scanner myReader = new Scanner(file);
                StringBuilder s = new StringBuilder();
                while (myReader.hasNextLine()) {
                    s.append(myReader.nextLine());

                }
                if(s.length()>maxDataLength){
                    maxDataLength = s.length();
                }
                fileContent.add(s.toString());
                System.out.println(fileContent.get(i-1));


                myReader.close();
            } catch (FileNotFoundException e) {
                System.out.println("An error occurred.");
                e.printStackTrace();
                exit(1);
            }
        }

        System.out.println("Content is :");
        for(String x : fileContent){
            System.out.println(x);
        }
        System.out.println("End");

        int[] dataInEachStation = new int[numberOfStations];
        long start = System.nanoTime();
        int port = 5000;
        int totalUsefullSent = 0 ;
        try{
            Socket s  = new Socket("localhost", port);
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(s.getOutputStream());
            ObjectInputStream objectInputStream = new ObjectInputStream(s.getInputStream());
            
            for(int i=0;i<maxDataLength;i++){
                //preparing data frame i.e. extracting data from all sender and creating a final data
                totalUsefullSent++;
                for(int j=0;j<numberOfStations;j++){
                    if(i >= fileContent.get(j).length()){
                        dataInEachStation[j] = 0;
                    }else{
                        if(Integer.parseInt(String.valueOf(fileContent.get(j).charAt(i))) == 1){
                            dataInEachStation[j] = Integer.parseInt(String.valueOf(fileContent.get(j).charAt(i)));
                        }else{
                            dataInEachStation[j] = -1;
                        }
                    }
                    System.out.print(dataInEachStation[j]);
                }


                CDMA cdma = new CDMA();

                String data = cdma.setUp(dataInEachStation,numberOfStations); // this will return the data which is to be transferred
//                System.out.println("String data is "+data);

//                System.out.println("Frame before error insertion : " + i);


                if(i == maxDataLength-1){
                    data = "e" + data;  //e for last frame
                }else{
                    data = "n" + data;  //n for normal frame
                }
                Channel.send(data, objectOutputStream); //sending data

                while(Channel.getAck(objectInputStream, s)){
                    Channel.send(data, objectOutputStream); //receiving acknowledgement
                }

                Thread.sleep(1000);
                System.out.println();
            }

        }catch(Exception e){
            System.out.println("exception");
            e.printStackTrace();
        }
        long end = System.nanoTime();
        long totalExecution = end - start;
        System.out.println("Time taken to send  is "+totalExecution+" NanoSeconds.");
        double elapsedTimeInSecond = (double) totalExecution/ 1_000_000_000;
        int  noOfBytes= FRAME_SIZE * totalUsefullSent;
        double bps = noOfBytes/elapsedTimeInSecond;
        System.out.println("Total no. of bytes sent are "+noOfBytes+" and total time taken in sending the bytes is "+elapsedTimeInSecond+"sec ("+totalExecution+"ns)");
        System.out.println("Hence speed of the system is "+bps+" Bytes/sec.");
    }
}