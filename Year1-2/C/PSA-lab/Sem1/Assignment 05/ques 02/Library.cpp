#include<iostream>
using std::cin; using std::cout;
using std::istream ; using std::ostream;

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

class Book{
public:
    // Constructor
    Book() {}

    static int bookCount;

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
    int count = 20;
};
int Book::bookCount = 0;
void Book::get_data()
{
    cout<<"Enter Book details(BookId and Serial Number) - \n";
    cin>>*this;
    ++bookCount;
}
ostream & operator<<(ostream &out , Book& b)
{
    out<<b.bookId<<"      "<<b.serial;
    return out;
}
istream & operator>>(istream &in , Book& b)
{
    in>>b.bookId>>b.serial;
    return in;
}
class BookList{
public:

    // Static Member
    Book book[10];

    // Functions
    void enterBooks();
    int find_details(string  );
    void checkAvailability();
};
//Book BookList::book[10];
void BookList::enterBooks()
{
    int i = 0;
    char ch = 'y';
    cout<<"Enter n to stop entering data.\n";
    do{
        Book temp;
        temp.get_data();
        book[i] = temp;
        i++;
        cout<<"More? ";
        cin>>ch;
    }while(ch!='n');
}
int BookList::find_details(string  x)
{
    for(int i = 0 ; i<Book::bookCount ; ++i){
        if(book[i].returnSerial() == x)
            return i;
    }
    return EXIT_FAILURE;
}
void BookList::checkAvailability()
{
    string x;
    cout<<"Enter books serial number \n";
    cin>>x;
    for(auto i = 0  ; i< Book::bookCount;++i )
    {

        if(x == book[i].returnSerial())
        {
            if(book[i].returnCount()>0)
            {
                cout<<"Book Available\n ";
                return ;
            }
            else{
                cout<<"Book present in library but currently unavailable.";
                return;
            }
        }
    }
    cout<<"No such book in Library.\n";
    return ;

}
class Member {
public:

    //Constructor
    Member() {}

    //Friends
    friend ostream & operator<<(ostream & , Member& );
    friend istream & operator>>(istream & , Member& );

    //Functions
    const long int& returnMemberId() {return memberId;}

protected:

    long int memberId = 0 ;
    string name = " ";
  /*  string email = " ";
    string address = " ";*/
};
ostream & operator<<(ostream &out , Member& m)
{
    out<<m.memberId<<"     "<<m.name;
    return out;
}
istream & operator>>(istream &in , Member& m)
{
    in>>m.memberId>>m.name;
    return in;
}
class Transaction{

public:

    //Constructor
    Transaction() : b() {}

    //Functions
    static int transactionCount;
    void update_transaction(Book& , bool);
    void showTransaction();
    int returnTransactionCount() {return transactionCount;}
    bool returnReturned() {return returned;}
    Book& returnBook() {return b;}

protected:

    Book b;
    bool returned = true;
};
int Transaction::transactionCount = 0;
void Transaction::showTransaction()
{
    cout<<b<<"         ";
    cout<<std::boolalpha<<returned<<std::noboolalpha<<endl;
}
void Transaction::update_transaction(Book &book , bool w)
{
    b = book;
    returned = w;
    if(w) // return
    {
        --transactionCount;
    }
    else{ // false (issue)
        ++transactionCount;
    }

}
class Student : public Member{
public:

    //Constructors
    Student() : Member() , t() {}

    // Static members
    static int studentCount;

    //Functions
    void get_data();
    bool check_issued(string );
    void showStudentTransaction();
    int& returnCount(){return count;}

    //Friendship

    Transaction t[10] ;
private:
    int count = 0;
};
int Student::studentCount = 0;
bool Student::check_issued(string serialNo){
for(auto i = 0 ; i< Transaction::transactionCount ;++i)
{
    if(t[i].returnBook().returnSerial() == serialNo){
            cout<<t[i].returnBook().returnSerial()<<endl;
        return true;}
}
return false;
}
void Student::showStudentTransaction()
{
    if(Transaction::transactionCount==0){
        cout<<"You haven't issued any book yet.\n";
        return;
    }
    for(auto i = 0 ; i < Transaction::transactionCount ; ++i){
        cout<<"BookId SerialNo Status\n";
        t[i].showTransaction();}
}
void Student::get_data(){
    cout<<"Enter Student details(MemberId and Name) - \n";
    cin>>*this;
    ++studentCount;
}
class StudentList{
public:

