#include<iostream>
//#include<conio>
#define s 20
using namespace std;
class matrix
{
    int a[s][s],x,y;
    public:
    int transpose[10][10];
   void get();
   void put();
   matrix operator+(matrix);
   matrix operator*(matrix);
   void mat_trace();
   int mat_transpose();
};
void matrix::get()
{
   cout<<"Enter the number of rows of the matrix : "<<" ";
   cin>>x;
   cout<<"Enter the number of columns of the matrix : "<<" ";
   cin>>y;
   cout<<"Enter the Matrix "<<" :\n";
   for(int i=0;i<x;i++)
      for(int j=0;j<y;j++)
         cin>>a[i][j];
   cout<<endl;
}
void matrix::put()
{
   for(int i=0;i<x;i++)
   {
      cout<<"\n\t";
      for(int j=0;j<y;j++)
         cout<<a[i][j]<<" ";
   }
   cout<<endl;
}
matrix matrix::operator+(matrix b)
{
   matrix r;
   if((x!=b.x)||(y!=b.y))
   {
      cout<<"\nMatrix addition is not possible as the orders of both the matrices are not the same\n\n";
      r.x=0;
      r.y=0;
   }
   else
   {
      r.x=x;
      r.y=y;
   }
   for(int i=0;i<x;i++)
      for(int j=0;j<y;j++)
         r.a[i][j]=a[i][j]+b.a[i][j];
   return r;
}

matrix matrix::operator*(matrix b)
{
   matrix r;
   if(y!=b.x)
   {
      cout<<"Matrix multiplication is not possible"<<endl;
      r.x=0;
      r.y=0;
   }
   else
   {
      r.x=x;
      r.y=b.y;
   }
   for(int i=0;i<s;i++)
      for(int j=0;j<s;j++)
         r.a[i][j]=0;
   for(int i=0;i<x;i++)
      for(int j=0;j<b.y;j++)
         for(int k=0;(k<y)||(k<b.x);k++)
            r.a[i][j]+=a[i][k]*b.a[k][j];
 
   return r;
}
int matrix::mat_transpose()
{
   matrix r;
   for(int i=0;i<x;i++)
   {
      for(int j=0;j<y;j++)
      {
          transpose[j][i]=a[i][j];
      }
   }  
    cout<<"The transpose of the matrix is : "<<endl;        
    for(int i=0;i<y;i++)
    {
      for(int j=0;j<x;j++)
      {
         cout << " " << transpose[i][j];
         if (j == x - 1)
            cout << endl;
      }  
    
    } 
    cout<<endl;
    return(0);
}
void matrix::mat_trace()
{   
    int trace=0;
    if (x==y)
    {
    for(int i=0;i<x;i++)
    {
        trace=trace+a[i][i];
    }
    cout<<"Trace of matrix : "<<trace<<endl;
    cout<<endl;
    }
    else
    {
        cout<<"Trace does not exist (The matrix is not a square matrix)"<<endl;
    }
    
}
int main()
{
   matrix a,b,c;
   int x;
   do
   {
       cout<<"----------OPERATIONS ON MATRICES----------"<<endl;
       cout<<"Choose any option from the following : "<<endl;
       cout<<"1 : Input the details of the matrix "<<endl;
       cout<<"2 : Display the matrix "<<endl;
       cout<<"3 : Addition "<<endl;
       cout<<"4 : Multiplication  "<<endl;
       cout<<"5 : Transpose "<<endl;
       cout<<"6 : Trace "<<endl;
       cout<<endl;
       cout<<"Enter your choice : "<<" ";
       cin>>x;
       cout<<endl;
       switch(x)
       {
           case 1:
           a.get();
           b.get();
           case 2:
           cout<<"------Matrix 1------ "<<endl;
           cout<<endl;
           a.put();
           cout<<endl;
           cout<<"------Matrix 2------"<<endl;
           cout<<endl;
           b.put();
           cout<<endl;
           break;
           case 3:
            c=a+b;
            c.put();
            break;
            case 4: 
            c=a*b;
            c.put();
            break;
            case 5:
            cout<<"------Matrix 1------"<<endl;
            cout<<endl;
            a.mat_transpose();
            cout<<"------Matrix 2------"<<endl;
            cout<<endl;
            b.mat_transpose();
            break;
            case 6:
            cout<<endl;
            cout<<"------Matrix 1------"<<endl;
            cout<<endl;
            a.mat_trace();
            cout<<endl;
            cout<<"------Matrix 2------"<<endl;
            cout<<endl;
            b.mat_trace();
            case 7: break;
            default:cout<<"Error ! Please try again "<<endl;
        }
        char a;
        if (x!=7)
        {
        cout<<endl;
        cout<<"Do you want to continue(y/n)?"<<" ";
        cin>>a;
        if (a=='n')
        {
            x=7;
        }
        }
    } while (x!=7);
   
}   
