#include<iostream>
using namespace std;
class Array{
// Friend functions
friend istream &operator>>(istream &in,Array &s);
friend ostream &operator<<(ostream &out,const Array &s);
friend Array operator*(const Array &s,int n);
static int objcount;
public:
Array operator + (Array const &obj) {
		Array res;
		int n=5;
		for(int i=0;i<n;i++)
        {
            res.values[i]= values[i] + obj.values[i];
        }
		return res;
	}
int operator [] (int n) {
		return values[n-1] ;
	}
private:
    int values[5];
    int size;
  /*  get_size(int size=0,int init =0)
    {
        cout<<"Enter no of elements in the array.\n";
        cin>>size;
        cout<<"Enter value to initialize.\n";
        cin>>init;
        Array(init)
    }    */
};
int Array::objcount=0;
istream &operator>>(istream &in,Array &s)
{
    int n=5;
    Array::objcount++;
    for(int i=0;i<n;i++)
    {
        in>>s.values[i];
    }
    return in;
}
ostream &operator<<(ostream &out,const Array &s)
{
    int  n=5;
    for(int i=0;i<n;i++)
    {
       // cout<<"\n"<<i+1<<" element is ";
        out<<s.values[i]<<"  ";
    }
    return out;
}
Array operator * (const Array &s,int n) {
		Array res;
		//int n=5;
		for(int i=0;i<5;i++)
        {
            res.values[i]= s.values[i]*5;
        }
		return res;
	}
Array operator * (int n,const Array &s) {
		return operator*(s,n);
	}

