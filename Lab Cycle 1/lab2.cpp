#include<iostream>
#include <cmath>
using namespace std;
class Area
{
    public:
    void area(int);
    void area(int,int);
    void area(float);
    void area(float,float); 
    void area(int,int,int);  
};
void area(int s)
{
    cout<<"Enter side of a square:"<<" ";
    cin>>s;
    cout<<"Area of square is : "<<s*s<<endl;
}
void area(int l,int b)
{
    cout<<"Enter length and breadth of rectangle:"<<" ";
    cin>>l>>b;
    cout<<"Area of rectangle is : "<<l*b<<endl;
}
void area(float r)
{
    cout<<"Enter radius of circle:"<<" ";
    cin>>r;
    cout<<"Area of circle is : "<<3.14*r*r<<endl;
}
void area(float base,float height)
{
   cout<<"Enter base and height of the right angled triangle:"<<" ";
   cin>>base>>height;
   cout<<"Area of right angled triangle is : "<<0.5*base*height<<endl;
}
void area(int side1 ,int side2 ,int side3)
{
    cout<<"Enter the first side length of the triangle : "<<" ";
    cin>>side1;
    cout<<"Enter the second side length of the triangle : "<<" ";
    cin>>side2;
    cout<<"Enter the third side length of the triangle : "<<" ";
    cin>>side3;
    int sp,k,ar,g,m,n;
    sp=(side1+side2+side3)/2;
    g=sp-side1;
    m=sp-side2;
    n=sp-side3;
    k=sp*g*m*n;
    ar=sqrt(k);
    cout<<"Area of the triangle is : "<<ar<<endl;
}
void area(float bs,int h)
{ 
   int arparallel; 
   cout<<"Enter base of the  parallelogram : "<<endl;
   cin>>bs;
   cout<<endl;
   cout<<"Enter height of the parallelogram : "<<endl;
   cin>>h;
   cout<<endl;
   arparallel=bs*h;
   cout<<"Area of the parallelogram is : "<<arparallel<<endl;
}   

int main()
{
    int s,l,b,d,e,f,h;
    int x;
    float r,base,height,bs;
    do
    {
        cout<<"You can do the following : "<<endl;
        cout<<"Enter appropriate number : "<<endl;
        cout<<"1 : AREA OF A SQUARE "<<endl;
        cout<<"2 : AREA OF A RECTANGLE "<<endl;
        cout<<"3 : AREA OF A CIRCLE "<<endl;
        cout<<"4 : AREA OF A RIGHT-ANGLED TRIANGLE "<<endl;
        cout<<"5 : AREA OF A TRIANGLE "<<endl;
        cout<<"6 : AREA OF A PARALLELOGRAM "<<endl;
        cout<<endl;
        cout<<"Enter choice : "<<" ";
        cin>>x;
        switch(x)
        {
            case 1: area(s);
            break;
            case 2: area(l,b);
            break;
            case 3: area(r);
            break;
            case 4: area(base,height);
            break;
            case 5: area(d,e,f);
            break;
            case 6: area(bs,h);
            break;
            case 7: break;
            default:cout<<"Error ! Please try again "<<endl;
        }
        char a;
        if (x!=7)
        {
           cout<<"Do you want to continue(y/n)?"<<" ";
           cin>>a;
           if (a=='n')
           {
               x=7;
           }
        }
    } while (x!=7);
    
    return(0);
}

