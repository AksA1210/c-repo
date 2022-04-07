#include<iostream>
using namespace std;
double zerodivision(float x,float y)
{
    if(y==0)
    {
        throw"Division by zero" ;
    }
    return(x/y);              
}
char p;
int main()
{
    do
    {
    float a;
    float b;
    float c;

    cout<<"--------------------DIVISION OF TWO NUMBERS--------------------"<<endl;
    cout<<"Enter the first number : "<<" ";
    cin>>a;
    cout<<"Enter the second number : "<<" ";
    cin>>b;
    try
    {
        c=zerodivision(a,b);
        cout<<"Result = "<<c<<endl;
    }
    catch(const char*message)
    {
        cout<<"Division by zero"<<endl;
        cout<<"Therefore,the result is undefined"<<endl;
    }
    cout<<"Do you want to continue(y/n)? "<<endl;
    cin>>p;
    }
    while (p!='n');
}
