#include<iostream>
using namespace std;
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
int main()
{
    char choice;
    int N;
    do
    {
        cout<<"--------------------SELECTION SORT--------------------"<<endl;
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
        selection_sort(DATA,N);
        cout<<endl;
        cout<<"Do you want to continue(y/n)? : "<<" ";
        cin>>choice;
    } while(choice!='n');
    return(0);
}
