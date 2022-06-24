#include<iostream>                       //lc 2 q2
using namespace std;
class complex
{
    public:
    float x;
    float y;

    complex(){x=0;y=0;}
    void input (float real,float img)
    {
        x=real;
        y=img;
    }
    friend complex operator+(complex &, complex &);
    friend complex operator*(complex &, complex &);
    void display(void);
};
complex operator+(complex &a,complex &b)
{   
    complex temp;
    temp.x=a.x+b.x;
    temp.y=a.y+b.y;
    
    return(temp);
}
complex operator*(complex &a,complex &b)
{
    complex temp;
    temp.x=(a.x*b.x)-(a.y*b.y);   
    temp.y=(a.x*b.y)+(a.y*b.x);
    return(temp);
 
}

void complex::display(void)
{
    cout<<x<<"";
    if(y<0)
     cout<<y<<"i"<<endl;
    else
      cout<<"+"<<y<<"i"<<endl;
}
char p;
int main()
{
    complex c1,c2,c3,c4;
    float a1,b1,a2,b2;
    int ch;
    do{
    cout<<"Choose any option from the folowing : "<<endl;
    cout<<"----------OPERATIONS ON COMPLEX NUMBERS----------"<<endl;
    cout<<"1 : Input "<<endl;
    cout<<"2 : Addition"<<endl;
    cout<<"3 : Multiplication"<<endl;
    cout<<"4 : Exit"<<endl;
    cout<<"Enter your choice : "<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
    cout<<"\nEnter real part of the first complex number : "<<" ";
    cin>>a1;
    cout<<"\nEnter imaginary part of first complex number:"<<" ";
    cin>>b1;
    c1.input(a1,b1);
    cout<<"Complex number 1 : ";
    c1.display();
    cout<<endl;
    cout<<"\nEnter real part of the second complex number:"<<" ";
    cin>>a2;
    cout<<"\nEnter imaginary part of the second complex number:"<<" ";
    cin>>b2;
    c2.input(a2,b2);
    cout<<"Complex number 2 : ";
    c2.display();
    cout<<endl;
    break;
    case 2:
    c3=c1+c2;
    cout<<"ADDITION"<<endl;
    cout<<"Sum = ";
    c3.display();
    cout<<endl;
    break;
    case 3:
    c4=c1*c2;
    cout<<"MULTIPLICATION"<<endl;
    cout<<"Product = ";
    c4.display();
    cout<<endl;
    case 4: break;
    default:cout<<"Error ! Please try again "<<endl;
    }
    if (ch!=4)
    {
    cout<<"Do you want to continue(y/n)? "<<endl;
    cin>>p;
    if (p=='n')
    {
       ch=4;
    }
    }
    } while (ch!=4);
    
    return(0);
  
}
