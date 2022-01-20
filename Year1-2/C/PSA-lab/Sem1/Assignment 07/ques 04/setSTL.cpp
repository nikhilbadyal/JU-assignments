#include<iostream>
using std::cin; using std::cout;
using std::istream ; using std::ostream;

#include<vector>
using std::vector; using std::endl;

#include<set>
using std::set;

#include<string>
using std::string;

class Student{
public:

    // Constructor
    Student():roll(0),score(0) {}
    Student( int &r): roll(r),score(0) {}

    // Friend overloaded
    friend ostream & operator<<(ostream & , const Student& );
    friend istream & operator>>(istream & ,  Student& );

    // Functions
    void get_data();
    const int& returnRoll()const {return roll;}
    const int& returnScore()const {return score;}

private:
    int roll;
    int score;
};
ostream & operator<<(ostream &out ,const Student& s)
{
    out<<s.roll<<" "<<s.score;
    return out;
}
istream & operator>>(istream &in ,Student& s)
{
    in>>s.roll>>s.score;
    return in;
}
void Student::get_data()
{
    cout<<"Enter student details - \n";
    cin>>*this;
}
struct StudentCmp {
    bool operator()(const Student& lhs,const  Student& rhs) const  {
        return lhs.returnScore()>rhs.returnScore();
    }
};
class StudentList{
public:

    // Constructor
    StudentList() : student() {}
    struct compare{
        bool operator()(Student & s1 ,  Student & s2){
        return s1.returnScore()>s2.returnScore();}
    };

    std::set<Student, StudentCmp> student;

    // Functions
    void enter_students()
    {
        char ch = 'y';
        cout<<"Enter n to stop entering data.\n";
        do{
            Student q;
            q.get_data();
            student.insert(q);
            cout<<"More? ";
            cin>>ch;
        }while(ch!='n');
    }

    void show_all_students()
    {  /*for( auto i : student)
            cout<<i<<endl;*/

         std::set<Student>::iterator itr = student.begin();
        while(itr != student.end())
            cout<<*itr<<endl;
    }
};
int main()
{
    StudentList sl;
    sl.enter_students();
    sl.show_all_students();
    return 0;
}
