#include<iostream>                //lc 2 q1//count//input in do
#include<cmath>
using namespace std;
class vector
{

    float x,y,z;
    float magnitude;
    public:
    vector(){};
    vector(float a,float b,float c)
    {
        x=a;
        y=b;
        z=c;
    }
    void display_vector()
    {
        float a,b,c;
        if(b<0)
        {
            cout<<a<<"i - "<<abs(b)<<"j + "<<c<<" k"<<endl;
        }
        else if(z<0)
        {
            cout<<x<<"i + "<<y<<"j - "<<abs(z)<<" k"<<endl;
        }
        else if(y<0&&z<0)
        {
            cout<<x<<"i + "<<abs(y)<<"j - "<<abs(z)<<" k"<<endl;
        }
        else
        {
            cout<<x<<"i + "<<y<<"j + "<<z<<" k"<<endl;
        }
        
    }
    void operator==(const vector &);
    void operator!=(const vector &);
    void operator<(const vector &);
    void operator>(const vector &);
    void operator<=(const vector&);
    void operator>=(const vector &);
    void get_magnitude(void)
    {
        //magnitude=(x*x)+(y*y)+(z*z);
        if(x>0 && y>0 &&z>0)
        {
             magnitude=sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
             cout<<"The magnitude of the vector is : "<<magnitude<<endl;
        }
        //magnitude=sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
        //cout<<"The magnitude of the vector is : "<<magnitude<<endl;
    }
};
void vector::operator==(const vector&a)
{
    if(magnitude==a.magnitude)
    {
       /* cout<<"Vector 1 :";
        magnitude;
        cout<<endl;
        cout<<"Vector 2 :";
        a.magnitude;
        cout<<endl;*/
        cout<<"Vector 1 and vector 2 are equal"<<endl;
    }
    else
    {
        cout<<"Vector 1 and vector 2 are not equal"<<endl;
    }
}
void vector::operator!=(const vector&a)
{
    if(magnitude!=a.magnitude)
    {
        cout<<"Vector 1 and Vector 2 are not equal"<<endl;
    }
    else
    {
        cout<<"Vector 1 and vector 2 are equal"<<endl;
    }
}
void vector::operator<(const vector&a)
{
    if(magnitude<a.magnitude)
    {
        cout<<"Vector 2 is greater than vector 1 "<<endl;
    }
    else
    {
        cout<<"Vector 1 is greater than vector 2"<<endl;
    }
}
void vector::operator<=(const vector&a)
{
    if(magnitude<a.magnitude)
    {
        cout<<"Vector 2 is greater than vector 1"<<endl;
    }
    else if(magnitude==a.magnitude)
    {
        cout<<"Vector 1 and vector 2 are equal"<<endl;
    }
    else
    {
        cout<<"Vector 1 is greater than vector 2"<<endl;
    }
}
void vector::operator>(const vector&a)
{
    if(magnitude>a.magnitude)
    {
        cout<<"Vector 1 is greater than vector 2"<<endl;
    }
    else
    {
        cout<<"Vector 1 is lesser than vector 2"<<endl;
        
    }
}
void vector::operator>=(const vector&a)
{
    if(magnitude>a.magnitude)
    {
        cout<<"Vector 1 is greater than vector 2"<<endl;
    }
    else if(magnitude==a.magnitude)
    {
        cout<<"Vector 1 and Vector 2 are equal"<<endl;
    }
    else
    {
        cout<<"Vector 2 is greater than vector 1"<<endl;
    }
}
int main()
{
    int p;
    int count=1;
    do
    {
        int a,b,c;
	    vector v1,v2;
        if(count==1)
        {
        cout<<"-------Vector 1-------"<<endl;
        cout<<"Enter the component along x-axis : "<<endl;
        cin>>a;
        cout<<"Enter the component along y-axis : "<<endl;
        cin>>b;
        cout<<"Enter the component along z-axis : "<<endl;
        cin>>c;
        vector v1(a,b,c);
        cout<<"-------Vector 2-------"<<endl;
        cout<<"Enter the component along x-axis : "<<endl;
        cin>>a;
        cout<<"Enter the component along y-axis : "<<endl;
        cin>>b;
        cout<<"Enter the component along z-axis : "<<endl;
        cin>>c;
	    vector v2(a,b,c);
        count=0;
        }
        cout<<"You can do the following : "<<endl;
        cout<<"Enter appropriate number : "<<endl;
        cout<<"1 : Vector 1 == Vector 2"<<endl;
        cout<<"2 : Vector 1 != Vector 2 "<<endl;
        cout<<"3 : Vector 1 < Vector 2 "<<endl;
        cout<<"4 : Vector 1 <= Vector 2  "<<endl;
        cout<<"5 : Vector 1 > Vector 2  "<<endl;
        cout<<"6 : Vector 1 >= Vector 2  "<<endl;
	    cout<<"7 : Enter the new vector "<<endl;
        cout<<endl;
        cout<<"Enter your choice : "<<" ";
        cin>>p;
        //v1.get_magnitude();
        switch(p)
        {

           case 1:
           v1==v2;
           cout<<"Vector 1 : ";
           v1.display_vector();
           cout<<endl;
           v1.get_magnitude();
           cout<<"Vector 2 : ";
           v2.display_vector();
           cout<<endl;
           v2.get_magnitude();
           break;
           case 2: 
           v1!=v2;
           cout<<"Vector 1 : ";
           v1.display_vector();
           v1.get_magnitude();
           cout<<"Vector 2 : ";
           v2.display_vector();
           v2.get_magnitude();
           break;
           case 3:
           v1<v2;
           cout<<"Vector 1 : ";
           v1.display_vector();
           cout<<endl;
           v1.get_magnitude();
           cout<<"Vector 2 : ";
           v2.display_vector();
           cout<<endl;
           v2.get_magnitude();
           break;
           case 4: 
           v1<=v2;
           cout<<"Vector 1 : ";
           v1.display_vector();
           v1.get_magnitude();
           cout<<"Vector 2 : ";
           v2.display_vector();
           cout<<endl;
           v2.get_magnitude();
           case 5:
           v1>v2;
           cout<<"Vector 1 : ";
           v1.display_vector();
           cout<<endl;
           v1.get_magnitude();
           cout<<"Vector 2 : ";
           v2.display_vector();
           cout<<endl;
           v2.get_magnitude();
           break;
           case 6:
           v1>=v2;
           cout<<"Vector 1 : ";
           v1.display_vector();
           cout<<endl;
           v1.get_magnitude();
           cout<<"Vector 2 : ";
           v2.display_vector();
           cout<<endl;
           v2.get_magnitude();
           break;
 	       case 7:
 	       count=1;
 	       break;
           case 8:break;
           default:cout<<"Error ! Please try again "<<endl;
        }
        char g;
        if (p!=8)
        {
        cout<<endl;
        cout<<"Do you want to continue(y/n)?"<<" ";
        cin>>g;
        if (g=='n')
        {
            p=8;
        }
        }
    } while (p!=8);
   return (0);
}   


