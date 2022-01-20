package com.nikhil;

import java.security.SecureRandom;
import java.util.Random;

/**
 * @author Nikhil
 * @date 22 Feb2020
 */

public class Data {
    private int storedData;
    private boolean isAnyOneReading;
    private Random random = new SecureRandom();
    public Data() {
    }

    public  void readQ(int number) {
        synchronized (this){
            isAnyOneReading = true;
            System.out.println(number + " started reading and readed "+ this.storedData);
        }
        final int DELAY = 1000;
        try {
            Thread.sleep(DELAY);
        }catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        synchronized (this){
            isAnyOneReading = false;
            System.out.println(number + " stopped reading ");
            notifyAll();
        }
    }

    public synchronized void writeQ(int dataToBeWritten) {
        while (isAnyOneReading){
            try{
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
                System.out.println("Done");
                Thread.currentThread().interrupt();
            }
        }
        System.out.println(dataToBeWritten + " started writting and wrote "+ dataToBeWritten);
        this.storedData = dataToBeWritten;
        final int DELAY = 5000;
        try {
            Thread.sleep( DELAY);
        }catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        System.out.println(dataToBeWritten + " ended writting ");
        notifyAll();
    }
}
   
