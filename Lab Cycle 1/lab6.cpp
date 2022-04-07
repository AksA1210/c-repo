#include <iostream>
using namespace std;
class TIME
{
    int hours;
    int minutes;
    int seconds;
  public:
    void gettime(int h,int m,int s)
    {
        hours=h;
        minutes=m;
        seconds=s;
    }
    void puttime(void)
    {
        cout<<hours<<"hours and ";
        cout<<minutes<<" minutes and ";
        cout<<seconds<<" seconds";
    }
    void sum(TIME,TIME);  
};
void TIME::sum(TIME t1,TIME t2)
{
    seconds=t1.seconds+t2.seconds;
    minutes=seconds/60;
    seconds=seconds%60;
    minutes=minutes+t1.minutes+t2.minutes;
    hours=minutes/60;
    minutes=minutes%60;
    hours=hours+t1.hours+t2.hours;
}
char p;
int main()
{
    TIME T1,T2,T3;
    int h1,h2,m1,m2,s1,s2;
    do
    {
    cout<<"Enter the time in hrs(for T1) : ";
    cin>>h1;
    cout<<"Enter the time in minutes(for T1) : ";
    cin>>m1;
    cout<<"Enter the time in seconds(for T1) : ";
    cin>>s1;
    cout<<"Enter the time in hrs(for T2) : ";
    cin>>h2;
    cout<<"Enter the time in minutes(for T2) : ";
    cin>>m2;
    cout<<"Enter the time in seconds(for T2) : ";
    cin>>s2;
    T1.gettime(h1,m1,s1);
    T2.gettime(h2,m2,s2);
    T3.sum(T1,T2);
    cout<<endl;
    cout<<"T1 = "<<" ";
    T1.puttime();
    cout<<endl;
    cout<<"T2 = "<<" ";
    T2.puttime();
    cout<<endl;
    cout<<"T3 = "<<" ";
    T3.puttime();
    cout<<endl;
    cout<<"Do you want to continue(y/n)? "<<endl;
    cin>>p;
    }
    while (p!='n');
    
    return(0);
}
