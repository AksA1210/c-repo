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
        cout<<"Book code : "<<code<<endl;
    }
    static void showcount(void)
    {
        cout<<"Count : "<<count<<endl;
    }
};
int test::count;

char p;

int main()
{
    do{
    int n;
    cout<<"Enter no: of books : ";
    cin>>n;
    test o[n];
    for(int i=0;i<n;i++)
    {
        o[i].setcode();
        //cout<<"\nBook ";
        o[i].showcode();
        cout<<" created"<<endl;
        
    }
    test::showcount();
    for(int i=0;i<n;i++)
    {
        o[i].showcode();
    }
    
    cout<<"\n Do you want to continue(y/n)?"<<endl;cin>>p;
    }
    return(0);
}

    while (p!='n');
    return(0);
}

