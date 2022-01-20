package assignmentwo.library03;

import assignmentwo.library03.booklist.Book;

/**
 * @author Nikhil
 * @date 03 Feb2020
 */

public class RequiredClass {
    private boolean check ;
    private Book book;

    public RequiredClass(boolean b , Book book){
        this.check = b;
        this.book = book;
    }

    public boolean isCheck() {
        return check;
    }

    public void setCheck(boolean check) {
        this.check = check;
    }

    public Book getBook() {
        return book;
    }

    public void setBook(Book book) {
        this.book = book;
    }
}


