#include<iostream>
#include<string>
using namespace std;
class Date{
public:
    friend class Balance;
    get_date()
    {
        cout<<"Enter day , month , year.\n";
        cin>>day>>month>>year;
    }
    show_date()
    {
        cout<<"Day , month , year.\n";
        cout<<day<<month<<year;
    }
private:
    int day = 5;
    int month = 8;
    int year= 2019;
};
class Balance{
public:
    friend class Trans;
    void show_data()
    {
        cout<<accNo;
        cout<<balance;
        cout<<date.show_date();
    }
private:
    int accNo = 23564464;
    int balance = 50000;
    Date date;
};
class Trans{
public:
    Balance b;
    Date d;
    void withdraw()
    {
        int with;
        cout<<b.balance;
        cout<<"Enter the amount you want to withdraw.\n";
        cin>>with;
        b.balance = b.balance - with ;
        if(with>b.balance)
        {
            cout<<"Insufficient amount in account.";
            b.balance = b.balance + with;
        }
        else{
            cout<<"Amount after withdrawal is "<<b.balance;
        }
    }
    void update_date()
    {
        d.get_date();
    }
private:
    int accNo ;
    int date;
    int amount;
    string type;
};
int main()
{
    Trans t;
    t.withdraw();


    return 0;
}
