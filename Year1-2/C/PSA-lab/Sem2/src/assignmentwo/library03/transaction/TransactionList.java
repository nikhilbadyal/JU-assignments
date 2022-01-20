package assignmentwo.library03.transaction;

import assignmentwo.library03.booklist.Book;
import assignmentwo.library03.memberlist.Member;


/**
 * @author Nikhil
 * @date 03 Feb2020
 */

public class TransactionList {
    private static final  int NO= 10;
    private   Transaction[] bunchOfTranscaction;
    private static int count ;

    public TransactionList(Transaction[] bunchOfTranscaction) {
        this.bunchOfTranscaction = bunchOfTranscaction;
    }
    public  TransactionList(int n){
        this.bunchOfTranscaction = new  Transaction[n];
    }

    public TransactionList() {
        this.bunchOfTranscaction = new Transaction[NO];
    }

    private  static  void  updateStatic(){
        TransactionList.count++;
    }

    public void updateTransaction(Book book , Member member , boolean status){
        if(status){
            Transaction transaction = new Transaction(book, member , status);
            bunchOfTranscaction[TransactionList.count] = transaction;
            TransactionList.updateStatic();
        }
    }
    public void updateTransaction(long bookId, Member member , boolean status) { // return
        if(!status){
            for(int i = 0 ; i < TransactionList.count ; ++i){
                if(bunchOfTranscaction[i].getMembObj().equals(member) &&
                        bunchOfTranscaction[i].getBookObj().getId() == bookId){
                    bunchOfTranscaction[i].setStatus(status);
                }
            }
        }
    }

    public void showTransaction(int show) {
        int toPrint = Math.min(show, TransactionList.count);
        for(int i = 0 ; i < toPrint ; ++i){
            System.out.println(bunchOfTranscaction[i]);
        }
    }

    public void showTransaction() {
        int toPrint = 10;
        if(TransactionList.count < toPrint){
            toPrint = TransactionList.count;
        }
        for(int i = 0 ; i < toPrint ; ++i){
            System.out.println(bunchOfTranscaction[i]);
        }
    }
}
   
