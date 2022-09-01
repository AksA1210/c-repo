#include<iostream>
#include<iomanip>
using namespace std;

void transpose(int B1[][3], int B2[][3])
{
     cout<<"The input matrix is : "<<endl;
     for(int i=0; i<7; i++){
         for(int j=0; j<3; j++){
             cout<<setw(4)<<B1[i][j]<<" ";
         }
         cout<<endl;
     }

    B2[0][0] = B1[0][1];
    B2[0][1] = B1[0][0];
    B2[0][2] = B1[0][2];

    
    int k = 1;
    int n = B1[0][2];

    
    for(int i=0; i<B1[0][1]; i++){
        for(int j=1; j<=n; j++){
            if(i == B1[j][1]){
                B2[k][0] = B1[j][1];
                B2[k][1] = B1[j][0];
                B2[k][2] = B1[j][2];
                k = k+1;
            }
        }
    }
    
}

int main()
{
    
    int A[][3] = {{5,6,6},{0,4,9},{1,1,8},{2,0,4},{2,3,2},{3,5,5},{4,2,2}};
	
    int T[7][3];

    transpose(A,T);

    cout<<"\nTranspose : \n";
    for(int i=0; i<7; i++){
        for(int j=0; j<3; j++){
            cout<<setw(4)<<T[i][j]<<" ";
        }
        cout<<endl;
    }

    return (0);
}

