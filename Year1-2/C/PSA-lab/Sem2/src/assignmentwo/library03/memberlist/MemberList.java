package assignmentwo.library03.memberlist;

import assignmentwo.library03.booklist.Book;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


class Util{
    private   boolean check ;
    private  Member member;

    Util(boolean b , Member member){
        this.check = b;
        this.member= member;
    }

    public boolean isCheck() {
        return check;
    }

    public Member getMember() {
        return member;
    }

    public void setCheck(boolean check) {
        this.check = check;
    }

    public void setMember(Member member) {
        this.member = member;
    }
}

/**
 * @author Nikhil
 * @date 03 Feb2020
 */


public class MemberList {
    public   Member[] bunchOfMember;
    private static int count ;
    private  static final String IOERROR = "IO Error occurred.";
    private  static final String NEWDETAILS = "Enter new details :- ";


    public  MemberList(int count ){
        bunchOfMember = new Member[count];
    }


    public static int getCount() {
        return count;
    }


    private Util isUnique(long id ){
        int i ;
        for(i = 0 ; i < bunchOfMember.length ; ++i){
                if(bunchOfMember[i] != null &&  bunchOfMember[i].getId() == id ){
                    return  new Util(false, bunchOfMember[i]);
                }
            }
        return  new Util(true, bunchOfMember[i-1]);
    }

    public Util isUnique(Member memb){
        boolean checked = true;
        int i ;
        for(i = 0 ; i < bunchOfMember.length ; ++i){
            if(bunchOfMember[i].equals(memb)){
                checked = false;
                break;
            }
        }
        return  new Util(checked, bunchOfMember[i]);
    }


