package assignmentthree.account02;

import java.util.Objects;

/**
 * @author Nikhil
 * @date 13 Feb2020
 */

public class Account implements  Comparable<Account> {
    private  long accNo;
    private  String name;
    private double balance;

    public Account(long accNo, String name, double balance) {
        this.accNo = accNo;
        this.name = name;
        this.balance = balance;
    }

    @Override
    public String toString() {
        return "Account{" +
                "balance=" + balance +
                ", accNo=" + accNo +
                ", name='" + name + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if(o== null){
            return  false;
        }
        if (this == o) {
            return true;
        }
        if (o.getClass() == this.getClass()){
            return false;
        }
        Account account = (Account) o;
        return Double.compare(account.getBalance(), getBalance()) == 0 &&
                getAccNo() == account.getAccNo() &&
                Objects.equals(getName(), account.getName());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getBalance(), getAccNo(), getName());
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public long getAccNo() {
        return accNo;
    }

    public void setAccNo(long accNo) {
        this.accNo = accNo;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public int compareTo(Account account) {
        if(accNo < account.accNo){
            return  -1;
        }else if(accNo > account.accNo){
            return  1;
        }else{
            return  0;
        }
    }
}
   