   // friend class MemberList;
    Student student[10];
    void issueBook(long int, int ,BookList &);
    void returnBook(long int, int , BookList & );
public:
    StudentList() {}
    void enterStudents();
    void showStudent(int );
};
void StudentList::showStudent(int i)
{
    student[i].showStudentTransaction();
}
void StudentList::enterStudents()
    {
        int i = 0;
        char ch = 'y';
        cout<<"Enter n to stop entering data.\n";
        do{
            Student temp;
            temp.get_data();
            student[i] = temp;
            i++;
            cout<<"More? ";
            cin>>ch;
        }while(ch!='n');
    }
void StudentList::issueBook(long int id, int i ,BookList &bl)
{
  //  cout<<i<<endl<<endl<<endl;
    if(student[i].returnCount()>=2)
     {
         cout<<"You have exceeded the limit for issuing book per person .\n";
         return ;
     }
    id = id;
    long int x;
    string y;
    cout<<"Enter Book id and Serial ";
    cin>>x;
    cin>>y;
    if(student[i].check_issued(y))
    {
        cout<<"Book already issued to you.\n";
        return;
    }
    int j;
    for(j=0;j<Book::bookCount;++j)
    {
        if(x ==int(bl.book[j].returnBookId()) && y == bl.book[j].returnSerial()) // To check if present
        {
            if(bl.book[j].returnCount()>0) // To check availability.
            {
                     student[i].returnCount()++;
                     bl.book[j].returnCount()--;
                     student[i].t[Transaction::transactionCount].update_transaction(bl.book[j],false);
                     cout<<"You can take your book.\n";
                     return ;
            }
        }
    }
    cout<<"Book unavailable.\n";
}
void StudentList::returnBook(long int id,int i, BookList & bl )
{
    id = id;
    string  x;
    cout<<"Enter serial no. of book - ";
    cin>>x;

    if(student[i].check_issued(x))
    {
        student[i].returnCount()--;
        int bn = bl.find_details(x);
        bl.book[bn].returnCount()++;
        student[i].t[Transaction::transactionCount].update_transaction(bl.book[bn],true);
        cout<<"Book returned.\n";
         return ;
    }
    else{
        cout<<"Book was not issued to you.\n";
    }
}
class Faculty : public Member{
public:

    //Constructors
    Faculty() : Member() , t() {}

    // Static members
    static int facultyCount;

    //Functions
    void get_data();
    bool check_issued(string );
    void showFacultyTransaction();
    //Friendship

    Transaction t[10] ;
    int& returnCount() {return count;}
private:
    int count = 0;
};
int Faculty::facultyCount = 0;
bool Faculty::check_issued(string serialNo){
    for(auto i = 0 ; i< Transaction::transactionCount ;++i)
    {
        if(t[i].returnBook().returnSerial() == serialNo)
            return true;
    }
    return EXIT_FAILURE;
}
void Faculty::showFacultyTransaction()
{
    for(auto i = 0 ; i < Transaction::transactionCount ; ++i)
        t[i].showTransaction();
}
void Faculty::get_data(){
    cout<<"Enter Faculty details(MemberId and Name) - \n";
    cin>>*this;
    ++facultyCount;
}
class FacultyList{
public:

