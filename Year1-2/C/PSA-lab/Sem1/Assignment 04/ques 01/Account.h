#include<iostream>
#include<stdio.h>
#include<string.h>
class Acoount{

public:

};
using namespace std;
class Item_list;
class Account{
friend class Item_list;
friend istream &operator>>(istream &in,Account &s);
friend ostream &operator<<(ostream &out,const Account &s);
public:
static int objcount;
accn_ret() const {return acc_no;}
update_bal(int n) {balance = n;}
void add(int);
    void search();
    void search_display();
    void display();
    void update();
private:
    int acc_no,balance;
};
int Account::objcount=0;
istream &operator>>(istream &in,Account &s)
{
    Account::objcount++;
    in>>s.acc_no>>s.balance;
    return in;
}
ostream &operator<<(ostream &out,const Account &s)
{
    out<<s.acc_no<<"  "<<s.balance;
    return out;
}
class Item_list{
public:
    Account s[MAX];

};
