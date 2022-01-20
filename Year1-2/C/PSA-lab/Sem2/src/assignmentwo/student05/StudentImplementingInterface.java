package assignmentwo.student05;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @author Nikhil
 * @date 03 Feb2020
 */

public class StudentImplementingInterface  implements  StudentInterface{

    private int roll ;
    private String name ;
    private int score;


    StudentImplementingInterface() {
        this.name = "";
        this.roll = 0;
        this.score = 0;
    }

    StudentImplementingInterface(int score, String name, int roll) {
        this.score = score;
        this.roll = roll;
        this.name = name;

    }

    StudentImplementingInterface(StudentImplementingInterface studentobj) {
        this.name = studentobj.name;
        this.roll = studentobj.roll;
        this.score = studentobj.score;
    }


    @Override
    public String toString() {
        return  "Name :- "+ this.name + "\n"
                + "Roll :- "+ this.roll + "\n"+
                "Score :- "+ this.score;
    }

    @Override
    public boolean equals(Object obj) {
        boolean check = false;
        if(obj != null && this.getClass() == obj.getClass()){
            check = true;
        }
        if(this == obj ) {
            check = true;
        }
        StudentImplementingInterface std = (StudentImplementingInterface)obj ;
        if(obj != null && std.name.equals(this.name) && std.score == this.score && std.roll == this.roll) {
            check = true;
        }
        return  check;
    }

    @Override
    public int hashCode() {
        final int PRIME = 17;
        int result  = 31;
        result = PRIME * result +  ((this.name == null )? 0 : this.name.hashCode() );
        result = PRIME * result +  this.roll;
        result = PRIME * result +  this.score;
        return  result;
    }

    @Override
    public boolean setScore(){
        System.out.println("Enter score :- ");
        try{
            final int MAXIMUMALLOWDMARKS = 100;
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int scoreToBeUpdated = -1  ;
            score = Integer.parseInt(br.readLine());
            if( scoreToBeUpdated >= 0 && score <= MAXIMUMALLOWDMARKS){
                this.score = scoreToBeUpdated;
            }else{
                throw  new IllegalArgumentException("Please enter marks in permitted range.");
            }
        }catch (IllegalArgumentException illegalerror){
            illegalerror.getMessage();
        }catch(IOException ioError){
            System.out.println("Action cannot be performed at this instant of time.");
            return  false;
        }
        return  true;
    }
    boolean setScore(int score){
        final int MAXIMUMALLOWDMARKS = 100;
        try{
            if( score >= 0 && score <= MAXIMUMALLOWDMARKS){
                this.score = score;
            }else{
                throw  new IllegalArgumentException("Please enter marks in permitted range.");
            }
        }catch (IllegalArgumentException illegalerror){
            illegalerror.getMessage();
            return false;
        }
        return  true;
    }


}
   
