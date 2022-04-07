
#include <iostream>
using namespace std;
class TIME
{
    int hours;
    int minutes;
  public:
    void gettime(int h,int m)
    {
        hours=h;
        minutes=m;
    }
    void puttime(void)
    {
        cout<<hours<<"hours and ";
        cout<<minutes<<" minutes"<<"\n";
    }
    void sum(TIME,TIME);  
};
void TIME::sum(TIME t1,TIME t2)
{
    minutes=t1.minutes+t2.minutes;
    hours=minutes/60;
    minutes=minutes%60;
    hours=hours+t1.hours+t2.hours;
}
int main()
{
    TIME T1,T2,T3;
    int h1,h2,m1,m2;
    cout<<"Enter the time in hrs(for T1) : ";
    cin>>h1;
    cout<<"Enter the time in minutes(for T1) : ";
    cin>>m1;
    cout<<"Enter the time in hrs(for T2) : ";
    cin>>h2;
    cout<<"Enter the time in minutes(for T2) : ";
    cin>>m2;
    T1.gettime(h1,m1);
    T2.gettime(h2,m2);
    T3.sum(T1,T2);
    cout<<"T1 = ";
    T1.puttime();
    cout<<"T2 = ";
    T2.puttime();
    cout<<"T3 = ";
    T3.puttime();
    return(0);
}


