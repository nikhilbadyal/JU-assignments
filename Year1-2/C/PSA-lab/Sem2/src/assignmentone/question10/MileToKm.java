package assignmentone.question10;
import java.text.DecimalFormat;

class  MtoK{
    void  mtok(double d){
        double dd = d*1.6;
        DecimalFormat df = new DecimalFormat("#.##");
        System.out.println("Metre to Kilometer "+df.format(dd) );
    }
}

class  KtoM{
    void  ktom(double d){
        double dd = d/1.6;
        System.out.println("Kilometer to metre "+ dd);
    }
}

public class  MileToKm  {
    public  static  void main(String[] args){
        KtoM km=  new KtoM();
        MtoK  mk = new MtoK();
        km.ktom(160.5);
        mk.mtok(5.5);
    }
}
