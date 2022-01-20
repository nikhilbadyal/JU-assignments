package assignmentone.question01;

/**
 * @author Nikhil
 */

public class AcceptShort {
    public static void main(String[] args){
        final int NUM1 = 20;
        final int NUM2 = 20;
        short s1 = NUM1;
        short s2 = NUM2;
        Accept.showSum(s1,s2 );

    }
}
final class  Accept{
    private  Accept(){
        throw new IllegalStateException("Utility class.");
    }
    static void showSum(short s1, short s2){
        System.out.println("Sum of entered number is "+(s1+s2));
    }
}

