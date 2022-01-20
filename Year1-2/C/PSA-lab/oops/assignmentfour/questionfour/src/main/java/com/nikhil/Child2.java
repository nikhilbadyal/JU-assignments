package com.nikhil;


/**
 * @author Nikhil
 * @date 24 Feb2020
 */

public class Child2 {
    Data d;
    private double average = 0.0;

    public Child2(Data d) {
        this.d = d;
    }

    public Data getD() {
        return d;
    }

    public double getAverage() {
        return average;
    }

    void calculateAverageRequest(String which){
        if(which.equalsIgnoreCase("feature1")){
            calculateAverage(d.getFeature1());
        }else if(which.equalsIgnoreCase("feature2")){
            calculateAverage(d.getFeature2());
        }else if(which.equalsIgnoreCase("feature3")){
            calculateAverage(d.getFeature3());
        }else if(which.equalsIgnoreCase("feature4")){
            calculateAverage(d.getFeature4());
        }else  if(which.equalsIgnoreCase("feature5")){
            calculateAverage(d.getFeature5());
        }else{
            System.out.println("Please enter properly.");
        }
    }

    private void calculateAverage(double[] feature) {
        double sum = 0.0;
        for(int i = 0 ; i < feature.length ; ++i){
            sum += feature[i];
        }
        average =  sum /feature.length;
    }
}
   
