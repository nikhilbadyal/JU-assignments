package com.nikhil;

/**
 * @author Nikhil
 * @date 23 Feb2020
 */

public class Data {
    private int data ;
    private boolean isAnyOneIncreasingData ;
    private boolean isAnyOneDecreasingData;

    public Data(int data) {
        this.data = data;
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    synchronized  void increase(int data){
        System.out.println("Increasing value.");
        while (isAnyOneDecreasingData || isAnyOneIncreasingData){
            try{
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
                Thread.currentThread().interrupt();
            }
        }
        isAnyOneIncreasingData = true;
        this.data += data;
        isAnyOneIncreasingData = false;
        System.out.println("Value after increment "+ this.getData());
        notifyAll();
    }

    synchronized  public  void decrease(){
        while (isAnyOneIncreasingData || isAnyOneDecreasingData){
            try{
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
                Thread.currentThread().interrupt();
            }
        }
        System.out.println("Decreasing value");
        isAnyOneDecreasingData = true;
        this.data -= 5;
        isAnyOneDecreasingData = false;
        notifyAll();
    }
}
   
