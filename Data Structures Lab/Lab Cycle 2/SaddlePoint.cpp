#include<iostream>
#include<iomanip>
using namespace std;

int saddle_point(int** A,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        int min=A[i][0];
        int column_index=0;
        for(int j=0;j<n;j++)
        {
            if(min>A[i][j])
            {
                min=A[i][j];
                column_index=j;
            }
        }
        int k = 0;
        while(k<m && A[k][column_index] <= min)
        {
            k++;
        }
        if(k==m-1)
        {
            return A[k][column_index] ; 
        }
    }
    return (-1);
}
int main()
{
    char ch;
    do
    {
         int r,c;
        int **A;
        A = new int *[r];
        cout<<"Enter the no: of rows : "<<" ";
        cin>>r;
        cout<<"Enter the no: of columns : "<<" ";
        cin>>c;
        for (int i = 0;i < r;i++) 
        {
		    A[i] = new int[c];
	    }
        cout<<"Input the elements of the matrix : "<<endl;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>A[i][j];
            }
        }
        cout<<"MATRIX = "<<endl;
        cout<<"\t\t"<<endl;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout<<setw(4)<<A[i][j]<<" ";
            }
            cout<<endl;
        }
        int s=saddle_point(A,r,c);
        if (s==-1)
        {
            cout<<"No saddle point"<<endl;
        }
        else
        {
            cout<<"\nSaddle point of the matrix = "<<s<<endl;
        }
        cout<<"Do you want to continue (y/n)? : "<<" ";
        cin>>ch;
       
    } while (ch!='n');
    return(0);
}
