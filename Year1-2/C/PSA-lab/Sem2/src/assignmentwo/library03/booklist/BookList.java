package assignmentwo.library03.booklist;

import assignmentwo.library03.RequiredClass;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @author Nikhil
 * @date 27 Jan2020
 */


public class BookList {
    public Book[] bunchOfBooks;
    private static int count ;
    private  static final String ENTERID = "Enter book id :- ";
    private  static final String NEWDETAILS = "Enter new details.";

    public BookList(int count){
        this.bunchOfBooks = new Book[count];
    }

     public RequiredClass isUnique(long id){
        int i ;
        for(i = 0 ; i < bunchOfBooks.length ; ++i){
            if(bunchOfBooks[i] != null && bunchOfBooks[i].id == id ){
                return  new RequiredClass(false, bunchOfBooks[i]);
            }
        }
        return  new RequiredClass(true, bunchOfBooks[i-1]);
    }

    public RequiredClass isUnique(Book b){
        boolean checked = true;
        int i ;
        for(i = 0 ; i < bunchOfBooks.length ; ++i){
            if(bunchOfBooks[i].equals(b)){
                checked = false;
                break;
            }
        }
        return  new RequiredClass(checked, bunchOfBooks[i]);
    }


    public void displayOneBook(){
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.println(ENTERID);
            String str ;
            str = br.readLine();
            long id = Integer.parseInt(str);
            RequiredClass u = isUnique(id);
            if(!u.isCheck()){
                System.out.println(u.getBook());
            }else{
                System.out.println("Book not found.");
            }

        }catch(NumberFormatException numberFormat){
          System.out.println("Please enter data carefully.");
        }catch (IOException ioError){
            System.out.println("IO Error occurred.");
        }
    }

    public void displayParticularInfoOfBook(){
        System.out.println(ENTERID);
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.println(ENTERID);
            String idString = br.readLine();
            long id = Long.parseLong(idString);
            RequiredClass utilityClassObj = isUnique(id);
            if(!utilityClassObj.isCheck()){
                System.out.println("What do you check.");
                String str = br.readLine();
                if("title".equalsIgnoreCase(str)){
                    System.out.println(utilityClassObj.getBook().getTitle());
                }else if("author".equalsIgnoreCase(str)){
                    System.out.println(utilityClassObj.getBook().getAuthor());
                }else if("publisher".equalsIgnoreCase(str)){
                    System.out.println(utilityClassObj.getBook().getPublisher());
                }else{
                    System.out.println("Please enter valid choice.");
                }
            }
        }catch (IOException ioError){
            System.out.println("IO Error occurred");
        }
    }
    public  void displayAll(){
        for(int i = 0 ; i < BookList.count ; ++i ){
            System.out.println(bunchOfBooks[i]);
        }
    }
    private  static  void  updateStatic(){
        BookList.count++;
    }
    public  boolean  addBook(Book bookobj){
        try{
            RequiredClass utilityClassObj = isUnique(bookobj);
            if(utilityClassObj.isCheck()){
                this.bunchOfBooks[BookList.count] = bookobj;
                BookList.updateStatic();
                System.out.println("Book added.");
                return  true;
            }else{
                throw  new IllegalArgumentException("Id unavailable.");
            }
        }catch(IllegalArgumentException illegalArgumentError){
            System.out.println( illegalArgumentError.getMessage());
            return  false;
        }
    }

    public static int getCount() {
        return count;
    }

    public void addBook(){
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Enter Book id :- ");
            String str = br.readLine();
            long bookId = Integer.parseInt(str);
             RequiredClass utilityClassobj = isUnique(bookId);
             if(utilityClassobj.isCheck()){
                 System.out.println("Enter title , author , publisher. ");
                 Book newBookObj = new Book();
                 newBookObj.setId(Long.parseLong(str));
                 newBookObj.setTitle(br.readLine());
                 newBookObj.setAuthor(br.readLine());
                 newBookObj.setPublisher(br.readLine());
                 newBookObj.setCount(100);
                 this.bunchOfBooks[BookList.count] = newBookObj;
                 BookList.updateStatic();
                 System.out.println("Book added.");
             }else{
                 throw  new IllegalArgumentException("Id unavailable.");
             }
        }catch(IllegalArgumentException illegalArgumentError){
            System.out.println( illegalArgumentError.getMessage());
        } catch(IOException ioError  ){
            System.out.println("IO Error occurred.");
        }
    }

    public void addBook(long bookId, String author , String title , String publisher ){
        try{
            RequiredClass utilityClassobj = isUnique(bookId);
            if(utilityClassobj.isCheck()){
                Book newBookObj = new Book();
                newBookObj.setTitle(title);
                newBookObj.setAuthor(author);
                newBookObj.setPublisher(publisher);
                newBookObj.setCount(100);
                this.bunchOfBooks[BookList.count] = newBookObj;
                BookList.updateStatic();
                System.out.println("Book added.");
            }else{
                throw  new IllegalArgumentException("Id unavailable.");
            }
        }catch(IllegalArgumentException illegalArgumentError){
            System.out.println( illegalArgumentError.getMessage());
        }
    }

    boolean updateTitle(Book bookobj , String title){
        bookobj.setTitle(title);
        return  true;
    }
    boolean updateAuthor(Book bookobj, String author){
        bookobj.setAuthor(author);
        return  true;
    }
    boolean updatePublisher(Book bookobj , String publisher ){
        bookobj.setPublisher(publisher);
        return  true;
    }
    boolean updateId(Book bookobj , String id){
        long idd = Long.parseLong(id);
        bookobj.setId(idd);
        return  true;
    }
    public void update(){
        System.out.println(ENTERID);
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int bookId = Integer.parseInt(br.readLine());
            RequiredClass utilityClassObj = isUnique(bookId);
            if(!utilityClassObj.isCheck()){
                System.out.println("What do you want to update.");
                String str = br.readLine();
                if("title".equalsIgnoreCase(str)){
                    System.out.println(NEWDETAILS);
                    this.updateTitle(utilityClassObj.getBook() , br.readLine() );
                }else if("author".equalsIgnoreCase(str)){
                    System.out.println(NEWDETAILS);
                    this.updateAuthor(utilityClassObj.getBook() , br.readLine() );
                }else if("publisher".equalsIgnoreCase(str)){
                    System.out.println(NEWDETAILS);
                    this.updatePublisher(utilityClassObj.getBook() , br.readLine() );
                }else if("id".equalsIgnoreCase(str)){
                    System.out.println(NEWDETAILS);
                    this.updateId(utilityClassObj.getBook() , br.readLine() );
                }else{
                    System.out.println("Please enter valid choice.");
                }
            }
        }catch (IOException ioError){
            System.out.println("Action cannot be performed at the moment.");
        }
    }
}
   
