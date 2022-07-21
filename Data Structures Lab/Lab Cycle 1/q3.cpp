#include<iostream>
using namespace std;
void bubble_sort(int DATA[],int N)
{
    for(int k=0;k<N-1;k++)
    {
        for(int j=0;j<N-k-1;j++)
        {
            if (DATA[j]>DATA[j+1])
            {
                int TEMP=DATA[j+1];
                DATA[j+1]=DATA[j];
                DATA[j]=TEMP;
            }
        }
    }
    cout<<"After Bubble Sort : "<<" ";
    for(int i=0;i<N;i++)
    {
        cout<<DATA[i]<<"  ";
    }
}
void selection_sort(int DATA[],int N)
{
    for(int k=1;k<N;k++)
    {
        for(int j=1;j<N-k+1;j++)
        {
            if (DATA[j-1]>DATA[j])
            {
                int TEMP=DATA[j];
                DATA[j]=DATA[j-1];
                DATA[j-1]=TEMP;
            }
        }
    }
    cout<<"After Selection Sort : "<<" ";
    for(int i=0;i<N;i++)
    {
        cout<<DATA[i]<<"  ";
    }
}
void insertion_sort(int A[],int N)
{
    for(int k=1;k<N;k++)
    {
        int TEMP=A[k];
        int PTR=k-1;
        while (PTR>=0 && TEMP<A[PTR])
        {
            A[PTR+1]=A[PTR];
            PTR=PTR-1;
        }
        A[PTR+1]=TEMP;
    }
    cout<<"After Insertion Sort : "<<"  ";
    for(int i=0;i<N;i++)
    {
        cout<<A[i]<<"  ";
    }
}

void MERGING(int *A,int R,int LBA,int *B,int S,int LBB,int *C,int LBC)
{
    int NA=LBA,NB=LBB,PTR=LBC;
    int UBA=LBA+R-1,UBB=LBB+S-1;

    while(NA<=UBA && NB<=UBB)
    {
        if(A[NA]<B[NB])
        {
            C[PTR]=A[NA];
            NA=NA+1;
            PTR=PTR+1;
        }
        else
        {
            C[PTR]=B[NB];
            NB=NB+1;
            PTR=PTR+1;
        }
    }

    if(NA>UBA)
    {
        for(int i=0;i<=UBB-NB;i++)
        {
            C[PTR+i]=B[NB+i];
        }
    }
    else
    {
        for(int i=0;i<=UBA-NA;i++)
        {
            C[PTR+i]=A[NA+i];
        }

    }
}

void MERGE_PASS(int *A,int N,int L,int *B)
{
    int Q=N/(2*L);
    int S=2*L*Q;
    int R=N-S;
    int LB;

     for(int j= 1;j<=Q;j++)
    {
        LB=(2*j-2)*L;
        MERGING(A,L,LB,A,L,LB+L,B,LB);
    }

    if(R<=L)
    {
        for(int k=0;k<R;k++)
        {
            B[S+k]=A[S+k];
        }
    }
    else
    {
        MERGING(A,L,S,A,R-L,L+S,B,S);
    }
}

void mergesort(int *A,int *B,int N)
{
    int L=1;
    
    while(L<N)
    {
        MERGE_PASS(A,N,L,B);
        MERGE_PASS(B,N,2*L,A);
        L=4*L;
    }
    cout<<"After Sorting : "<<"  ";
    for(int i =0; i<N;i++)
    {
        cout<<A[i]<<"  ";
    }


}
int main()
{
    int choice;
    int N;
    cout<<"Enter the number of elements : "<<" ";
    cin>>N;
    int DATA[N];
    for(int i=0;i<N;i++)
    {
        cout<<"Enter the element : "<<" ";
        cin>>DATA[i];
    }
    for(int i=0;i<N;i++)
    {
        cout<<DATA[i]<<"  ";
    }
    do
    {
        cout<<"\n----------------------SORTING TECHNIQUES--------------------------"<<endl;
    cout<<"\n1.Bubble Sort";
    cout<<"\n2.Selection Sort";
    cout<<"\n3.Insertion Sort";
    cout<<"\n4.Merge Sort";
    cout<<"\n5.Exit";
    cout<<"\nEnter your choice : "<<" ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            cout<<"Before Sorting : "<<" ";
            for(int i=0;i<N;i++)
            {
                cout<<DATA[i]<<"  ";
            }
            cout<<endl;
            bubble_sort(DATA,N);
            break;

        }
        case 2:
        {
            cout<<"Before Sorting : "<<" ";
            for(int i=0;i<N;i++)
            {
                cout<<DATA[i]<<"  ";
            }
            cout<<endl;
            selection_sort(DATA,N);
            break;

        }
        case 3:
        {
            cout<<"Before Sorting : "<<" ";
            for(int i=0;i<N;i++)
            {
                cout<<DATA[i]<<"  ";
            }
            cout<<endl;
            insertion_sort(DATA,N);
            break;

        }
        case 4:
        {
            int B[N];
            cout<<"Before Sorting : "<<" ";
            for(int i=0;i<N;i++)
            {
                cout<<DATA[i]<<"  ";
            }
            cout<<endl;
            mergesort(DATA,B,N);
            break;
        }
        case 5:
        {
             break;
        }
        default:cout<<("Wrong choice\n");
    }
    char p;
    if(choice!=5)
    {
        cout<<"\nDo you want to continue(y/n) ? : "<<" ";
        cin>>p;
        if (p=='n')
        {
            choice=5;
        }
    }
    }while(choice!=5);
    return(0);
}
