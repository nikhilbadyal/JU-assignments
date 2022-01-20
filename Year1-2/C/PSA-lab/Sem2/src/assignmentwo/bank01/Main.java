package assignmentwo.bank01;

/**
 * @author Nikhil
 * @date 24 Jan2020
 */

public class Main {
    public static void main(String[] args){
        Bank bnk = new Bank("Nikhil",0.0,1_811_069,"nikhil6521",682_319_516);
        Privlaged pvg = new Privlaged(bnk);
        Normal nm = new Normal(bnk);

        pvg.update();
        nm.update();
        pvg.loanRequest();
        nm.loanRequest();
        pvg.data();
        nm.data();
        pvg.loanRequest();
        nm.loanRequest();
        System.out.println(pvg);
        System.out.println(nm);

    }
}
   
