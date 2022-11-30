//Floyd Warshall
#include<iostream>
using namespace std;
int a[10][10];
int t[10][10];
int n;
void path()
{
    int i,j,k;
    for(k = 0;k<n;k++)
    {
        for(i= 0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if((t[i][j]) || (t[i][k] && t[k][j]))
                {
                    t[i][j] = 1;

                }
            }
        }
    }
}
int main()
{
    int i,j,n;
    int d[10][10];
    cout<<"Enter no: of vertices : "<<" ";
    cin>>n;
    cout<<"Enter the adjacency matrix : "<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
            d[i][j] = a[i][j];
        }
    }
    path();
    cout<<"The Final Distance matrix is : "<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<d[i][j];
        }
        cout<<endl;
    }
    return(0);
}
