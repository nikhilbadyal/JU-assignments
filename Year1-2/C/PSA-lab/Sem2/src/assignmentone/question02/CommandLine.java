package assignmentone.question02;

/**
 * @author Nikhil
 */

public class CommandLine {
    public static  void main(String[] args){
        System.out.println("No. of parameter are "+ args.length);
        for(String i : args){
            System.out.println(i);
        }

    }
}
