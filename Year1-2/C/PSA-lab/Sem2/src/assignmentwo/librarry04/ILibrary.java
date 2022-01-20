package assignmentwo.librarry04;

public interface ILibrary {
    void addbook(int id,String title,int noOfBooks);
    boolean showBook(int bookId);
    void showBook();
    void addMember(int id,String name, String dob);
    boolean showMember(int memberId);
    void showMember();
    boolean searchBook(int bookId);
    boolean searchMember(int memberId);
}
