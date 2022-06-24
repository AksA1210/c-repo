#include<iostream>                    //lc 2 q7
using namespace std;
class alpha
{
    int x;
   public:
    alpha(int i)
    {
        x=i;
        cout<<"alpha initialized"<<endl;
    }
    void show_x(void)
    {
        cout<<"x = "<<x<<endl;
    }
};
class beta
{
    float y;
   public:
    beta(float j)
    {
        y=j;
        cout<<"beta initialized"<<endl;
    }
    void show_y(void)
    {
        cout<<"y = "<<y<<endl;
    }
};
class gamma:public beta,public alpha
{
    int m,n;
   public:
    gamma(int a,float b,int c,int d):alpha(a),beta(b)
    {
        m=c;
        n=d;
        cout<<"gamma initialized"<<endl;
    }
    void show_mn(void)
    {
        cout<<"m = "<<m<<endl;
        cout<<"n = "<<n<<endl;
    }
};
char p;
int main()
{
    do{
    int a,c ,d;
    float b;
    cout<<"Enter the first value : "<<" ";
    cin>>a;
    cout<<"Enter the second value : "<<" ";
    cin>>b;
    cout<<"Enter the third value : "<<" ";
    cin>>c;
    cout<<"Enter the fourth value : "<<" ";
    cin>>d;
    gamma g(a,b,c,d);
    g.show_x();
    g.show_y();
    g.show_mn();
    cout<<"Do you want to continue(y/n)? "<<endl;
    cin>>p;
    }
    while (p!='n');
    return(0);
}          
      
