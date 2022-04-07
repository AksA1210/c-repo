

#include<iostream>
#include<cmath>
using namespace std;
template <class T>
class calculator
{
    T num1,num2;
    public:
     calculator(T n1,T n2)
    {
        num1=n1;
        num2=n2;
    }
    void display_result(void)
    {
        cout<<"Numbers "<<num1<<" and "<<num2<<endl;
        if(num2<0)
        {
            cout<<num1<<"-"<<abs(num2)<<" = "<<add()<<endl;
            
        }
        else
        {
            cout<<num1<<"+"<<num2<<" = "<<add()<<endl;
        }
        if(num2<0)
        {
            cout<<num1<<"+"<<abs(num2)<<" = "<<subtract()<<endl;
            
            
        }
        else
        {
            cout<<num1<<"-"<<num2<<" = "<<subtract()<<endl;
            
        }
        cout<<num1<<"*"<<num2<<" = "<<multiply()<<endl;
        cout<<num1<<"/"<<num2<<" = "<<divide()<<endl;
    }
    T add()
    {
        return(num1+num2);
    }
    T subtract()
    {
        return(num1-num2);
    }
    T multiply()
    {
        return(num1*num2);
    }
    T divide()
    {
        return(num1/num2);
    }

};
char p;
int main()
{
    do{
        int x,y;
    float a,b;
    cout<<"Enter the first integer : "<<" ";
    cin>>x;
    cout<<endl;
    cout<<"Enter the second integer : "<<" ";
    cin>>y;
    cout<<endl;
    calculator<int>calc1(x,y);
    cout<<"Enter the floating point number : "<<" ";
    cin>>a;
    cout<<endl;
    cout<<"Enter the second floating number : "<<" ";
    cin>>b;
    cout<<endl;
    calculator<float>calc2(a,b);
    calc1.display_result();
    cout<<endl;
    calc2.display_result();
    cout<<"\nDo you want to continue(y/n)?"<<endl;
    cin>>p;
    }
    while (p!='n');
    return(0);
}
