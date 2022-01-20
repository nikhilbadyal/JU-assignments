package assignmentwo.library03.memberlist;

import assignmentwo.library03.booklist.Book;

import java.util.Arrays;
import java.util.Objects;

/**
 * @author Nikhil
 * @date 27 Jan2020
 */

public class Member {
    private String name;
    private long phone;
    private String email;
    private long id ;
    private int noOfissued;
    private  Book[] listOfIssuedBooks;


    public Member(String name, long phone, String email, long id) {
        this.name = name;
        this.phone = phone;
        this.email = email;
        this.id = id;
        this.noOfissued = 0;
        this.listOfIssuedBooks = new Book[5];
    }
    public Member() {
        this.name = "";
        this.phone = 0;
        this.email = "";
        this.id = 0;
        this.noOfissued = 0;
        this.listOfIssuedBooks = new Book[5];
    }

    public Book[] getListOfIssuedBooks() {
        return listOfIssuedBooks;
    }

    public void setListOfIssuedBooks(Book book) {
        this.listOfIssuedBooks[noOfissued-1] = book;
    }
    public void setListOfIssuedBooks(Book book , int n ) {
        this.listOfIssuedBooks[n] = book;
    }


    @Override
    public String toString() {
        return "Member{" +
                "name='" + name + '\'' +
                ", phone=" + phone +
                ", email='" + email + '\'' +
                ", id=" + id +
                ", noOfissued=" + noOfissued +
                ", listOfIssuedBooks=" + Arrays.toString(listOfIssuedBooks) +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if( o == null){
            return  false;
        }
        if (this == o){
            return true;
        }
        if (this.getClass() == o.getClass()) {
            return false;
        }
        Member member = (Member) o;
        return phone == member.phone &&
                id == member.id &&
                noOfissued == member.noOfissued &&
                Objects.equals(name, member.name) &&
                Objects.equals(email, member.email);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, phone, email, id, noOfissued);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public long getPhone() {
        return phone;
    }

    public void setPhone(long phone) {
        this.phone = phone;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public int getNoOfissued() {
        return noOfissued;
    }

    public void setNoOfissued(int noOfissued) {
        this.noOfissued = noOfissued;
    }
}
   
