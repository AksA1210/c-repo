
#include<iostream>                  //lc2 q8
using namespace std;

//abstract
class Shape
{
    public:
    float area;
    virtual void get_area(void)=0;

};
class Rectangle:public Shape
{
    int length,breadth;
    int area;
    public:
    void get_dim(int l,int b)
    {
        length=l;
        breadth=b;
    }
    void get_area(void)
    {
        area=length*breadth;
        cout<<"The area of the rectangle is : "<<area<<endl<<endl;
    }
};
class Circle:public Shape
{
    int radius;
    public:
    void get_dim(int r)
    {
        radius=r;
    }
    void get_area(void)
    {
        area=3.14*radius*radius;
        cout<<"The area of the circle is : "<<area<<endl<<endl;
    }
};
class Square:public Shape
{
    int sidelength;
    public:
    void get_dim(int s)
    {
        sidelength=s;
    }
    void get_area(void)
    {
        area=sidelength*sidelength;
        cout<<"The area of the square is : "<<area<<endl<<endl;
    }
};
class Ellipse:public Shape
{
    int minor_r;
    int major_r;
    public:
    void get_dim(int a,int b)
    {
        major_r=a;
        minor_r=b;
    }
    void get_area(void)
    {
        area=3.14*major_r*minor_r;
        cout<<"The area of the square is : "<<area<<endl<<endl;
    }
};
int main()
{
    int s,l,a,b;
    int x;
    float r,base,height,bs;

    Shape *shape;
    do
    {
    cout<<"-----------AREA OF DIFFERENT SHAPES----------"<<endl;
    cout<<"Choose any option from the following : "<<endl;
    cout<<"1 : AREA OF A RECTANGLE "<<endl;
    cout<<"2 : AREA OF A CIRCLE "<<endl;
    cout<<"3 : AREA OF A SQUARE "<<endl;
    cout<<"4 : AREA OF A ELLIPSE "<<endl;
    cout<<"5 : QUIT "<<endl;
    cout<<endl;
    cout<<"Enter choice : "<<" ";
    cin>>x;
    if (x==1)
    {
        int l,b;
        cout<<"Enter the length of the rectangle : "<<" ";
        cin>>l;
        cout<<"Enter the breadth of the rectangle : "<<" ";
        cin>>b;
        Rectangle rect;
        rect.get_dim(l,b);
        shape=&rect;
        shape->get_area();
    }
    else if (x==2)
    {
        int r;
        cout<<"Enter the radius of the circle : "<<" ";
        cin>>r;
        Circle cir;
        cir.get_dim(r);
        shape=&cir;
        shape->get_area();
    }
    else if (x==3)
    {
        cout<<"Enter the sidelength of the square : "<<" ";
        cin>>s;
        Square sq;
        sq.get_dim(s);
        shape=&sq;
        shape->get_area();
    }
    else if (x==4)
    {
        cout<<"Enter the major radius of the ellipse : "<<" ";
        cin>>a;
        cout<<"Enter the minor radius of the ellipse : "<<" ";
        cin>>b;
        Ellipse ell;
        ell.get_dim(a,b);
        shape=&ell;
        shape->get_area();
    }
    else if(x==5)
    {
        break;
    }
    
    else
    {
        cout<<"Invalid option "<<endl<<endl;
    }
    }while (x!=5);
    return(0);
}  
         
         
