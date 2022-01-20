package assignmentone.question08;

import assignmentone.question07.Student;

public class Modify  extends Student {
     Modify(int roll){
        super();
        this.roll = roll;
     }
     Modify(String name , int roll){
         super();
         this.name = name ;
         this.roll = roll;
     }
     Modify(){
         super();
     }
     Modify(String name , int roll , int score){
         super(name, score,roll);
     }
     Modify(Modify m){
         super(m);
     }
}
