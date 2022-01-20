package assignmentwo.bank01;
import  java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


/**
 * @author Nikhil
 * @date 24 Jan2020
 */

public class Bank {
    protected String name ;
    protected double loanamount;
    protected int  costumerId;
    protected String password;
    protected  int phone;

    Bank(Bank bank){
        this.loanamount = bank.loanamount;
        this.costumerId = bank.costumerId;
        this.name = bank.name;
        this.password = bank.password;
        this.phone = bank.phone;
    }
    Bank(String name , double loanamount, int costumerId , String password, int phone){
        this.password = password;
        this.name = name;
        this.costumerId = costumerId;
        this.loanamount = loanamount;
        this.phone= phone;
    }

    public Bank(String name, int costumerId, String password, int phone) {
        this.name = name;
        this.costumerId = costumerId;
        this.password = password;
        this.phone = phone;
        this.loanamount = 0.0;
    }

    public  Bank(){
        System.out.println("Please enter data to crete account.");
    }
    public void update(){
        System.out.println("What do you want to update.");
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String str = br.readLine();
            if ("phone".equalsIgnoreCase(str)) {
                System.out.println("Enter phone number :- ");
                this.phone = Integer.parseInt(br.readLine());
            }else if("Name".equalsIgnoreCase(str)){
                System.out.println("Enter Name :- ");
                this.name = br.readLine();
            }else{
                throw  new IllegalArgumentException();
            }
        }catch (IOException ioError){
            System.out.println("IO Error occurred.");
        }catch (IllegalArgumentException err){
            System.out.println("Unknown request.");
        }
    }
    public void loanRequest(){
        System.out.println("Currently loan is unavailable for current user.");
    }
    void data(){
        System.out.println("No information available for this user,");
    }
}

   
