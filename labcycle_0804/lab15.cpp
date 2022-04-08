#include <iostream>
using namespace std;
class Vector
{
    float i,j,k;
    float vector_product;
    public:
	    void operator*(Vector&);
	    friend istream & operator>>(istream&,Vector&);
            friend ostream & operator<<(ostream&,Vector&); 
};    
istream & operator>>(istream&din,Vector&a)
{
    cout<<"Enter the component along x-axis : "<<endl;
    cin>>a.i;
    cout<<"Enter the component along y-axis : "<<endl;
    cin>>a.j;
    cout<<"Enter the component along z-axis : "<<endl;
    cin>>a.k;
    return (din);
}    
ostream & operator<<(ostream&dout,Vector&a)
{	
    dout<<a.i<<"i + "<<a.j<<"j + "<<a.k<<"k"<<endl; 
    return dout;
}
void Vector::operator*( Vector&a)
{	
    float vector_product;	
    vector_product = (i*a.i)+(j*a.j)+(k*a.k);	
    cout<<"Dot product of two vectors: "<<vector_product<<endl;
} 
int main() 
{
    int option;
    int p;
    do 
    {
        Vector V1,V2;
        cout<<"Choose any option from the following : "<<endl;
        cout<<"1 : Display the vectors "<<endl;
	cout<<"2 : Dot product of vectors" <<endl;	
	cout<<"3 : Exit" <<endl;	
	cout<<"Enter your choice :  "<<" ";	
       	cin>>p;		
        switch (p) 
        {
            case 1:
            cout<<"Vector 1"<<endl;
            cin>>V1;
            cout<<"Vector 2"<<endl;
            cin>>V2;
            cout<<"Vector 1: ";
            cout<<V1 <<endl; 
            cout<<"Vector 2: ";
            cout<<V2 <<endl; 		
            case 2:				
            V1*V2; 	
            case 3:
            break;
            default:cout<<"Error ! Please try again "<<endl;
        }
        char a;
        if (p!=3)
        {
            cout<<endl;
            cout<<"Do you want to continue(y/n)?"<<" ";
            cin>>a;
            if (a=='n')
            {
                p=3;
            }
        }
    } while (p!=3);
   
}   
  
   
  
