#include<iostream>
using namespace std;
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
int main()
{
    char choice;
    int N;
    do
    {
        cout<<"--------------------INSERTION SORT--------------------"<<endl;
        cout<<"Enter the number of elements : "<<" ";
        cin>>N;
        int DATA[N];
        for(int i=0;i<N;i++)
        {
            cout<<"Enter the element : "<<" ";
            cin>>DATA[i];
        }
        cout<<"Before Sorting : "<<" ";
        for(int i=0;i<N;i++)
        {
            cout<<DATA[i]<<"  ";
        }
        cout<<endl;
        insertion_sort(DATA,N);
        cout<<endl;
        cout<<"Do you want to continue(y/n)? : "<<" ";
        cin>>choice;
    } while (choice!='n');
    return(0);
}

