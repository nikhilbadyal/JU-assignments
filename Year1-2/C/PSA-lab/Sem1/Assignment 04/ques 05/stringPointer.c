#include<iostream>
#include<string>

class String {
public:

    String(const std::string &s = std::string()):ps(new std::string(s)), use(new std::size_t(1)){}
    String(const String &p):ps(p.ps),  use(p.use) { ++*use; }
    String& operator=(const String&);
    ~String();
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
    }
}
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{

    ++*rhs.use; // increment the use count of the right-hand operand
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    use = rhs.use;
    return *this;
}
int main()
{
    String s;
}
