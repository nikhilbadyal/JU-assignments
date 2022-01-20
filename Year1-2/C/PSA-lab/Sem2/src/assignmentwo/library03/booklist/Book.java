package assignmentwo.library03.booklist;


/**
 * @author Nikhil
 * @date 27 Jan2020
 */

public class Book {
    protected  long id ;
    protected  String title ;
    protected  String author;
    protected String publisher;
    private  int count;


    public Book(Book b){
        this.author = b.author;
        this.id = b.id;
        this.publisher = b.publisher;
        this.title = b.title;
        this.count = b.count;
    }

    public Book(String author ,  long id , String title , String publisher , int count){
        this.title = title;
        this.publisher = publisher;
        this.id = id;
        this.author = author;
        this.count = count;
    }

    public Book(){
        this.id = 0;
        this.author = "";
        this.publisher = "";
        this.title = "";
        this.count = 0;
    }

    @Override
    public String toString() {
        return "Book{" +
                "id=" + id +
                ", title='" + title + '\'' +
                ", author='" + author + '\'' +
                ", publisher='" + publisher + '\'' +
                ", count=" + count +
                '}';
    }

    @Override
    public boolean equals(Object obj) {
        boolean check = false;
        if(obj != null && this.getClass() == obj.getClass()){
            check = true;
        }
        if(this == obj ) {
            check = true;
        }
        Book  book = (Book) obj ;
        if(obj != null && book.title.equals(this.title) &&  book.id == this.id
                && book.author.equals(this.author ) &&  book.publisher.equals(this.publisher)){
            check = true;
        }
        return  check;
    }

    @Override
    public int hashCode() {
        final int PRIME = 17;
        int result  = 31;
        result = PRIME * result +  ((this.title == null )? 0 : this.title.hashCode() );
        result = PRIME * result +  ((this.title == null )? 0 : this.publisher.hashCode() );
        result = PRIME * result +  ((this.title == null )? 0 : this.author.hashCode() );
        result = PRIME * result +  (int) this.id ;
        return  result;
    }


    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public String getPublisher() {
        return publisher;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }
}
