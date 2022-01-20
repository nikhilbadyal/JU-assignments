package assignmentone.question09;

/**
 * @author Nikhil
 */

public class BankAccount {
    private  static  final  double RATEALLOT = 6.8;
    protected static  double rate= RATEALLOT;
    private String name;
    private int accNo;
    private double balance;
    private  int month ;

    BankAccount(){
        name = "";
        this.accNo = 0;
        this.balance = 0.0;
        this.month = 0;
    }

    BankAccount(String name , int  acc , double balance,int month){
        this.name = name;
        this.accNo = acc;
        this.balance = balance;
        this.month = month;
    }

    static void updateRate(double rate){
        BankAccount.rate = rate;
    }
    static void showRate(){
        System.out.println("Current interest rate is :- "+BankAccount.rate);
    }
    void showBalance() {
        System.out.println("Balance available is :- " + balance);
    }
    void calcInterest(){
        final double DIVIDE = 0.01;
        double bal = (balance*rate*month)*DIVIDE;
        System.out.println("Interest amount is "+bal);
    }

    @Override
    public String toString() {
        return "Account Number :- "+this.accNo+
                "Name :- "+this.name+
                "Balance :- "+this.balance;

    }
}
