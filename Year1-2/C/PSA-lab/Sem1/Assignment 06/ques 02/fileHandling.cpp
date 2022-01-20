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
    string title = " ";
    string author = " ";
    string publisher = " ";
    int price = 0;
    int count =0  ;

};
void Book::get_data()
{
    cout<<"Enter Book details(BookId,Serial Number,count of copies,title,author,publisher,price) - \n";
    cin>>*this;
}
ostream & operator<<(ostream &out , Book& b)
{
    out<<b.bookId<<"  "<<b.serial<<"  "<<b.count<<"  "<<b.title<<"  "<<b.author<<" "<<b.publisher<<"  "<<b.price;
    return out;
}
istream & operator>>(istream &in , Book& b)
{
    in>>b.bookId>>b.serial>>b.count>>b.title>>b.author>>b.publisher>>b.price;
    return in;
}
class BookList{
public:
    BookList()  {};

    // Functions
    void enterBooks();
    void checkAvailability();
};
//Book BookList::book[10];
void BookList::enterBooks()
{
    ofstream writeBook;
    int i = 0;
    char ch = 'y';
    cout<<"Enter n to stop entering data.\n";
    writeBook.open("Booklist.txt",ofstream::app);
    do{
        Book temp;
        temp.get_data();
        writeBook<<temp<<endl;
        i++;
        cout<<"More? ";
        cin>>ch;
    }while(ch!='n');
    writeBook.close();
}
std::iostream::pos_type find_details(string  x)
{
    ifstream readBook;
    readBook.open("Booklist.txt",ios::binary);
    Book temp;
    auto old_pos = readBook.tellg();
    while(readBook>>temp){
        if(temp.returnSerial() == x){
            auto new_pos = old_pos;
            return new_pos;
        }
        old_pos = readBook.tellg();
    }

    return EXIT_FAILURE;
}
void BookList::checkAvailability()
{
    ifstream readBook;
    ofstream writeBook;
    string x;
    cout<<"Enter books serial number \n";
    cin>>x;
    Book temp;
    readBook.open("Booklist.txt",ios::binary);
    while(readBook>>temp){
        if(x == temp.returnSerial())
        {
            if(temp.returnCount()>0)
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
    readBook.close();
    cout<<"No such book in Library.\n";
    return ;
}
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
ostream & operator<<(ostream &out , Member& m)
{
    out<<m.memberId<<"  "<<m.name<<"  "<<m.count; // Lets see
    return out;
}
istream & operator>>(istream &in , Member& m)
{
    in>>m.memberId>>m.name>>m.count;
    return in;
}
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
ostream  & operator<<(ostream &out , Transaction &t)
{
    out<<t.book<<"  "<<t.returned;
    return out;

}
istream  & operator>>(istream &in, Transaction & t)
{
    in>>t.book>>t.returned;
    return in;
}
class TransactionList{

public:
    void update_transaction(string , Book& , bool);
    void showTransaction(string );
    bool check_issued(string ,string );
};
bool TransactionList::check_issued(string name,string s)
{
    ifstream readTransaction;
    readTransaction.open(name+".txt",ios::binary);
    Transaction temp1;
    while(readTransaction>>temp1)
    {
        if(temp1.book.returnSerial() == s)
        {
            return true;
        }
    }
    return false;
}
void TransactionList::showTransaction(string name)
{
    ifstream readTransaction;
    readTransaction.open(name+".txt",ios::binary);
    Transaction temp1;
    while(readTransaction>>temp1)
    {
        cout<<std::boolalpha<<temp1<<std::noboolalpha<<endl;
    }
}
void TransactionList::update_transaction(string name ,Book &book , bool w)
{
    Transaction temp;
    temp.book = book;
    temp.returned = w;
    ifstream readTransaction;
    ofstream writeTransaction;

    if(w) // return
    {
        readTransaction.open(name+".txt",ios::binary);
        Transaction temp1;
        auto old_pos = readTransaction.tellg();
        auto new_pos = old_pos;
        while(readTransaction>>temp1)
        {
            if(temp1.book.returnSerial() == temp.book.returnSerial())
            {
                writeTransaction.open(name+".txt",ofstream::in|ofstream::out);
                new_pos = old_pos;
                writeTransaction.seekp(new_pos);
                if(new_pos == 0)
                {
                    writeTransaction<<temp;
                }
                else{writeTransaction<<endl<<temp;}

                break;
            }
            old_pos = readTransaction.tellg();
        }
    }
    else{
        writeTransaction.open(name+".txt",ofstream::in | ofstream::out);
        writeTransaction<<temp<<endl;
    }
}
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
bool Student::check_issued(string name1, string serialNo){
    return tl.check_issued(name1,serialNo);
}
void Student::showStudentTransaction()
{
    if(Student::count==0){
        cout<<"You haven't issued any book yet.\n";
        return;
    }
    tl.showTransaction(this->name);
}
void Student::get_data(){
    cout<<"Enter Student details(MemberId and Name and count) - \n";
    cin>>*this;
}
class StudentList{
public:

    void issueBook(std::iostream::pos_type);
    void returnBook(std::iostream::pos_type);
public:
    StudentList() {};
    void enterStudents();
    void showStudent(std::iostream::pos_type );
};
void StudentList::showStudent( std::iostream::pos_type position)
{
    ifstream readStudent;
    readStudent.open("Studentlist.txt",ios::binary);
    readStudent.seekg(position);
    Student temp;
    readStudent>>temp;
    cout<<"Student details \n";
    cout<<temp<<endl;
    cout<<"Student Library details \n";
    temp.tl.showTransaction(temp.returnName());
}
void StudentList::enterStudents()
{
    ofstream writeStudent;
    int i = 0;
    char ch = 'y';
    writeStudent.open("Studentlist.txt",ofstream::app);
    cout<<"Enter n to stop entering data.\n";
    do{
        Student temp;
        temp.get_data();
        writeStudent<<temp<<endl;
        i++;
        cout<<"More? ";
        cin>>ch;
    }while(ch!='n');
    writeStudent.close();
}
void StudentList::issueBook(std::iostream::pos_type position)
{
    ifstream readBook;
    ifstream readStudent;
    ofstream writeStudent;
    ofstream writeBook;
    readStudent.open("StudentList.txt",ios::binary);
    readStudent.seekg(position);
    Student s;
    readStudent>>s;
    if(s.returnCount()>=2)
     {
         cout<<"You have exceeded the limit for issuing book per person .\n";
         return ;
     }
    readStudent.close();
    long int x;
    string y;
    cout<<"Enter Book id and Serial ";
    cin>>x;
    cin>>y;
    if(s.check_issued(s.returnName(),y))
    {
        cout<<"Book already issued to you.\n";
        return;
    }
    readBook.open("Booklist.txt",ios::binary);
    Book temp;
    auto old_pos = readBook.tellg();
    while(readBook>>temp)    {
        if(x ==int(temp.returnBookId()) && y == temp.returnSerial()) // To check if present
        {
            if(temp.returnCount()>0) // To check availability.
            {
                     s.returnCount()++;
                     cout<<s.returnCount()<<endl;
                     cout<<s<<endl;
                     writeStudent.open("StudentList.txt",ofstream::in| ofstream::out);
                     writeStudent.seekp(position);
                     if(position == 0)
                     {
                        // cout<<s<<endl;
                         writeStudent<<s;
                     }
                     else{
                        writeStudent<<endl<<s;
                     }
                     temp.returnCount()--;
                     writeBook.open("Booklist.txt",ofstream::in| ofstream::out);
                     writeBook.seekp(old_pos);
                     if(old_pos == 0)
                     {
                         writeBook<<temp<<" ";
                     }
                     else{
                        writeBook<<endl<<temp<<" ";
                     }
                     s.tl.update_transaction(s.returnName(),temp,false);
                     cout<<"You can take your book.\n";
                     return ;
            }
        }
        old_pos = readBook.tellg();
    }
    readBook.close();

    cout<<"Book unavailable.\n";
}
void StudentList::returnBook(std::iostream::pos_type position )
{
    ifstream readBook;
    ifstream readStudent;
    ofstream writeStudent;
    ofstream writeBook;
    readStudent.open("Studentlist.txt",ios::binary);
    readStudent.seekg(position);
    Student s;
    readStudent>>s;
    if(s.returnCount()==0)
    {
        cout<<"You haven't issued any book yet.\n";
    }
    string  x;
    cout<<"Enter serial no. of book - ";
    cin>>x;

    if(s.check_issued(s.returnName(),x))
    {
        Book temp;
        readBook.open("Booklist.txt",ios::binary);
        auto new_pos = find_details(x);
        readBook.seekg(new_pos);
        readBook>>temp;
        s.tl.update_transaction(s.returnName(),temp,true);
        s.returnCount()--;
        writeStudent.open("Studentlist.txt",ofstream::in| ofstream::out);
        writeStudent.seekp(position);
        if(position == 0)
        {
            writeStudent<<s;
        }
        else{
                writeStudent<<endl<<s;
        }
        temp.returnCount()++;
        writeBook.open("Booklist.txt",ofstream::in| ofstream::out);
        writeStudent.seekp(new_pos);
        if(new_pos == 0)
        {
            writeBook<<temp;
        }
        else{
            writeBook<<endl<<temp;
        }
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
int Faculty::facultyCount = 0;
bool Faculty::check_issued(string name1 ,  string serialNo){
    return tl.check_issued(name1, serialNo);
}
void Faculty::showFacultyTransaction()
{
    tl.showTransaction(this->name);
}
void Faculty::get_data(){
    cout<<"Enter Faculty details(MemberId and Name) - \n";
    cin>>*this;
    ++facultyCount;
}
class FacultyList{
public:

    FacultyList()   {};
    void enterFaculty();
    void showFaculty( std::iostream::pos_type );
    void issueBook(std::iostream::pos_type);
    void returnBook(std::iostream::pos_type);
public:


};
void FacultyList::enterFaculty()
{
    int i = 0;
    char ch = 'y';
    ofstream writeFaculty;

    writeFaculty.open("Facultylist.txt",ios::binary);
    cout<<"Enter n to stop entering data.\n";
    do{
        Faculty temp;
        temp.get_data();
        writeFaculty<<temp<<endl;
        i++;
        cout<<"More? ";
        cin>>ch;
    }while(ch!='n');
}
void FacultyList::showFaculty(std::iostream::pos_type position)
{
    ifstream readFaculty;
    readFaculty.open("Facultylist.txt",ios::binary);
    readFaculty.seekg(position);
    Faculty temp;
    readFaculty>>temp;
    cout<<temp<<endl;
    temp.tl.showTransaction(temp.returnName());

}
void FacultyList::issueBook(std::iostream::pos_type position )
{
    ifstream readFaculty;
    ifstream readBook;

    readFaculty.open("Facultylist.txt",ios::binary);
    readFaculty.seekg(position);
    Faculty f;
    readFaculty>>f;
    if(f.returnCount()>=2)
     {
         cout<<"You have exceeded the limit for issuing book per person .\n";
         return ;
     }
    long int x;
    string y;
    cout<<"Enter Book id and Serial ";
    cin>>x;
    cin>>y;
    if(f.check_issued(f.returnName(),y))
    {
        cout<<"Book already issued to you.\n";
        return;
    }
    Book temp;
    readBook.open("Booklist.txt",ios::binary);
    while(readBook>>temp)
    {
        if(x ==int(temp.returnBookId()) && y == temp.returnSerial()) // To check if present
        {
            if(temp.returnCount()>0) // To check availability.
            {
                     f.returnCount()++;
                     temp.returnCount()--;
                     f.tl.update_transaction(f.returnName(),temp,false);
                     cout<<"You can take your book.\n";
                     return ;
            }
        }
    }
    cout<<"Book unavailable.\n";
}
void FacultyList::returnBook(std::iostream::pos_type position )
{
    ifstream readBook;
    ifstream readFaculty;
    readFaculty.open("Facultylist.txt",ios::binary);
    readFaculty.seekg(position);
    Faculty f;
    readFaculty>>f;
    if(f.returnCount()==0)
    {
        cout<<"You haven't issued any book yet.\n";
    }
    string  x;
    cout<<"Enter serial no. of book - ";
    cin>>x;
    readBook.open("Booklist.txt",ios::binary);
    Book temp;
    if(f.check_issued(f.returnName(),x))
    {
        f.returnCount()--;
        BookList bl;
        auto position1 = find_details(x);
        readBook.seekg(position1);
        temp.returnCount()++;
        f.tl.update_transaction(f.returnName(),temp,false);
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
    tuple<std::iostream::pos_type,int> verifyMember();
    void issueRequest();
    void returnRequest();
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
    if(std::get<1>(tupled) ==1 )
    {
        s.showStudent(std::get<0>(tupled));
    }
    if(std::get<1>(tupled) ==2)
    {
        f.showFaculty(std::get<0>(tupled));
    }
    if(std::get<1>(tupled) == 0)
        cout<<"Error verifying details.\n";
}
tuple<std::istream::pos_type,int> MemberList::verifyMember() // id , location , present
{
    int choice;
    long int id;

    cout<<"Enter 0 if you are Student or 1 if you are Faculty.\n";
    cin>>choice;
    if(!choice)
    {
        ifstream read;
        ofstream write;
        cout<<"Enter your student id ";
        cin>>id;
        Student temp;
        read.open("Studentlist.txt",ios::binary);
        auto old_pos = read.tellg();
        while(read>>temp){
            if(temp.returnMemberId() == id)
            {
                auto new_pos = old_pos;
                return std::make_tuple(new_pos,1);
            }
            old_pos = read.tellg();
        }
    }
    if(choice)
    {
        ifstream read;
        ofstream write;
        cout<<"Enter your faculty id - ";
        cin>>id;
        Faculty temp;
        read.open("Facultylist.txt",ios::binary);
        auto old_pos = read.tellg();
        while(read>>temp){
            if(temp.returnMemberId() == id)
            {
                auto new_pos = old_pos;
                return std::make_tuple(new_pos,1);
            }
            old_pos = read.tellg();
        }
    }
    ifstream read;
    ofstream write;
    auto pos = read.tellg();
    return std::make_tuple(pos,0);
}
void MemberList::issueRequest()
{
    auto tupled = verifyMember();
    if(std::get<1>(tupled) ==1 )
    {
        s.issueBook(std::get<0>(tupled));
    }
    if(std::get<1>(tupled) ==2)
    {
        f.issueBook(std::get<0>(tupled));
    }
    if(std::get<1>(tupled) == 0)
        cout<<"Error verifying details.\n";
}
void MemberList::returnRequest()
{
    auto tupled = verifyMember();
    if(std::get<1>(tupled) ==1 )
    {
        s.returnBook(std::get<0>(tupled));
    }
    if(std::get<1>(tupled) ==2)
    {
        f.returnBook(std::get<0>(tupled));
    }
    if(std::get<1>(tupled) == 0)
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
int main()
{
    Menu m;
    m.printMenu();
    return 0;
}
