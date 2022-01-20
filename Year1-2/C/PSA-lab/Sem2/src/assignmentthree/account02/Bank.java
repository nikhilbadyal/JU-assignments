package assignmentthree.account02;

/**
 * @author Nikhil
 * @date 13 Feb2020
 */

public class Bank {
    public static void main(String[] args){
        AccountList accountList = new AccountList();

        System.out.println( accountList.addMember());
        System.out.println( accountList.addMember());
        System.out.println( accountList.addMember());
        double balance = accountList.getBalance();
        long id = 822;
        System.out.println( accountList.getBalance(id));
        accountList.displayAll();
        System.out.println( accountList.doesItExists(id));
    }
}
   
