//Floyd Warshall
//without user input
//hard coded
#include<iostream>
using namespace std;
#define INF 99999
#define num 4
void floyd_warshall(int A[][num])
{
    int i,j,k;
    for(k = 0;k<num;k++)
    {
        for(i= 0;i<num;i++)
        {
            for(j=0;j<num;j++)
            {
                if(A[i][j] > (A[i][k] + A[k][j]) && A[k][j]!= INF && A[i][k] != INF)
                {
                    A[i][j] = A[i][k] + A[k][j];

                }
            }
        }
    }
}

int main()
{
    int i,j,no_of_vertices;
    //cout<<"Enter no: of vertices : "<<" ";
    //cin>>no_of_vertices;
    /*cout<<"Enter the adjacency matrix : "<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
            d[i][j] = a[i][j];
        }
    }*/
    int M[num][num] = {{0 , 5 , INF ,10},
                        {INF , 0 , 3 , INF },
                        {INF, INF , 0 , 1},
                        {INF , INF ,INF , 0 }};
    cout<<"The Input matrix is : "<<endl;
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            if (M[i][j] == INF)
            {
                cout<<"INF"<<"   ";
            }    
            else
            {
                cout<< M[i][j]<<"   ";
            }
        }
        cout<<endl;  
    }                      
    floyd_warshall(M);
    cout<<"The Final Distance matrix is : "<<endl;
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            if (M[i][j] == INF)
            {
                cout<<"INF"<<"  ";
            }    
            else
            {
                cout<< M[i][j]<<"   ";
            }
        }
        cout<<endl;
    }
    return(0);
}    
