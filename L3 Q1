

#include<iostream>
#include<cstring>
using namespace std;
class media
{
    protected:
    char title[50];
    float price;
    public:
    media(char *s,float a)
    {
        strcpy(title,s);
        price=a;
    }
    virtual void display()=0;
};
class book:public media
{
    int pages;
    public:
    book(char *s,float a,int p):media(s,a)
    {
        pages=p;
    }
    void display();
};
class tape:public media
{
    float Time;
    public:
    tape(char *s,float a,float t):media(s,a)
    {
        Time=t;
    }
    void display();

};
void book::display()
{
    cout<<"Title : "<<title<<endl;
    cout<<"Pages : "<<pages<<endl;
    cout<<"Price : "<<price<<endl;

}


void tape::display()
{
    cout<<"Title : "<<title<<endl;
    cout<<"Play time : "<<time<<endl;
    cout<<"Price : "<<price<<endl;

}
int main()
{
    char *title=new char[30];
    float price,Time;
    int pages;
    cout<<"ENTER BOOK DETAILS"<<endl;
    cout<<"Title : ";
    cin>>title;
    cout<<"Price : ";
    cin>>price;
    cout<<"Pages : ";
    cin>>pages;
    book book1(title,price,pages);
    cout<<"ENTER TAPE DETAILS"<<endl;
    cout<<"Title : ";
    cin>>title;
    cout<<"Price : ";
    cin>>price;
    cout<<"Play time(in minutes) : ";
    cin>>Time;
    tape tape1(title,price,Time);
    media* list[2];
    list[0]=&book1;
    list[1]=&tape1;
    cout<<"\n MEDIA DETAILS";
    cout<<"\n-----------BOOK----------"<<endl;
    list[0]->display();
    cout<<"\n-----------TAPE----------"<<endl;
    list[1]->display();
    return 0;

}