    public void displayOneMember(){
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.println(NEWDETAILS);
            String str ;
            str = br.readLine();
            long id = Integer.parseInt(str);
            Util u = isUnique(id);
            if(!u.isCheck()){
                System.out.println(u.getMember());
            }else{
                System.out.println("Member not found.");
            }

        }catch (IOException ioError){
            System.out.println(IOERROR);
        }
    }

    public void displayParticularInfoOfMember(){
        System.out.println("Enter member id :- ");
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String idString = br.readLine();
            long id = Long.parseLong(idString);
            Util utilityClassObj = isUnique(id);
            if(!utilityClassObj.isCheck()){
                System.out.println("What do you check.");
                String str = br.readLine();
                if("name".equalsIgnoreCase(str)){
                    System.out.println(utilityClassObj.getMember().getName());
                }else if("phone".equalsIgnoreCase(str)){
                    System.out.println(utilityClassObj.getMember().getPhone());
                }else if("email".equalsIgnoreCase(str)){
                    System.out.println(utilityClassObj.getMember().getEmail());
                }else if("noOfissued".equalsIgnoreCase(str)){
                    System.out.println(utilityClassObj.getMember().getNoOfissued());
                }else{
                    System.out.println("Please enter valid choice.");
                }
            }
        }catch (IOException ioError){
            System.out.println("IO Error occurred");
        }
    }
    public  void displayAll(){
        for(int i = 0 ; i < MemberList.count ; ++i ){
            System.out.println(bunchOfMember[i]);
        }
    }
    private  static  void  updateStatic(){
        MemberList.count++;
    }
    private  static  void  decreaseStatic(){MemberList.count--; }

    public  boolean  addMember(Member membObj){
        try{
            Util utilityClassObj = isUnique(membObj);
            if(utilityClassObj.isCheck()){
                this.bunchOfMember[MemberList.count] = membObj;
                MemberList.updateStatic();
                System.out.println("Book added.");
                return  true;
            }else{
                throw  new IllegalArgumentException("Id unavailable.");
            }
        }catch(IllegalArgumentException illegalArgumentError){
            System.out.println( illegalArgumentError.getMessage());
            return  false;
        }finally {
            MemberList.decreaseStatic(); 
        }
    }

    public void   addMember(){
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Enter Member id :- ");
            String str = br.readLine();
            long memberId = Long.parseLong(str);
            Util utilityClassobj = isUnique(memberId);
            if(utilityClassobj.isCheck()){
                System.out.println("Enter name , email , phone");
                Member newMembObj = new Member();
                newMembObj.setId(Long.parseLong(str));
                newMembObj.setName(br.readLine());
                newMembObj.setEmail(br.readLine());
                newMembObj.setPhone(Long.parseLong(br.readLine()));
                this.bunchOfMember[MemberList.count] = newMembObj;
                MemberList.updateStatic();
                System.out.println("Member added.");
            }else{
                System.out.println("Heya");
                throw  new IllegalArgumentException("Id unavailable.");
            }
        }catch (NumberFormatException numError){
            System.out.println("Please enter data carefully.Member not added.");
        } catch(IllegalArgumentException illegalArgumentError){
            System.out.println( illegalArgumentError.getMessage());
        } catch(IOException ioError  ){
            System.out.println(IOERROR);
        }
    }
    boolean updateName(Member membObj , String name){
        membObj.setName(name);
        return  true;
    }
    boolean updatePhone(Member membObj , String phone){
        long phn = Long.parseLong(phone);
        membObj.setPhone(phn);
        return  true;
    }
    boolean updateEmail(Member membObj, String email){
        membObj.setEmail(email);
        return  true;
    }
    boolean updateNoOfBooksIssued(Member membobj, String noOfBooksIssued ){
        int no  = Integer.parseInt(noOfBooksIssued);
        membobj.setNoOfissued(no);
        return  true;
    }

    boolean updateId(Member membObj , String id){
        long idd = Long.parseLong(id);
        membObj.setId(idd);
        return  true;
    }

    public boolean update(){
        System.out.println("Enter member id :- ");
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int bookId = Integer.parseInt(br.readLine());
            Util utilityClassObj = isUnique(bookId);
            if(!utilityClassObj.isCheck()){
                System.out.println("What do you want to update.");
                String str = br.readLine();
                if("name".equalsIgnoreCase(str)){
                    System.out.println(NEWDETAILS);
                    if(this.updateName(utilityClassObj.getMember() , br.readLine() )){
                        return  true;
                    }
                }else if("email".equalsIgnoreCase(str)){
                    System.out.println(NEWDETAILS);
                    if(this.updateEmail(utilityClassObj.getMember(), br.readLine() )){
                        return  true;
                    }
                }else if("phone".equalsIgnoreCase(str)){
                    System.out.println(NEWDETAILS);
                    if(this.updatePhone(utilityClassObj.getMember() , br.readLine() )){
                        return  true;
                    }
                }else if("id".equalsIgnoreCase(str)){
                    System.out.println(NEWDETAILS);
                    if(this.updateId(utilityClassObj.getMember() , br.readLine())){
                        return  true;
                    }
                }else{
                    System.out.println("Please enter valid choice.");
                    return  false;
                }
            }
        }catch (IOException ioError){
            System.out.println("Action cannot be performed at the moment.");
            return  false;
        }
        return  false;
    }


   public boolean issueBook(Book book , Member member){
       boolean alreadyIssued = false;
      System.out.println(book);
       System.out.println(member);
       if(member.getNoOfissued() <5){
           Book[] list = member.getListOfIssuedBooks();
           for(int l = 0 ; l < member.getNoOfissued(); ++l) {
               if (list[l].getId() == book.getId()) {
                   System.out.println(book);
                   alreadyIssued = true;
               }
           }
       }else{
           System.out.println("Already max. allowable issued.");
           return  false;
       }
       if(alreadyIssued){
           System.out.println("Book already issued to you.");
           return  false;
       }else{
           member.setNoOfissued(member.getNoOfissued() + 1 );
           member.setListOfIssuedBooks(book);
           book.setCount(book.getCount() -1 );
           System.out.println("Book Issued.");
           System.out.println(book);
           System.out.println(member);
           return  true;
       }

   }
   public  boolean returnBook(long bookId, Member member){
       boolean issued = false;
       int k = 0;
       Book[] alreadyIssuedBooks = member.getListOfIssuedBooks();
      // System.out.println(k);
       System.out.println(member.getNoOfissued());
       for(k = 0 ; k < member.getNoOfissued() ; ++k){
           System.out.println(member.getNoOfissued());
           if(alreadyIssuedBooks[k].getId() == bookId){
               issued = true;
               System.out.println(alreadyIssuedBooks[k]);
               System.out.println(member);
               break;
           }
       }
       if(issued){
           alreadyIssuedBooks[k].setCount(alreadyIssuedBooks[k].getCount()+1);
           member.setListOfIssuedBooks(alreadyIssuedBooks[member.getNoOfissued()-1],k);
           member.setNoOfissued(member.getNoOfissued()-1);
           System.out.println("Book Returned.");
           System.out.println(alreadyIssuedBooks[k]);
           System.out.println(member);
           return  true;
       }else{
           System.out.println("Book not issued to you.");
           return  false;
       }
   }
}
   
