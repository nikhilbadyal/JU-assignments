package com.nikhil;

import java.security.SecureRandom;
import java.util.Random;

/**
 * @author Nikhil
 * @date 22 Feb2020
 */

public class Reader implements  Runnable {
    private Data data;
    private Thread readerThread;
    private Random random = new SecureRandom();


    public Reader(Data data) {
        this.data = data;
        readerThread = new Thread(this, "ReaderThread");
    }

    void startThread(){
        readerThread.start();
    }

    @Override
    public void run() {
        int i = 0 ;
        while (true){
            final int DELAY = 1000;
            try {
                Thread.sleep(DELAY);
            }catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }catch (IllegalArgumentException ee){
                System.out.println(ee.getMessage());
            }
            data.readQ(i);
            i++;
        }
    }
}
   
