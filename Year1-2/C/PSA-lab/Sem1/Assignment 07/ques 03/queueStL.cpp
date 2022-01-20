#include<iostream>
using std::cin; using std::cout;
using std::istream ; using std::ostream;

#include<vector>
using std::vector; using std::endl;

#include<queue>
using std::queue;

#include<string>
using std::string;

class Student{
public:

    // Constructor
    Student(): name(" "),roll(0),score(0) {}
    Student(const Student& s): name(s.name),roll(s.roll),score(s.score) {}
    Student(const string&s , int &r): name(s),roll(r),score(0) {}

    // Friend overloaded
    friend ostream & operator<<(ostream & , Student& );
    friend istream & operator>>(istream & , Student& );

    // Functions
    void get_data();
    const int& returnRoll(){return roll;}
    const string& returnName(){return name;}
    const int& returnScore(){return score;}
    void printMarksheet();

private:
    std::string name;
    int roll;
    int score;
 //   int marks[5] = {1,1,1,1,1};
    vector<int>marks{1,1,1,1,1};
};
ostream & operator<<(ostream &out , Student& s)
{
    out<<s.roll<<" "<<s.name<<" "<<s.score;
    return out;
}
istream & operator>>(istream &in , Student& s)
{
    in>>s.roll>>s.name>>s.score;
    return in;
}
void Student::get_data()
{
    cout<<"Enter student details - \n";
    cin>>*this;
}
void Student::printMarksheet()
{
    cout<<*this<<endl;
    int  j =1 ;
    for(auto i : this->marks)
    {
        cout<<"Subject "<<j<<"   "<<i <<endl;
        ++j;
    }
}
class StudentList{
public:

    // Constructor
    StudentList() : sl() {}

    queue<Student,vector<Student>>sl;

    // Functions
    void enter_students();
    void remove_student();
    void show_student();
    void requestMarksheet();
};
void StudentList::requestMarksheet()
{
    auto i = sl.front();
    i.printMarksheet();
    sl.front();
}
void StudentList::enter_students()
{
    char ch = 'y';
    do{
        Student temp;
        temp.get_data();
        sl.push(temp);
        cout<<"More? ";
        cin>>ch;
    }while(ch!='n');
}
void StudentList::remove_student()
{
    if(!sl.empty())
    {
        sl.front();
        return;
    }
    cout<<"Underflow\n";
}
void StudentList::show_student()
{
    if(!sl.empty())
    {
        cout<<sl.front();
        return ;
    }
    cout<<"Underflow\n";
}
int main()
{
    StudentList sl;
    cout<<"Enter n to stop entering data.\n";
    sl.enter_students();
    sl.remove_student();
    cout<<"Student details\n";
    sl.show_student();
    cout<<"\nStudent Mark sheet \n";
    sl.requestMarksheet();
    return 0;
}
