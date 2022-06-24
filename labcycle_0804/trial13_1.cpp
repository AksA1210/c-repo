#include<iostream>                //lc 2 q1  //input function not switch
#include<cmath>
using namespace std;
class vector
{

    float a,b,c;
    float magnitude;
    public:
    void input(float ,float ,float )
    {
        cout<<"-------Vector 1-------"<<endl;
        cout<<"Enter the component along x-axis : "<<endl;
        cin>>a;
        cout<<"Enter the component along y-axis : "<<endl;
        cin>>b;
        cout<<"Enter the component along z-axis : "<<endl;
        cin>>c;
        //vector v1(a,b,c);
        cout<<"-------Vector 2-------"<<endl;
        cout<<"Enter the component along x-axis : "<<endl;
        cin>>a;
        cout<<"Enter the component along y-axis : "<<endl;
        cin>>b;
        cout<<"Enter the component along z-axis : "<<endl;
        cin>>c;
    }
    void display_vector()
    {
        float a,b,c;
        if(b<0)
        {
            cout<<a<<"i - "<<abs(b)<<"j + "<<c<<" k"<<endl;
        }
        else if(c<0)
        {
            cout<<a<<"i + "<<b<<"j - "<<abs(c)<<" k"<<endl;
        }
        else if(b<0&&c<0)
        {
            cout<<a<<"i + "<<abs(b)<<"j - "<<abs(c)<<" k"<<endl;
        }
        else
        {
            cout<<a<<"i + "<<b<<"j + "<<c<<" k"<<endl;
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
        if(a>0 && b>0 && c>0)
        magnitude=sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
        cout<<"The magnitude of the vector is : "<<magnitude<<endl;
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
        //float a,b,c;
	    vector v1,v2;
	    float i,j,k;
	    v1.input(i,j,k);
 	    cout<<"Vector 1 : ";
 	    v1.display_vector();
 	    v2.input(i,j,k);
 	    cout<<"Vector 2 : ";
 	    v2.display_vector();
        cout<<"You can do the following : "<<endl;
        cout<<"Enter appropriate number : "<<endl;
        cout<<"2 : Vector 1 == Vector 2"<<endl;
        cout<<"3 : Vector 1 != Vector 2 "<<endl;
        cout<<"4 : Vector 1 < Vector 2 "<<endl;
        cout<<"5 : Vector 1 <= Vector 2  "<<endl;
        cout<<"6 : Vector 1 > Vector 2  "<<endl;
        cout<<"7 : Vector 1 >= Vector 2  "<<endl;
	    cout<<"8 : Enter the new vector "<<endl;
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
 	       case 7 :
 	       v1.input(i,j,k);
 	       cout<<"Vector 1 : ";
 	       v1.display_vector();
 	       v2.input(i,j,k);
 	       cout<<"Vector 2 : ";
 	       v2.display_vector();
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
