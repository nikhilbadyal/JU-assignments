#include<iostream>
#include<cstdlib>
#include<string.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;
#define hra 0.3
#define da 0.8
#define allowance 0.4
class Employee{
protected:
    string name;
    unsigned long int id;
    string desigination;
    float  basicPay;
    double   salary=0.0;
public:

    get_data()
    {
        cout<<"Enter basic pay - ";
        cin>>basicPay;
    }
    virtual show_data() {}
};
class Permanent : public Employee{
public:
    calcSalary()
    {
        salary += basicPay + (hra*basicPay) + (da*basicPay);
    }
    show_data()  override
    {
        calcSalary();
        cout<<"\nSalary of Permanent person is - "<<salary;
    }

};
class Contractual: public Employee{
public:
    calcSalary()
    {
        salary += basicPay + (basicPay*allowance);
    }
    show_data()
    {
        calcSalary();
        cout<<"\nSalary of Contractual person is - "<<salary;
    }
};
int main()
{
    Employee *ptr[2];
    Contractual c;
    Permanent p;
    ptr[0] = &c;
    ptr[1] = &p;
    ptr[0]->get_data();
    ptr[1]->get_data();
    ptr[0]->show_data();
    ptr[1]->show_data();
    return 0;
}
