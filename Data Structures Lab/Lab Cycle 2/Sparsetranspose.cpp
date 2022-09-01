#include<iostream>
using namespace std;

void inv(int B1[][3], int B2[][3])
{

    // for(int i=0; i<7; i++){
    //     for(int j=0; j<3; j++){
    //         cout<<B1[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

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
    
    int B1[][3] = {{5,6,6},{0,4,9},{1,1,8},{2,0,4},{2,3,2},{3,5,5},{4,2,2}};
    int B2[7][3];

    inv(B1,B2);

    cout<<"\nTranspose : \n";
    for(int i=0; i<7; i++){
        for(int j=0; j<3; j++){
            cout<<B2[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
