#include<iostream>
using namespace std;

class Try{
public:
    int a =10;
};
class again : public Try{
public :
    int c = 20;
};
int main()
{
    again ag ;
    again ag1 ;
    Try t;
//    again *agp = t;
    ag1 = ag;

}
