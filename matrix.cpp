#include<iostream>
using namespace std;
class MATRIX
{
    int m,n,p,q;
    int A[10][10];
    int B[10][10];
    int C[10][10];
  public:
    int get_element(int,int,int);
    int matrix_add(int,int);
    int matrix_mult(int,int);
    int matrix_transpose(int);
    int matrix_determinant(int); 
    int matrix_display();
};
int MATRIX:: get_element(int i,int j,int value)
{
    A[i][j]=value;
    return value;
} 
int MATRIX::matrix_add(int X,int Y)
{
    for(int i=0; i<m+1 && i<p+1; i++)
    {
        for(int j=0; j<n+1 && j<q+1; j++)
        {
            C[i][j]=A[i][j]+B[i][j];
        }
    }
    cout<<"Resultant matrix = "<<matrix_display(C);
}
int MATRIX::matrix_mult(int X,int Y)
{
    for(int i=0; i<m+1 && i<p+1; i++)
    {
        for(int j=0; j<n+1 && j<q+1; j++)
        {
            C[i][j]=A[i][j]*B[i][j]+A[i][j+1]*B[i+1][j]+A[i][j+2]*B[i+2][j];
        }
    }
    cout<<"Resultant matrix = "<<matrix_display(C);    
}
int MATRIX::matrix_transpose(int X)
{
    for(int i=0; i<m+1; i++)
    {
        for(int j=0; j<n+1; j++)
        {
           A[i][j]=A[j][i];
        }
    }
    cout<<"Resultant matrix : "<<matrix_display(A);    
}
int MATRIX::matrix_display(int X)
{
    for(int i=0; i<m+1; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;    
}
int main()
{
    int m,n,o,p,q,r;
    cout<<"Enter the number of rows of matrix 1 : "<<" ";
    cin>>m;
    cout<<"Enter the number of coloumns of matrix 1 : "<<" ";
    cin>>n;
    cout<<"Enter the number of rows of matrix 2 : "<<" ";
    cin>>p;
    cout<<"Enter the number of coloumns of matrix 2 : "<<" ";
    cin>>q;
    MATRIX A(m,n);
    MATRIX B(p,q);
    cout<<"Enter matrix elements row by row "<<endl;
    int i,j,value;
    for(i=0; i<m; i++)
        for (j=0;j<n;j++)
        {
            cin>>value;
            cout<<A.get_element(i,j,value);
        }
    }    
    MATRIX D;
    D.matrix_add(A,B);
    D.matrix_mult(A,B);
    D.matrix_transpose(A);
    D.matrix_determinant(A);
    D.matrix_display(A);
    return(0);
}






