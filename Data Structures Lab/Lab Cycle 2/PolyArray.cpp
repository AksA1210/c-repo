//Add 2 Polynomials using array
#include<iostream>
using namespace std;
int max(int m,int n)
{  
    int MAX;
    if (m>n)
    {
        MAX=m;
    }
    else
    {
        MAX=n;
    }
    return MAX;
}
 
int *add(int A[], int B[], int m, int n)
{
   int size = max(m,n);
   int *sum = new int[size];
 
   for (int i = 0; i<m; i++)
     sum[i] = A[i];
 
   for (int i=0; i<n; i++)
       sum[i] += B[i];
 
   return sum;
}
 
void print(int poly[], int m,int n)
{
    int MAX=max(m,n);
    int i;
    for (i=0; i<n; i++)
    {
       cout << poly[i]<<" ";
       if (i != MAX-1 )
       {
        cout << "x^" << MAX-1 ;
        cout << " + ";
        MAX--;
       }
        else
        {
            cout<<poly[i]<<" ";
            cout<<endl;
        }
    }
}
 
int main()
{
    int m;
    int n;
    cout<<"Enter the number of terms in the first polynomial : "<<" ";
    cin>>m;
    int A[m];
    cout<<"Enter the coefficients of the first polynomial(one by one from the highest power) : "<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>A[i];
    }
    cout<<"Enter the number of terms in the second polynomial : "<<" ";
    cin>>n;
    int B[n];
    cout<<"Enter the coefficients of the second polynomial(one by one from the highest power) : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>B[i];
    }
    //cout << "First polynomial is : ";
    //print(A,m);
    //cout<<endl;
    //cout << "Second polynomial is :";
    //print(B,n);
    //cout<<endl;
 
    int *sum = add(A, B, m, n);
    int size = max(m,n);

    cout << "Polynomial sum is :  ";
    print(sum,m,n);
 
    return (0);
}
