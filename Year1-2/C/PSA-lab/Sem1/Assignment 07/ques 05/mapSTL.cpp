#include<iostream>
using std::cin; using std::cout;
using std::istream ; using std::ostream;

#include<vector>
using std::vector; using std::endl;

#include<map>
using std::map;

#include<string>
using std::string;

class Student{
public:

    // Constructor
    Student():roll(0),score(0) {}
    Student( int &r): roll(r),score(0) {}

    // Friend overloaded
    friend ostream & operator<<(ostream & , Student& );
    friend istream & operator>>(istream & , Student& );

    // Functions
    void get_data();
    const int& returnRoll(){return roll;}
    const int& returnScore(){return score;}

private:
    int roll;
    int score;
};
ostream & operator<<(ostream &out , Student& s)
{
    out<<s.roll<<" "<<s.score;
    return out;
}
istream & operator>>(istream &in , Student& s)
{
    in>>s.roll>>s.score;
    return in;
}
void Student::get_data()
{
    cout<<"Enter student details - \n";
    cin>>*this;
}
class StudentList{
public:

    // Constructor
    StudentList() : student() {}
    struct compare{
        bool operator()(const int & i1 , const int & i2){
        return i1<i2;}
    };

    map<int,int,compare>student;

    // Functions
    void enter_students()
    {
        char ch = 'y';
        cout<<"Enter n to stop entering data.\n";
        do{
            Student temp;
            temp.get_data();
            student.insert({temp.returnRoll(),temp.returnScore()});
            cout<<"More? ";
            cin>>ch;
        }while(ch!='n');
    }
    void show_all_students()
    {
        auto itr = student.begin();
        while(itr!=student.end()){
            cout<<itr->first<<"  "<<itr->second<<endl;
            ++itr;}
    }
    void show_student(int roll )
    {
        cout<<"Marks secured by student is - "<<student[roll];
    }
};
int main()
{
    StudentList sl;
    sl.enter_students();
    sl.show_all_students();
    sl.show_student(11);
    return 0;
}
