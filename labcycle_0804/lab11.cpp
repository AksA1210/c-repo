#include <iostream>
using namespace std;
class class_2;
class class_1
{
    int value1;
   public:
    void indata(int a)
    {
        value1=a;
    }
    void display(void)
    {
        cout<<value1<<"\n";
    }
    friend void exchange(class_1 &,class_2 &); 
};
class class_2
{
    int value2;
   public:
    void indata(int a)
    {
        value2=a;
    }
    void display(void)
    {
        cout<<value2<<"\n";
    }
    friend void exchange(class_1 &,class_2 &); 

};
void exchange(class_1 & x,class_2 &y)
{
    int temp=x.value1;
    x.value1=y.value2;
    y.value2=temp;
}
int main()
{
    class_1 C1;
    class_2 C2;
    int a,b;
    cout<<"Enter the first number : "<<" ";
    cin>>a;
    cout<<"Enter the second number : "<<" ";
    cin>>b;
    C1.indata(a);
    C2.indata(b);
    cout<<endl;
    cout<<"Values before exchange "<<"\n";
    cout<<"The first number is : "; 
    C1.display();
    cout<<"The second number is : ";
    C2.display();
    exchange(C1,C2);
    cout<<endl;
    cout<<"Values after exchange "<<"\n";
    cout<<"The first number is : ";
    C1.display();
    cout<<"The second number is : ";
    C2.display();

    return(0);
}

