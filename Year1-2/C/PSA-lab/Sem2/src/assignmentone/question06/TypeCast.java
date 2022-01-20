package assignmentone.question06;

/**
 * @author Nikhil
 */

public class TypeCast {
    public  static  void main(String[] args){
        Cast cst = new Cast();
        int i = 10;
        short s = 8;
        byte b = 10;
        long lg = 10;
        double d = 10.5;
        float f = (float) 23.4;
        cst.cast(i);
        cst.cast(s);
        cst.cast(b);
        cst.cast(d);
        cst.cast(f);
        cst.cast(lg);
    }
}
class Cast{
    void cast(int i ){
        System.out.println("Value of i is int wala "+ i);
    }
    void cast(double i){
        System.out.println("Value of i is double wala "+ i);
    }
}


