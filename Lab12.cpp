

#include <iostream>

using namespace std;
class complex
{
    float real;
    float imag;
  public:
    void input(float r,float i)
    {
        real=r;
        imag=i;
    }
    friend complex sum(complex,complex);
        void show(void);
};        
void complex :: show(void)
{
    if (imag>0)
    {
        cout<<real<<"+"<<imag<<"i"<<endl;
    }
    else
    {
        cout<<real<<"-"<<abs(imag)<<"i"<<endl;
    }
    
}
complex sum(complex c1,complex c2)
{
    complex c3;
    c3.real=c1.real+c2.real;
    c3.imag=c1.imag+c2.imag;
    return(c3);
}
int main()
{
    complex A,B,C;
    int a,b,p,q;
    cout<<"Enter the real part of the first complex number : "<<" ";
    cin>>a;
    cout<<"Enter the imaginary part of the first complex number : "<<" ";
    cin>>b;
    cout<<"Enter the real part of the second complex number : "<<" ";
    cin>>p;
    cout<<"Enter the imaginary part of the first complex number : "<<" ";
    cin>>q;
    A.input(a,b);
    B.input(p,q);
    C=sum(A,B);
    cout<<"A = ";
    A.show();
    cout<<"B = ";
    B.show();
    cout<<"C = ";
    C.show();
    return 0;
}


