package com.nikhil;

import java.security.SecureRandom;
import java.util.Random;

/**
 * @author Nikhil
 * @date 22 Feb2020
 */

public class Writer  implements  Runnable{
    private Data data;
    private Thread writerThread;
    private Random random = new SecureRandom();

    public Writer(Data data) {
        this.data = data;
        writerThread = new Thread(this,"WriterThread," );
    }

    void startThread(){
        writerThread.start();
    }

    @Override
    public void run() {
        int i = 0 ;
        int j = 0 ;
        while (true){
            final long DELAY = 1000;
            try {
                Thread.sleep(DELAY);
            }catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }catch (IllegalArgumentException ee){
                System.out.println(ee.getMessage());
            }
            data.writeQ(i);
            i++;
           j++;
        }
    }
}
   
