package assignmentone.question05;

class  Check{
    void check(String s){
      //  String s1 = "Nikhil";
      //  String s2 = s;
        String s1 = s;
        String s2 = "Nikhil";
     //   String s2 = new String("Nikhil");
       if(s.equals(s1)) {
           System.out.println("Hello dear 01");
       }
       if(s == s1)  {
           System.out.println("Hello dear 02");
       }
        if(s == s2) {
            System.out.println("Hello dear 03");
        }
        if(s.equals(s2)) {
            System.out.println("Hello dear 04");
        }
    }
}
public class StringCheck {
    public  static  void main(String[] args){
        Check c = new Check();
        c.check("Nikhil");
   //     Stringcheck sc = new Stringcheck();
      //  sc.check("Nikhil");
    }
}
