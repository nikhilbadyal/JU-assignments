#include<iostream>
using std::cin; using std::cout;
using std::istream ; using std::ostream;

#include<vector>
using std::vector; using std::endl;

#include<algorithm>
using std::find_if; using std::max_element;

#include<stack>
using std::stack;


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

private:
    std::string name;
    int roll;
    int score;
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
class StudentList{
public:

    // Constructor
    StudentList() : sl() {}


    std::vector<Student> sl;

    // Functions
    void enter_students(); // Enter
    void show_all_students(); // Show all
    void remove_student(int ); // By roll
    void show_student(string ); // By name
    void show_student(int ); //By roll
    static bool compare( Student& s1,Student &s2){return (s1.returnScore()<s2.returnScore());}
    void highest_score();  // highest
    int total_students();  // Total student
    void sort_students(); // Sort
 //   void createStack(std::stack<Student,std::vector<Student> > & );

    //Friend
    friend void join_vector(StudentList &,StudentList &);

private:
    //std::stack<Student,std::vector<Student> > Stack;
};
void StudentList::enter_students()
{
    char ch = 'y';
    cout<<"Enter n to stop entering data.\n";
    do{
        Student temp;
        temp.get_data();
        sl.push_back(temp);
        cout<<"More? ";
        cin>>ch;
    }while(ch!='n');
}
void StudentList::show_all_students()
{
    for( Student v : sl)
        cout<<v<<endl;
}
void StudentList::remove_student(int roll)
{
    auto found = find_if(sl.begin(),sl.end(),[roll](Student &s)
              {return roll == s.returnRoll(); });
    if(found != sl.end())
        sl.erase(found);
}
void StudentList::show_student(string name)
{
    auto found = find_if(sl.begin(),sl.end(),[name](Student &s)
              {return name == s.returnName(); });
    if(found != sl.end())
        cout<<"Student not present.\n";
    else
        cout<<*found<<endl;
}
void StudentList::show_student(int roll)
{
    auto found = find_if(sl.begin(),sl.end(),[roll](Student &s)
              {return roll == s.returnRoll(); });
    if(found != sl.end())
        cout<<*found<<endl;
    else
        cout<<"Student not present.\n";
}
void StudentList::highest_score()
{
    auto max_score = max_element(sl.begin(),sl.end(),compare);
    if(max_score == sl.end())
        cout<<"Container empty.\n";
    else
        cout<<*max_score;
}
int StudentList::total_students()
{
    return sl.size();
}
void StudentList::sort_students()
{
    std::sort(sl.begin(),sl.end(),compare);
}
void join_vector(StudentList &l1,StudentList &l2)
{
    l1.sl.insert(l1.sl.end(),l2.sl.begin(),l2.sl.end());
}
int main()
{
    StudentList l1;
    StudentList l2;
    l1.enter_students();
    l2.enter_students();
    l1.show_all_students();
    l2.show_all_students();
   // l1.remove_student(12);
   // l1.show_all_students();
  //  l1.show_student("nikhil1");
 //   l1.show_student(11);
  //  l1.highest_score();
  //  cout<<l1.total_students();
//    l1.show_student_sub("khil1");
 //   l1.sort_students();
  //  l1.show_all_students();
    join_vector(l1,l2);
    l1.show_all_students();
    l1.sort_students();
    l1.show_all_students();
    return 0;
}