    FacultyList()  {}
    void enterFaculty();
    void showFaculty(int );
    void issueBook(long int,int,BookList &);
    void returnBook(long int ,int,BookList &  );
public:
    Faculty faculty[10];

};
void FacultyList::enterFaculty()
{
    int i = 0;
    char ch = 'y';
    cout<<"Enter n to stop entering data.\n";
    do{
        Faculty temp;
        temp.get_data();
        faculty[i] = temp;
        i++;
        cout<<"More? ";
        cin>>ch;
    }while(ch!='n');
}
void FacultyList::showFaculty(int i)
{
    faculty[i].showFacultyTransaction();
}
void FacultyList::issueBook(long int id, int i ,BookList &bl)
{
    if(faculty[i].returnCount()>=2)
     {
         cout<<"You have exceeded the limit for issuing book per person .\n";
         return ;
     }
    id = id;
    long int x;
    string y;
    cout<<"Enter Book id and Serial ";
    cin>>x;
    cin>>y;
    if(faculty[i].check_issued(y))
    {
        cout<<"Book already issued to you.\n";
        return;
    }
    for(i=0;i<Book::bookCount;i++)
    {
        if(x ==int(bl.book[i].returnBookId()) && y == bl.book[i].returnSerial()) // To check if present
        {
            if(bl.book[i].returnCount()>0) // To check availability.
            {
                     faculty[i].returnCount()++;
                     bl.book[i].returnCount()--;
                     faculty[i].t[Transaction::transactionCount].update_transaction(bl.book[i],false);
                     cout<<"You can take your book.\n";
                     return ;
            }
        }
    }
    cout<<"Book unavailable.\n";
}
void FacultyList::returnBook(long int id,int i, BookList & bl )
{
    id = id;
    string  x;
    cout<<"Enter serial no. of book - ";
    cin>>x;
    if(faculty[i].check_issued(x))
    {
        faculty[i].returnCount()--;
        int bn = bl.find_details(x);
        bl.book[bn].returnCount()++;
        faculty[i].t[Transaction::transactionCount].update_transaction(bl.book[bn],true);
        cout<<"Book returned.\n";
         return ;
    }
    else{
        cout<<"Book was not issued to you.\n";
    }
}
class MemberList{
public:
    MemberList() : f() , s(){}
    FacultyList f;
    StudentList s;
    tuple<long int,int,int> verifyMember();
    void issueRequest(BookList &);
    void returnRequest(BookList &);
    void enterMember();
    void showMemberDetails();
};
void MemberList::enterMember()
{
    cout<<"Enter 's' for student 'f' for faculty.\n";
    char ch;
    cin>>ch;
    if(ch == 's')
        s.enterStudents();
    if(ch == 'f')
        f.enterFaculty();
}
void MemberList::showMemberDetails()
{
    auto tupled = verifyMember();
    if(std::get<2>(tupled) ==1 )
    {
        s.showStudent(std::get<1>(tupled));
    }
    if(std::get<2>(tupled) ==2)
    {
        f.showFaculty(std::get<1>(tupled));
    }
    if(std::get<2>(tupled) == 0)
        cout<<"Error verifying details.\n";
}
tuple<long int,int,int> MemberList::verifyMember() // id , location , present
{
    int i,choice;
    long int id;
    cout<<"Enter 0 if you are Student or 1 if you are Faculty.\n";
    cin>>choice;
    if(!choice)
    {
        cout<<"Enter your student id ";
        cin>>id;
        for(i=0;i<Student::studentCount;++i)
        {
            if(s.student[i].returnMemberId() == id){
                return std::make_tuple(id,i,1);
                }
        }
    }
    if(choice)
    {
        cout<<"Enter your faculty id - ";
        cin>>id;
        for(i=0;i<Student::studentCount;++i)
        {
            if(f.faculty[i].returnMemberId() == id){

                return std::make_tuple(id,i,2);;
            }
        }
    }
    return std::make_tuple(id,-1,0);
}
void MemberList::issueRequest(BookList &bl)
{
    auto tupled = verifyMember();
    if(std::get<2>(tupled) ==1 )
    {
        s.issueBook(std::get<0>(tupled),std::get<1>(tupled),bl);
    }
    if(std::get<2>(tupled) ==2)
    {
        f.issueBook(std::get<0>(tupled),std::get<1>(tupled),bl);
    }
    if(std::get<2>(tupled) == 0)
        cout<<"Error verifying details.\n";
}
void MemberList::returnRequest(BookList &bl)
{
    auto tupled = verifyMember();
    if(std::get<2>(tupled) ==1 )
    {
        if(s.student[std::get<1>(tupled)].returnCount()==0){
        cout<<"You haven't issued any book yet.\n";
        return ;
        }
        s.returnBook(std::get<0>(tupled),std::get<1>(tupled),bl);
    }
    if(std::get<2>(tupled) ==2)
    {
        if(f.faculty[std::get<1>(tupled)].returnCount()==0){
        cout<<"You haven't issued any book yet.\n";
        return ;
        }
        f.returnBook(std::get<0>(tupled),std::get<1>(tupled),bl);
    }
    if(std::get<2>(tupled) == 0)
        cout<<"Error verifying details.\n";
}
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
                case 4:ml.issueRequest(bl);
                       break;
                case 5:ml.returnRequest(bl);
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
int main()
{
    Menu m;
    m.printMenu();
    return 0;
}
