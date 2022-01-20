#include<iostream>
#include<stdio.h>
#include<string.h>
#include<complex>
using namespace std;
class Complex{
friend istream &operator>>(istream &in,Complex &s);
friend ostream &operator<<(ostream &out,const Complex &s);
friend operator+(const Complex& , const & Complex);
friend bool operator==(const Complex&, const Complex&);
friend bool operator!=(const Complex&, const Complex&);
friend bool operator>(const Complex&, const Complex&);
public:
Complex &operator+=(const Complex  &);
Complex() = default;
static int objcount;
Complex operator - (Complex const &obj) {
		Complex res;
		res.real = real - obj.real;
		res.img = img - obj.img;
		return res;
	}
private:
    int real;
    int img;
};
int Complex::objcount=0;
Complex operator+(const Complex& lhs, const Complex&rhs)
{
    Complex res = lhs;
    res += rhs;
    return res;
}

istream &operator>>(istream &in,Complex &s)
{
    Complex::objcount++;
    in>>s.real>>s.img;
    if(in)
    {}
    else{
        s = Complex();
    }
    return in;
}
ostream &operator<<(ostream &out,const Complex &s)
{
    out<<s.real<<"+i("<<s.img<<")";

    return out;
}
Complex &Complex::operator+=(const Complex  &c2)
{

    img += c2.img;
    real += c2.real;
    return *this;
}
bool operator==(const Complex &lhs,const Complex &rhs)
{
    return lhs.img == rhs.img && lhs.real == rhs.real;
}
bool operator!=(const Complex &lhs,const Complex &rhs)
{
    return !(lhs==rhs);
}
bool operator>(const Complex &lhs,const Complex &rhs)
{
    return sqrt((lhs.img)*(lhs.img) + (lhs.real)*(lhs.real)) > sqrt((rhs.img)*(rhs.img) + (rhs.real)*(rhs.real));
}


