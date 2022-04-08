#include<iostream>                        //lc 2 q4
using namespace std;
class  MATRIX
{
    int **p;
    int x,y;
  public:
    MATRIX(int x,int y);
    //~MATRIX();


    void input()
    {
       cout<<"Enter matrix elements row by row "<<endl;
       int i,j,value;
       for(i=0; i<x; i++)
       {
	  for (j=0;j<y;j++)
          {
            cin>>value;
            get_element(i,j,value);
          }
       }    
    }


    void get_element(int i,int j,int value)
    {
        p[i][j]=value;
    }
    int &put_element(int i,int j)
    {
        return p[i][j];
    }
    void output()
    {
       for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            cout<<put_element(i,j)<<" ";
        }
        cout<<endl;
    }  
    }
    MATRIX operator+(MATRIX);
    MATRIX operator*(MATRIX);
};
MATRIX::MATRIX(int a,int b)
{
    x=a;
    y=b;
    p=new int*[x];
    for (int i=0;i<x;i++)
    {
        p[i]=new int [y];
    }
}
MATRIX MATRIX::operator+(MATRIX B)
{
   MATRIX r(x,y);
   if((x!=B.x)||(y!=B.y))
   {
      cout<<"\nMatrix addition is not possible as the orders of both the matrices are not the same\n\n";
      r.x=0;
      r.y=0;
   }
   else
   {
      r.x=x;
      r.y=y;
   
   for(int i=0;i<x;i++)
   {
      for(int j=0;j<y;j++)
      {
        int value=put_element(i,j)+B.put_element(i,j);
        r.get_element(i,j,value);
      } 
   }  
   cout<<"Sum of the two matrices : "<<endl;
   for(int i=0;i<x;i++)
   {
       for(int j=0;j<y;j++)
       {
          cout<<r.put_element(i,j)<<" ";
       }
       cout<<endl;
   }  
   }
   return r;
   
}

MATRIX MATRIX::operator*(MATRIX B)
{

    int value=0;

    MATRIX r(x,y);
    if((x!=B.y)||(y!=B.x))
    {
      cout<<"Matrix multiplication is not possible"<<endl;
      r.x=0;
      r.y=0;
    }
    else
    {
      r.x=x;
      r.y=B.y;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<B.y;j++)
        {
            for(int k=0;(k<y)||(k<B.x);k++)
            {
            value=value+(put_element(i,k)*B.put_element(k,j));
            }
        r.get_element(i,j,value);
        }
    }   
    cout<<"Product of the two matrices : "<<endl;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            cout<<r.put_element(i,j)<<" ";
        }
        cout<<endl;
    }  
   return r;  
    }
}
int main()
{
    int x;
        cout<<"\nMatrix 1"<<endl;
        int m,n;
        cout<<"Enter number of rows of the matrix : "<<" ";
        cin>>m;
        cout<<"Enter number of columns of the matrix : "<<" ";
   	cin>>n;
        MATRIX A(m,n);
        A.input();
        cout<<"\nMatrix 2"<<endl;
        cout<<"Enter number of rows of the matrix : "<<" ";
        cin>>m;
        cout<<"Enter number of columns of the matrix : "<<" ";
   	cin>>n;
        MATRIX B(m,n);
        B.input();

    do
    {        
        cout<<"-------------MATRIX OPERATIONS---------"<<endl;
        cout<<"Choose any option from the following : "<<endl;
        cout<<"1 : Display the matrix "<<endl;
        cout<<"2 : Addition "<<endl;
        cout<<"3 : Multiplication  "<<endl;
        cout<<"4 : Quit  "<<endl;
        cout<<endl;
        cout<<"Enter your choice : "<<" ";
        cin>>x;
        switch(x)
        {
            case 1:
            cout<<endl; 
            cout<<"\nMatrix 1 : "<<endl<<endl;
            A.output();
            cout<<endl;
            cout<<"\nMatrix 2 : "<<endl<<endl;
            B.output();
            cout<<endl;
            break;
            case 2:
            cout<<endl;
            A+B;
            cout<<endl;
            break;
            case 3: 
            cout<<endl;
            A*B;
            cout<<endl;
            break;
            case 4: break;
            default:cout<<"\nError ! Please try again\n"<<endl;
        }
    } while (x!=4);
   return (0);
}   
