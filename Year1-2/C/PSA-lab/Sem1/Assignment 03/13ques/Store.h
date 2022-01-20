#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class Store{
friend istream &operator>>(istream &in,Store &s);
friend ostream &operator<<(ostream &out,const Store &s);
public:
static int objcount;
code_ret() const {return code;}
update_rate(int n) {rate= n; }
update_quant(int n) {quant= n; }
private:
    int code;
    char name[30];
    int quant;
    int rate;
};
int Store::objcount=0;
istream &operator>>(istream &in,Store &s)
{
    Store::objcount++;
    in>>s.code>>s.name>>s.quant>>s.rate;
    return in;
}
ostream &operator<<(ostream &out,const Store &s)
{
    out<<s.code<<" "<<s.name<<" "<<s.quant<<" "<<s.rate;
    return out;
}
