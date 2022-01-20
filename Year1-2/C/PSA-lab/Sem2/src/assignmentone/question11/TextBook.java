package assignmentone.question11;

import java.io.*;

public class TextBook {
    String title;
    String publisher;
    String author;

    public TextBook(String title, String publisher, String author) {
        this.title = title;
        this.publisher = publisher;
        this.author = author;
    }

    public TextBook() {
        this.author = "";
        this.publisher = "";
        this.title = "";
    }

    void set() throws IOException {
        System.out.println("Enter textbook details :- ");
        String phone ;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        this.title = br.readLine();
        this.publisher = br.readLine();
        this.author = br.readLine();
    }

    @Override
    public String toString() {
        return "TextBook{" +
                "title='" + title + '\'' +
                ", publisher='" + publisher + '\'' +
                ", author='" + author + '\'' +
                '}';
    }
}
