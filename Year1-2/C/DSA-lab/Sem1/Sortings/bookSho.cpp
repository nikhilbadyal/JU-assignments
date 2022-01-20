#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int i;
class Book{
    static int count;
public:
    Book() {}
    Book(string au, string tit , long int pri, string pub , int stoc);
    const void search();
    const void show_stock()
    {
        cout<<"Stock available - "<<stock<<endl;
    }
    void update();
    show_transCount()
    {
        cout<<"No. of transaction done are - "<<count<<endl;
    }
private:
    void display(int n);
    void get_book();
    string author;
    string title;
    float price;
    string publisher;
    int stock;
    int cost =100;
    update_price(float x){
    price = x;
    cout<<"Price updated successfully.\n";}
};
Book::Book(string au, string tit , long int pri, string pub , int stoc)
{
    author = au;
    title = tit;
    price = pri;
    pub = publisher;
    stock =  stoc;
}
void Book::display(int n)
{
    cost = cost*n;
    cout<<"Total cost is - "<<cost<<endl;
}
void Book::get_book()
{
    int quant;
    cout<<"How many books do you want - ";
    cin>>quant;
    if(stock>quant)
    {
        count++;
        stock -= quant;
        display(quant);
    }
    else{
        cout<<"This much quantity isn't available.\n";
    }
}
const void Book::search()
{
    string tit;
    string auth;

    cout<<"Enter the title of book.\n";
    cin>>tit;
    cout<<"Enter author name.\n";
    cin>>auth;
    if(auth == author && tit == title )
    {
        cout<<"Hooray! Book found.\n";
        get_book();
    }
    else{
        cout<<"Book not available.\n";
    }
}
void Book::update()
{
    float x;
    cout<<"Enter new price of book.\n";
    cin>>x;
    update_price(x);

}
int Book::count = 0;
int main()
{
    Book b("nikhil","oop",250,"new",100);
    b.search();
    b.search();
    b.show_stock();
    b.update();
    b.show_transCount();
}
