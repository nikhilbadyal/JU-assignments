#include<iostream>
#include<string>

class String {
public:

    String(const std::string &s = std::string()):ps(new std::string(s)), use(new std::size_t(1)){}
    String(const String &p):ps(p.ps),  use(p.use) { ++*use; }
    String& operator=(const String&);
    ~String();
    std::size_t* & returnUse(){return use;}
private:
    std::string *ps;
    std::size_t *use; // member to keep track of how many objects share
};
String::~String()
{
    if (--*use == 0)
    {
        delete ps;
        delete use;
        std::cout<<"deleted";
    }
}
String& String::operator=(const String &rhs) //s 1
{

    ++*rhs.use; // increment the use count of the right-hand operand //2
    if (--*use == 0) //this lhs = r;
    {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    use = rhs.use; //2
    return *this;
}
int main()
{
    String s("nikhil");
    const std::size_t* check1 = s.returnUse();
    std::cout<<*check1<<std::endl;
     String r = s;
    const std::size_t* check2 = r.returnUse();
    std::cout<<*check2<<std::endl;
}
