#include<iostream>
using std::cin; using std::cout;
using std::istream ; using std::ostream;


#include<fstream>
using std::ifstream ; using std::ofstream;

#include<fstream>
using std::fstream; using std::wfstream;

#include<vector>
using std::vector; using std::endl;

#include<algorithm>
using std::find_if; using std::max_element;

#include<string>
using std::string;

#include<utility>
using std::pair;

#include<tuple>
using std::tuple;

#include<ios>
using std::ios;

#include<functional>
using std::ref;
std::iostream::pos_type find_details(string  );


class Book{
public:
    // Constructor
    Book() {}

    int count =0  ;

    //Friends
    friend ostream & operator<<(ostream & , Book& );
    friend istream & operator>>(istream & , Book& );


    //Functions
    void get_data();
    const long int& returnBookId() {return bookId;}
    int& returnCount() {return count;}
    const string& returnSerial() {return serial;}

protected:
    long int bookId = 0 ;
    string serial = " ";
  /*  string title = " ";
    string author = " ";
    string publisher = " ";
    int price = 0;*/

};

class BookList{
public:
    BookList()  {};

    // Functions
    void enterBooks();
    void checkAvailability();
};


class Member {
public:

    //Constructor
    Member() : memberId(), name() , count(){}



    //Friends
    friend ostream & operator<<(ostream & , Member& );
    friend istream & operator>>(istream & , Member& );

    //Functions
    const long int& returnMemberId() {return memberId;}
    const string & returnName() {return name;}
    int & returnCount() {return count;}

protected:

    long int memberId = 0 ;
    string name = " ";
    int count ;

  /*  string email = " ";
    string address = " ";*/
};


class Transaction{

public:

    //Constructor
    Transaction() : book() {}

    //Functions
    bool returnReturned() {return returned;}
    Book& returnBook() {return book;}

    //Friends
    friend istream  & operator>>(istream & , Transaction &);
    friend ostream  & operator<<(ostream & , Transaction &);
    friend class TransactionList;

private:

    Book book;
    bool returned = true;
};


class TransactionList{

public:
    void update_transaction(string , Book& , bool);
    void showTransaction(string );
    bool check_issued(string ,string );
};


class Student : public Member{
public:

    //Constructors
    Student() : Member() , tl() {}


    //Functions
    void get_data();
    bool check_issued(string , string  );
    void showStudentTransaction();

    //Friendship

  //  Transaction t[10] ;
      TransactionList tl;
private:

};

class StudentList{
public:

    void issueBook(std::iostream::pos_type);
    void returnBook(std::iostream::pos_type);
public:
    StudentList() {};
    void enterStudents();
    void showStudent(std::iostream::pos_type );
};

class Faculty : public Member{
public:

    //Constructors
    Faculty() : Member() ,tl()  {}

    // Static members
    static int facultyCount;

    //Functions
    void get_data();
    bool check_issued(string, string  );
    void showFacultyTransaction();


    TransactionList tl;
private:
};

class FacultyList{
public:

    FacultyList()   {};
    void enterFaculty();
    void showFaculty( std::iostream::pos_type );
    void issueBook(std::iostream::pos_type);
    void returnBook(std::iostream::pos_type);
public:


};


class MemberList{
public:
    MemberList() : f() , s(){}
    FacultyList f;
    StudentList s;
    tuple<std::iostream::pos_type,int> verifyMember();
    void issueRequest();
    void returnRequest();
    void enterMember();
    void showMemberDetails();
};


struct Menu
{
    int ch;
    void printMenu()
    {
        MemberList ml;
        BookList bl;
        while(1)
        {
            cout<<"\n\n";
            cout<<"\n1.Add books";
            cout<<"\n2.Add member";
            cout<<"\n3.Check book availability";
            cout<<"\n4.Make an issue request";
            cout<<"\n5.Make an issue Return request";
            cout<<"\n6.Show  member detail.";
            cout<<"\nYour choice : ";
            cin>>ch;
            switch(ch)
            {
                case 1:bl.enterBooks();
                       break;
                case 2: ml.enterMember();
                       break;
                case 3:bl.checkAvailability();
                       break;
                case 4:ml.issueRequest();
                       break;
                case 5:ml.returnRequest();
                       break;
                case 6:ml.showMemberDetails();
                        break;
                case 7: exit(0);
                default:cout<<"Wrong choice ";
                          break;
            }
        }
    }
};


