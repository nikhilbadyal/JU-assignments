package assignmentone.question04;

import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import  java.io.BufferedReader;

class Area {
    public static  final  double PIE = 3.14;
    protected int radius ;
    void calc() throws IOException {
        System.out.println("Enter radius of circle ");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        this.radius = Integer.parseInt(str);
        double d = Area.PIE *radius*radius;
        DecimalFormat df = new DecimalFormat("#.##");
        System.out.println("Area of given circle is "+ df.format(d));
    }

    void calc(int radius){
        double d = Area.PIE *radius*radius;
        DecimalFormat df = new DecimalFormat("#.##");
        System.out.println("Area of given circle is "+ df.format(d));
    }
}
public  class   Main{
    public  static  void main(String[] args){
        try{
            Area a = new Area();
            a.calc();
            final int RADIUS = 10;
            a.calc(RADIUS);
        }catch (IOException err){
            System.out.println("IO Exception.");
        }

    }
}
