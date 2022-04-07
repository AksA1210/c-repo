#include <iostream>

using namespace std;
class complex
{
    float x,y;
  public:
    complex(){}
    complex(float a)
    {
        x=y=a;
    }
    complex(float real,float imag)
    {
        x=real;
        y=imag;
    }
    friend complex sum(complex,complex);
    friend void show(complex);
};
complex sum(complex c1,complex c2)
{
    complex c3;
    c3.x=c1.x+c2.x;
    c3.y=c1.y+c2.y;
    return(c3);
}
void show(complex c)
{
    if (c.y>0)
    {
        cout<<c.x<<"+"<<c.y<<"i " <<"\n";
    }
    else
    {
        cout<<c.x<<"-"<<abs(c.y)<<"i " <<"\n";
    }   
}
char u;
int main()
{
    do{
    int a,b,p,q;
    cout<<"Enter the real part of the first complex number : "<<" ";
    cin>>a;
    cout<<"Enter the imaginary part of the first complex number : "<<" ";
    cin>>b;
    cout<<"Enter the real part of the second complex number : "<<" ";
    cin>>p;
    cout<<"Enter the imaginary part of the first complex number : "<<" ";
    cin>>q;
    complex A,B,C;
    A=complex(a,b);
    B=complex(p,q);
    C=sum(A,B);
    cout<<"\n";
    cout<<"A = "<<" ";
    show(A);
    cout<<"B = "<<" ";
    show(B);
    cout<<"Sum = A+B = ";
    cout<<"C = "<<" ";
    show(C);
    cout<<"Do you want to continue(y/n)? "<<endl;
    cin>>u;
    }
    while (u!='n');
    return(0);
    
}



