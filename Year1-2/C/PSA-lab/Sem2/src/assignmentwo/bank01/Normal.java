package assignmentwo.bank01;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @author Nikhil
 * @date 24 Jan2020
 */

public class Normal extends Bank {
    private static final double MAX = 250_000;

    Normal(){
        super();
    }
    Normal(Bank bank) {
        super(bank);
    }

    Normal(String name, double loanamount, int costumerId, String password, int phone) {
        super(name, loanamount, costumerId, password, phone);
    }

    @Override
    public String toString() {
        return  "Name :- "+this.name+
                "\nCostumer id :- "+this.costumerId+
                "\nMaximum Loan limit :- 2.5 Lakh"+
                "\nCurrent loan amount :- "+ this.loanamount+
                "\nLoan you can seek :- "+(Normal.MAX - this.loanamount)+"\n";
    }

    @Override
    public void loanRequest() {
        System.out.println("How much loan do you need :- ");
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int amount = Integer.parseInt(br.readLine());
            if (this.loanamount + amount > MAX) {
                System.out.println("You can't exceed your max limit.");
            } else {
                this.loanamount += amount;
            }
        } catch (IOException ioError) {
            System.out.println("IO Error occurred.");
        }
    }
    @Override
    void data() {
        String str = "Current loan amount - "+ this.loanamount+"\nMax Limit :- "
                +Normal.MAX+ "\nRemaining amount :- "+(Normal.MAX - this.loanamount);
        System.out.println(str);
    }
}
   
