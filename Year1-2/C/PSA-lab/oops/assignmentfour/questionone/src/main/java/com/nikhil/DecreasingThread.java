package com.nikhil;


/**
 * @author Nikhil
 * @date 23 Feb2020
 */

public class DecreasingThread implements  Runnable {
    private Data data;
    private Thread decreasingThread ;

    public DecreasingThread(Data data) {
        this.data = data;
        decreasingThread = new Thread(this, "DecreasingThread");
    }

    @Override
    public void run() {
        int i = 0 ;
        while (i != 2){
            data.decrease();
            i++;
        }
    }

    void startThread(){
        decreasingThread.start();
    }
}
   
