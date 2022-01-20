#include<iostream>
using std::cin; using std::cout;
using std::istream ; using std::ostream;

#include<vector>
using std::vector; using std::endl;

#include<algorithm>
using std::find_if; using std::max_element;

#include<string>
using std::string;


template<typename T>
int compare(const T& t1 ,const  T& t2)
{
    if(t1>t2) return -1;
    if(t2>t1) return 1;
    return 0;
}
template<typename T>
T create(const T& t1 )
{
    T temp = t1;
    return temp ;
}
template<typename T>
class createArray
{
    createArray(int s) :   {}
    createArray(std::initializer_list<T> t)  {}
    int sum() const
    {
        int sum  =0  ;
        for(auto i = 0 ;  i < 10 ; ++i)
            sum += array[i];
        return sum;
    }
private:
    int size ;
    int array[size];+
};
int main()
{
    cout<<compare(1,0)<<endl;
    vector<int>v1{1,2};
    vector<int>v2{1,2};
    cout<<compare(v1,v2)<<endl;

    vector<int> vv = create(v1);
    for(const auto i : vv)
        cout<<i<<endl;

    create2D(3,3);
    return 0;
}
