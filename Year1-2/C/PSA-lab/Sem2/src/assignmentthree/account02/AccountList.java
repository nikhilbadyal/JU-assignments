package assignmentthree.account02;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;


/**
 * @author Nikhil
 * @date 13 Feb2020
 */

public class AccountList  {
    private static final String ACCOUNT_NOT_FOUND = "Account not found.";
    private static final String NO_DATA = "No data exist.";
    private TreeSet<Account> accounts;

    public AccountList() {
       this.accounts = new TreeSet<>();
    }

    public boolean addMember() {
        try{
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Enter account number , Name , Balance.");
            return  accounts.add(new Account(Long.parseLong(bufferedReader.readLine()),
                    bufferedReader.readLine(),Double.parseDouble(bufferedReader.readLine())));

        }catch(NumberFormatException | IOException numberFormat){
            numberFormat.getMessage();
        }
        return false;
    }

    public double getBalance() {
        double balance = 0.0;
        if(accounts.isEmpty()){
            System.out.println(NO_DATA);
            return balance;
        }
        try{
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Enter account number.");
            long accno = Long.parseLong(bufferedReader.readLine());
            Account account = accounts.ceiling(new Account(accno,"",0.0));
            if(account.getAccNo() == accno){
                balance = account.getBalance();
                System.out.println(balance);
                return  balance;
            }else{
                System.out.println(ACCOUNT_NOT_FOUND);
            }
        }catch(NumberFormatException | IOException numberFormat){
            numberFormat.getMessage();
        }
        return balance;
    }

    public double getBalance(long accno) {
        double balance = -0.0;
        if(accounts.isEmpty()){
            System.out.println(NO_DATA);
            return  balance;
        }
        Account account = accounts.ceiling(new Account(accno,"",0.0));
        if(account.getAccNo() == accno){
            balance = account.getBalance();
            System.out.println(balance);
            return  balance;
        }else{
            System.out.println(ACCOUNT_NOT_FOUND);
        }
        return  balance;
    }

    public void displayAll() {
        if(accounts.isEmpty()){
            System.out.println(NO_DATA);
            return;
        }
        for(Account account : accounts ){
            System.out.println(account);
        }
    }

    public boolean doesItExists(long accno) {
        if(accounts.isEmpty()){
            System.out.println(NO_DATA);
            return  false;
        }
        Account account = accounts.ceiling(new Account(accno,"",0.0));
        if(account.getAccNo() == accno){
            System.out.println("Yes , it exist.");
            return  true;
        }else{
            System.out.println(ACCOUNT_NOT_FOUND);
        }
        return false;
    }
}
   
