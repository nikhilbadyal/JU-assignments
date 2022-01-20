package com.nikhil;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @author Nikhil
 * @date 23 Feb2020
 */

public class IncreasingThread implements  Runnable {
    private Data data;
    private Thread increasingThread;
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public IncreasingThread(Data data) {
        this.data = data;
        increasingThread = new Thread(this, "increasingThread");
    }

    @Override
    public void run() {
        int i = 0 ;
        while (i != 2){
            int value = 0 ;
            System.out.println("Enter how much increment do you want :- ");
            try{
                value = Integer.parseInt(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
            data.increase(value);
            i++;
        }
    }

    void startThread(){
        increasingThread.start();
    }
}
   
