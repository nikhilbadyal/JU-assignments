package assignmentone.question03;

class  CmToFeet{
    void iTof(double d){
        final double REFERANCE = 30.5;
        double dd = d/REFERANCE;
      //  DecimalFormat df = new DecimalFormat("#.##");
        /*int da = (int) dd;
        System.out.println("Height in Feet is "+df.format(dd) );*/
        String str = String.valueOf(dd);
        int index = str.indexOf('.');
        System.out.print(str.substring(0,index));
        System.out.print(" Inches ");
        System.out.println(str.substring(index+1));
     /*  String s = str.substring(index+1);*/
        System.out.println("feet");


    }
}
class FeetToCm{
    void  ftoi(double d){
        final double REFRENCE= 2.54;
        double dd = d*REFRENCE;
        //DecimalFormat df = new DecimalFormat("#.##");
        System.out.println("Height in cm is "+ dd);
    }
}
public class  CmFeet {
    public  static  void main(String[] args){
        CmToFeet cf =  new CmToFeet();
        FeetToCm  fc = new FeetToCm();
        final int CHECK = 35;
        cf.iTof(CHECK);
    //    fc.ftoi(5.5);
    }
}
