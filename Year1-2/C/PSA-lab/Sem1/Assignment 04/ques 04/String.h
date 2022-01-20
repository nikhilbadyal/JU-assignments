#include<iostream>
#include<string>
using namespace std;
class String{
// Friend functions
friend istream &operator>>(istream &in,String &s);
friend ostream &operator<<(ostream &out,const String &s);
friend bool operator==(const String&, const String&);
public:
friend String operator+(const String &, const String &);
void operator=(String &s1)
{
    int i;
    for(i=0; s1.words[i] != '\0'; i++)
    {
        words[i]=s1.words[i];
    }
    words[i]='\0';
}
static int objcount;
public:

char operator [] (int n) {
		return words[n-1] ;
	}
private:
    char words[100];
    int size;
};
int String::objcount=0;
istream &operator>>(istream &in,String &s)
{
    String::objcount++;
    in>>s.words;
    return in;
}
ostream &operator<<(ostream &out,const String &s)
{
    out<<s.words;
    return out;
}
String operator + (String const &s1,String const &s2) {
		String res;
        int i, j;
        for(i=0; s1.words[i] != '\0'; i++)
        {
            res.words[i]=s1.words[i];
        }
        for(j=0; s2.words[j] != '\0'; j++,i++)
        {
        res.words[i]=s2.words[j];
        }
        res.words[i]='\0';
		return res;
	}
bool operator==(const String &lhs,const String &rhs)
{
    int i,j;
    for(i=0,j=0;lhs.words[i]!= '\0',rhs.words != '\0';i++,j++)
    {
        if(lhs.words[i] != rhs.words[i])
        {
            return 0;
        }
        else{
        return 1;
        }
    }

}

