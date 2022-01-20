package com.nikhil;


/**
 * @author Nikhil
 * @date 23 Feb2020
 */

public class MainThread {
    public static void main(String[] args) {
        Data data = new Data(10);
        IncreasingThread increasingThread = new IncreasingThread(data);
        DecreasingThread decreasingThread = new DecreasingThread(data);

        increasingThread.startThread();
        decreasingThread.startThread();

        //System.out.println(data.getData());

    }
}
   
