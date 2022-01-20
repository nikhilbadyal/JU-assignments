package com.nikhil;


/**
 * @author Nikhil
 * @date 24 Feb2020
 */

public class Data {
    private double[] feature1;
    private double[] feature2;
    private double []feature3;
    private double[] feature4;
    private double[] feature5;


    private  double sd = 0.0;

    public double getSd() {
        return sd;
    }

    @Override
    public String toString() {
        return "Data{" +
                "feature1=" + feature1 +
                ", feature2=" + feature2 +
                ", feature3=" + feature3 +
                ", feature4=" + feature4 +
                ", feature5=" + feature5 +
                '}';
    }

    public double[] getFeature1() {
        return feature1;
    }

    public void setFeature1(double[] feature1) {
        this.feature1 = feature1;
    }

    public double[] getFeature2() {
        return feature2;
    }

    public void setFeature2(double[] feature2) {
        this.feature2 = feature2;
    }

    public double[] getFeature3() {
        return feature3;
    }

    public void setFeature3(double[] feature3) {
        this.feature3 = feature3;
    }

    public double[] getFeature4() {
        return feature4;
    }

    public void setFeature4(double[] feature4) {
        this.feature4 = feature4;
    }

    public double[] getFeature5() {
        return feature5;
    }

    public void setFeature5(double[] feature5) {
        this.feature5 = feature5;
    }

    private void calc(double[] feature){
        double sum = 0.0;
        double sd = 0.0;

        for(int i = 0 ; i < feature1.length ; ++i){
            sum += feature.length;
        }
        double mean = sum/feature.length;

        for(int i = 0 ; i < feature1.length ; ++i){
            sd = Math.pow((feature[i]-mean) , 2);
        }

        this.sd = Math.sqrt(sd/feature.length);

    }
    void  calculateSd(String which){

        if(which.equalsIgnoreCase("feature1")){
            calc(feature1);
        }else if(which.equalsIgnoreCase("feature2")){
            calc(feature2);
        }else if(which.equalsIgnoreCase("feature3")){
            calc(feature3);
        }else if(which.equalsIgnoreCase("feature4")){
            calc(feature4);
        }else  if(which.equalsIgnoreCase("feature5")){
            calc(feature5);
        }else{
            System.out.println("Please enter properly.");
        }
    }

}
   
