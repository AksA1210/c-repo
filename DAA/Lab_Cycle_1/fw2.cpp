#include<iostream>
using namespace std;
int a[10][10];
int t[10][10];
int n;
#define INF 9999
void path()
{
    int i,j,k;
    for(k = 0;k<n;k++)
    {
        for(i= 0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if (t[i][k] + t[k][j] < t[i][j])
                {
                    t[i][j] = t[i][k] + t[k][j];
                }   
            }
        }
    }
    cout<<"The Final Distance matrix is : "<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if (t[i][j] == INF)
            {
                cout<<"INF"<<" ";
            }
            else
            {
               cout<<t[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}
int main()
{
    int i,j,n;
    int d[10][10];
    cout<<"Enter no: of vertices : "<<" ";
    cin>>n;
    int a[n][n] = { { 0, 5, INF, 10 },
                    { INF, 0, 3, INF },
                    { INF, INF, 0, 1 },
                    { INF, INF, INF, 0 } 
                };
    path();
    return(0);
}
