package assignmentwo.library03.transaction;

import assignmentwo.library03.booklist.Book;
import assignmentwo.library03.memberlist.Member;

import java.util.Objects;

/**
 * @author Nikhil
 * @date 03 Feb2020
 */

public class Transaction {
    private Book bookObj ;
    private  Member membObj ;
    private boolean status ;

    public Transaction(Book bookObj , Member membObj, boolean status){
        this.bookObj = bookObj;
        this.membObj = membObj;
        this.status = status ;
    }

    public    Transaction(){ }

    @Override
    public boolean equals(Object o) {
        if(o == null){
            return  false;
        }
        if (this == o) {
            return true;
        }
        if ((o.getClass() == this.getClass())){
            return false;
        }
        Transaction that = (Transaction) o;
        return status == that.status &&
                Objects.equals(bookObj, that.bookObj) &&
                Objects.equals(membObj, that.membObj);
    }

    @Override
    public int hashCode() {
        return Objects.hash(bookObj, membObj, status);
    }

    @Override
    public String toString() {
        return "Transaction{" +
                "bookObj=" + bookObj +
                ", membObj=" + membObj +
                ", status=" + status +
                '}';
    }

    public Book getBookObj() {
        return bookObj;
    }

    public void setBookObj(Book bookObj) {
        this.bookObj = bookObj;
    }

    public Member getMembObj() {
        return membObj;
    }

    public void setMembObj(Member membObj) {
        this.membObj = membObj;
    }

    public boolean isStatus() {
        return status;
    }

    public void setStatus(boolean status) {
        this.status = status;
    }
}
   
