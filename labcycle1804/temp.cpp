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
    int ch;
    do{
        int x,y;
    float a,b;
    cout<<"Choose any option from the following : "<<endl;
    cout<<"1. Integers "<<endl;
    cout<<"2. Floating point numbers "<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"Enter your choice : "<<" ";
    cin>>ch; 
    switch(ch)
    {
      case 1:
      {     
      cout<<"Enter the first integer : "<<" ";
      cin>>x;
      cout<<endl;
      cout<<"Enter the second integer : "<<" ";
      cin>>y;
      cout<<endl;
      calculator<int>calc1(x,y);
      calc1.display_result();
      cout<<endl;
      } 
      break;
      case 2:
      {
      cout<<"Enter the floating point number : "<<" ";
      cin>>a;
      cout<<endl;
      cout<<"Enter the second floating number : "<<" ";
      cin>>b;
      cout<<endl;
      calculator<float>calc2(a,b);
      calc2.display_result();
      }
      break;
      case 3:
      {
      break;
      default:cout<<"\nError ! Please try again\n"<<endl;
      }
   }
      char p;
        if (ch!=3)
        {
        cout<<endl;
        cout<<"Do you want to continue(y/n)? : "<<" ";
        cin>>p;
        if (p=='n')
        {
            ch=3;
        }
        }
    } while (ch!=3);
   return (0);
}   
