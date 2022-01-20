package assignmentwo.library03;

import assignmentwo.library03.booklist.BookList;
import assignmentwo.library03.memberlist.MemberList;
import assignmentwo.library03.transaction.TransactionList;

import java.io.IOException;
import java.io.InputStreamReader;
import  java.io.BufferedReader;


/**
 * @author Nikhil
 * @date 03 Feb2020
 */

public class Library {
        private BookList bookList ;
        private MemberList memberList ;
        private TransactionList transactionList ;

    public Library(int listSIze) {
        this.bookList = new BookList(listSIze);
        this.memberList =  new MemberList(listSIze);
        this.transactionList = new TransactionList(listSIze);
    }
    public Library(int bookListSize , int memberListSize) {
        this.bookList = new BookList(bookListSize);
        this.memberList =  new MemberList(memberListSize);
        this.transactionList = new TransactionList();
    }

    private  Library() { }

    public void addBook(long bookId, String author , String title , String publisher) {
        bookList.addBook(bookId, author , title , publisher);
    }

    public void addBook() {
        bookList.addBook();
    }

    public void addMember() {
        memberList.addMember();
    }

    public boolean issueRequest() {
        System.out.println("Enter book id :- ");
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        boolean bookFound = false;
        boolean studentFound = false;
        try{
            String bookIdString  = bufferedReader.readLine();
            long bookId = Long.parseLong(bookIdString);
            for(int i = 0 ; i < BookList.getCount() ; ++i ){
                if(bookList.bunchOfBooks[i].getId() == bookId && bookList.bunchOfBooks[i].getCount()> 0) {
                    bookFound = true;
                    System.out.println("Enter student id :- ");
                    String studentIdString = bufferedReader.readLine();
                    long studentId = Long.parseLong(studentIdString);
                    for(int j = 0 ;j < MemberList.getCount() ; ++j){
                        if(memberList.bunchOfMember[j].getId() == studentId ){
                            studentFound = true;
                            if(memberList.issueBook(bookList.bunchOfBooks[i],memberList.bunchOfMember[j])){
                                transactionList.updateTransaction(bookList.bunchOfBooks[i],
                                        memberList.bunchOfMember[j], true);
                                return true;
                            }else{
                                return  false;
                            }
                        }
                    }
                }
            }
        }catch(NumberFormatException numberFormat){
            numberFormat.getMessage();
        }catch (IOException ioError){
            System.out.println("IO Error occurred.");
        }
        if (!bookFound){
            System.out.println("Book not found.");
            return  false;
        }
        if (!studentFound){
            System.out.println("Student not found.");
            return  false;
        }
        return false;
    }

    public boolean returnRequest() {
        System.out.println("Enter Student id :- ");
        boolean studentFound = false;
        try{
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
            String studentIdString  = bufferedReader.readLine();
            long studentId = Long.parseLong(studentIdString);
            for(int i = 0 ; i < MemberList.getCount() ; ++i ){
                if(memberList.bunchOfMember[i].getId() == studentId) {
                    studentFound = true;
                    System.out.println("Enter book id :- ");
                    String bookIdString = bufferedReader.readLine();
                    long bookId = Long.parseLong(bookIdString);
                    if(memberList.returnBook(bookId, memberList.bunchOfMember[i])){
                        transactionList.updateTransaction(bookId,
                                memberList.bunchOfMember[i], false);
                        return  true;
                    }else{
                        return  false;
                    }
                }
            }
        }catch (IOException ioError){
            System.out.println("IO Error occurred.");
        }
        if(!studentFound){
            System.out.println("Student not found.");
            return  false;
        }
        return false;
    }

    public void displayAllMembers() {
        memberList.displayAll();
    }

    public void displayAllBooks() {
        bookList.displayAll();
    }

    public void displayOneBook() {
        bookList.displayOneBook();
    }

    public void displayOneMember() {
        memberList.displayOneMember();
    }

    public void displayParticularInfoOfMember() {
        memberList.displayParticularInfoOfMember();
    }

    public void displayParticularInfoOfBook() {
        bookList.displayParticularInfoOfBook();
    }

    public void updateMember() {
        memberList.update();
    }

    public void updateBook() {
        bookList.update();
    }


    public void showTransactionRequest() {
        transactionList.showTransaction();
    }

    public void showTransactionRequest(int count ) {
        transactionList.showTransaction(count );
    }
}


