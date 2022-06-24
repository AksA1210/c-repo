#include<iostream>                //lc 2 q1
#include<cmath>
using namespace std;
class vector
{

    int x,y,z;
    float magnitude;
    public:
    vector(){};
    vector(int a,int b,int c)
    {
        x=a;
        y=b;
        z=c;
    }
    int operator==(vector &);
    int operator!=(vector &);
    int operator<(vector &);
    int operator>(vector &);
    int operator<=(vector&);
    int operator>=(vector &);
    void get_magnitude(void);
};
void vector:: get_magnitude(void)
{
    float mag;                            //pow(x,2)
    mag=(x*x)+(y*y)+(z*z);
    magnitude=sqrt(mag);//mag=sqrt(a*a+b*b+c*c);
}
int vector::operator==(vector&a)
{
    if(magnitude==a.magnitude)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int vector::operator!=(vector&a)
{
    if(magnitude!=a.magnitude)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int vector::operator<(vector&a)
{
    if(magnitude<a.magnitude)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int vector::operator<=(vector&a)
{
    if(magnitude<=a.magnitude)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int vector::operator>(vector&a)
{
    if(magnitude<=a.magnitude)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int vector::operator>=(vector&a)
{
    if(magnitude>=a.magnitude)
    {
        return 1;
    }
    else
    {
        return 0;
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
         v1.get_magnitude();
        switch(p)
        {

           case 1:
           if(v1==v2)
           {
               cout<<"\nVectors are equal as their magnitude is the same"<<endl;
           }
           else
           {
               cout<<"\nFALSE"<<endl;
           }
           break;
           case 2: 
           if(v1!=v2)
           {
               cout<<"\nTRUE"<<endl;
           }
           else
           {
               cout<<"\nFALSE"<<endl;
           }
           break;
           case 3:
           if(v1<v2)
           {
               cout<<"\nTRUE"<<endl;
           }
           else
           {
               cout<<"\nFALSE"<<endl;
           }
            break;
            case 4: 
            if(v1<=v2)
            {
               cout<<"\nTRUE"<<endl;
            }
            else
            {
               cout<<"\nFALSE"<<endl;
            }
            case 5:
            if(v1>v2)
            {
               cout<<"\nTRUE"<<endl;
            }
            else
            {
               cout<<"\nFALSE"<<endl;
            }
            break;
            case 6:
            if(v1>=v2)
           {
               cout<<"\nTRUE"<<endl;
           }
           else
           {
               cout<<"\nFALSE"<<endl;
           }
            break;
 	    case 7:
 	    count=1;
            case 8:
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
