package assignmentwo.library03;

/**
 * @author Nikhil
 * @date 10 Feb2020
 */

public class LibraryMain {
    public static void main(String[] args){
        Library myLibrary = new Library(5,5);
        myLibrary.addBook();
        myLibrary.addBook();
        myLibrary.addBook();
        myLibrary.addBook();
        myLibrary.addBook();
        myLibrary.addMember();
        System.out.println("Issuing book");
        boolean status2 = myLibrary.issueRequest();
        boolean status21 = myLibrary.issueRequest();
        boolean status22= myLibrary.issueRequest();
        boolean status23= myLibrary.issueRequest();
        boolean status24= myLibrary.issueRequest();
        System.out.println("Returning book");
        boolean statusCheck = myLibrary.returnRequest();
        boolean statusCheck1 = myLibrary.returnRequest();
        boolean statusCheck2= myLibrary.returnRequest();
        boolean statusCheck3= myLibrary.returnRequest();
        boolean statusCheck4= myLibrary.returnRequest();
      //  boolean statusCheck3 = myLibrary.returnRequest();
       /* myLibrary.displayAllMembers();
        myLibrary.displayAllBooks();
        myLibrary.displayOneBook();
        myLibrary.displayOneMember();
        myLibrary.displayParticularInfoOfMember();
        myLibrary.displayParticularInfoOfBook();
        myLibrary.updateMember();
        myLibrary.updateBook();*/
        myLibrary.showTransactionRequest();
       // myLibrary.showTransactionRequest(10);
    }
}
   
