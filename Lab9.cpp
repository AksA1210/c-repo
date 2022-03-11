#include <iostream>
using namespace std;
class test
{
    int code;
    static int count;
public:
    void setcode(void)
    {
        code=++count;
    } 
    void showcode(void)
    {
        cout<<"Object Number : "<<code<<endl;
    }
    static void showcount(void)
    {
        cout<<"Count : "<<count<<endl;
    }
};
int test::count;
int main()
{
    int n;
    cout<<"Enter no: of objects : ";
    cin>>n;
    test o[n];
    for(int i=0;i<n;i++)
    {
        o[i].setcode();
        cout<<"\nObject "<<i+1<<" created"<<endl;
    }
    test::showcount();
    for(int i=0;i<n;i++)
    {
        o[i].showcode();
    }
    return(0);
}



