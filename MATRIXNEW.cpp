#include<iostream>
using namespace std;
class MATRIX
{
    int **C;
    int a,b;
  public:
        MATRIX(int a,int b);
        void get_matrix(int i,int j,int value)
        {
            C[i][j]=value;
        }
        void matrix_display(int i,int j)
        {
            cout<<"Matrix is displayed below : "<<endl;
            for(int i=0; i<a; i++)
            {
                for(int j=0; j<b; j++)
                {
                    cout<<C[i][j]<<" ";
                }
                cout<<endl;    
            }
            
        }
        void matrix_get();
        void matrix_add(MATRIX&);
        void matrix_mult(MATRIX&);
        void matrix_transpose(void);
        void matrix_trace(void); 
        ~MATRIX()    
        {
            for(int i=0;i<a;i++)
            {
                delete C[i];
            }
            delete C;
        }
};
MATRIX::MATRIX(int horiz,int ver)
{
    a=horiz;
    b=ver;
    C=new int *[a];
    for(int i=0;i<a;i++)
    {
        C[i]=new int[b];
    }
}

void MATRIX::matrix_add(MATRIX &A)
{
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            C[i][j]=A.C[i][j]+B.C[i][j];
        }
    }
    cout<<"Resultant matrix = "<<endl;
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;    
    } 
}
void MATRIX::matrix_mult(MATRIX &A)
{
    if (A.b!=B.a)
    {
        cout<<"Matrix multipilication is not possible "<<endl;
    }
    else
    {
        a=A.a;          //row=a   col=b
        b=B.b;
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                C[i][j]=0;
                for(int k=0;k<b;k++)
                {
                    C[i][j]+=A.C[i][k]*B.C[K][j];
                
                }
            }
            cout<<endl;
            cout<<"Resultant matrix = "<<endl;
            for(int i=0; i<a; i++)
            {
                for(int j=0; j<b; j++)
                {
                    cout<<C[i][j]<<" ";
                }
                cout<<endl;    
           } 
        }
    }
}
int MATRIX::matrix_transpose(A)
{
    int transpose;
    cout<<"Transpose matrix : "<<endl;
    a=A.b;
    b=B.a;
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            transpose=A.C[j][i];
            cout<<transpose<<" ";
        }
        cout<<endl;
    }
}
void MATRIX::matrix_trace(MATRIX A)
{
    int trace=0;
    a=A.a;
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            if(i==j)
            {
                trace=trace+A.C[i][j];
                cout<<endl;
            }
        }
    }
    cout<<"Trace of matrix : "<<" ";    
    cout<<trace;
}

int main()
{
    int x;
    int m,n;
    int p,q;
    //MATRIX A(m,n);
    //MATRIX B(p,q);
    do
    {
        cout<<"Enter the order of the first matrix (m x n) : ";
        cin>>m>>n;
        MATRIX A(m,n);
        cout<<"Enter elements of the first matrix row by row : "<<endl;
        int i,j,value;
        for(i=0; i<m; i++)
        {
            for (j=0;j<n;j++)
        {    
            cin>>value;
            //cin>>"Enter"<<i+1<<"]"<<j+1<<"element:";                      
            A.matrix_get(i,j,value)
        }
        A.matrix_display(i,j);
        cout<<"Enter the order of the second matrix ( p x q) : ";
        cin>>p>>q;
        MATRIX B(p,q);
        cout<<"Enter elements of the second matrix row by row : "<<endl;
        int i,j,value;
        for(i=0; i<p; i++)
        {
            for (j=0;j<q;j++)
            {     
                cin>>value;
                //cin>>"Enter["<<i+1<<"]"<<j+1<<"]element:";    
                B.matrix_get(i,j,value);
            }
        }
        B.matrix_display(i,j);
        cout<<"Operations on matrices"<<endl;
        cout<<"1. Addition"<<endl;
        cout<<"2. Multipication"<<endl;
        cout<<"3. Transpose"<<endl;
        cout<<"4. Trace"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter choice : "<<" ";
        cin>>x;
        switch(x)
        {
            case 1: A.matrix_add(&B);
            break;   
            case 2: A.matrix_mult(&B);   
            break;   
            case 3: A.matrix_transpose();   
            break;
            case 4: A.matrix_trace();
            break;
        }    
    } while (x!=4);
    
    return(0);
}       
