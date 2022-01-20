#include<iostream>
#include<string.h>
using namespace std;
class Cricketer{
protected:
    char name[50];
    int played;
    int d,m,y;
public:
    Cricketer() = default;
    Cricketer(const char *s , int x , int d1, int m1 , int y1)
    {
        strcpy(name , s);
        played = x;
        d = d1;
        m = m1;
        y = y1;
    }
};
class Batsman : virtual public Cricketer{
protected:
    Batsman(int run , float avg = 0.0) {
        runs = run ;
        average = runs/played;
    }
    int runs;
    float average;
public:
    Batsman() =  default;
    Batsman(const char *s , int x , int d1 , int m1 , int y1 , int run ) : Cricketer(s,x,d1,m1,y1)   {
        runs = run;
        average = runs/played;
    }
    virtual show_data()
    {
        cout<<"Name of person is - "<<name<<endl;
        cout<<"Match played by person are - "<<played<<endl;
        cout<<"D.O.B of person is - "<<d<<"/"<<m<<"/"<<y<<endl;
        cout<<"Runs made by person are - "<<runs<<endl;
        cout<<"Average of person is - "<<average<<endl;
    }
};
class Bowler : virtual public Cricketer {
protected:
    Bowler(int wick ) {
        wicket = wick;
        economy = 4.6;

    }
    int wicket;
    float economy;
public:
    Bowler() = default;
    Bowler(const char *s , int x , int d1 , int m1 , int y1 , int wick  ) : Cricketer(s,x,d1,m1,y1)   {
        wicket  = wick;
        economy = 4.6;
    }
    virtual show_data()
    {
        cout<<"Name of person is - "<<name<<endl;
        cout<<"Match played by person are - "<<played<<endl;
        cout<<"D.O.B of person is - "<<d<<"/"<<m<<"/"<<y<<endl;
        cout<<"Wickets took  by person are - "<<wicket<<endl;
        cout<<"Economy of person is - "<<economy<<endl;
    }

};
class allRounder: public Batsman , public Bowler{
public:
    allRounder(const char *s , int x , int d1 , int m1 , int y1 , int run,int wick) : Cricketer(s,x,d1,m1,y1), Batsman(run), Bowler(wick){}
    show_data()
    {

        cout<<"Name of person is - "<<name<<endl;
        cout<<"Match played by person are - "<<played<<endl;
        cout<<"D.O.B of person is - "<<d<<"/"<<m<<"/"<<y<<endl;
        cout<<"Runs made by person are - "<<runs<<endl;
        cout<<"Average of person is - "<<average<<endl;
        cout<<"Wickets took  by person are - "<<wicket<<endl;
        cout<<"Economy of person is - "<<economy<<endl;

    }
};
class Pair{
    Batsman bat;
    Bowler bow;
public:
    Pair():bat("Nikhil",100,06,10,2000,10000) ,bow("Nikhil",100,06,10,2000,500) {}
    show_data()
    {
        cout<<"\t\tPlayer 1\n";
        bat.show_data();
        cout<<"\t\tPlayer 2\n";
        bow.show_data();
    }


};
int main()
{
    cout<<"\t\tBatsmen\n";
    Batsman bat("Nikhil",100,06,10,2000,10000);
    bat.show_data();
    cout<<"\t\tBowler\n";
    Bowler bow("Nikhil",100,06,10,2000,500);
    bow.show_data();
    cout<<"\t\tAll-Rounder\n";
    allRounder all("Nikhil",100,06,10,2000,10000,500);
    all.show_data();
    cout<<"\t\tPair\n";
    Pair p;
    p.show_data();
    return 0;
}
