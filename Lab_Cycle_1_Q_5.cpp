


#include<iostream>
using namespace std;
class  MATRIX
{
    int **p;
    int d1,d2;
  public:
    MATRIX(int x,int y);
    ~MATRIX();
    void get_element(int i,int j,int value)
    {
        p[i][j]=value;
    }
    int &put_element(int i,int j)
    {
        return p[i][j];
    }
};
MATRIX::MATRIX(int x,int y)
{
    d1=x;
    d2=y;
    p=new int*[d1];
    for (int i=0;i<d1;i++)
    {
        p[i]=new int [d2];
    }
}
int main()
{
    int m,n;
    cout<<"Enter size of matrix : "<<" ";
    cin>>m>>n;
    MATRIX A(m,n);
    cout<<"Enter matrix elements row by row "<<endl;
    int i,j,value;
    for(i=0; i<m; i++)
        for (j=0;j<n;j++)
        {
            cin>>value;
            A.get_element(i,j,value);
        }
    cout<<"Matrix created"<<endl;    
    cout<<"Entered matrix : "<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<A.put_element(i,j)<<" ";
        }
        cout<<endl;
    }
    return(0);
}
MATRIX::~MATRIX()
{
    for(int i=0;i<d1;i++)
    {
        delete p[i];
    }
    delete p;
    cout<<"Memory released "<<endl;
    
}
    
   

