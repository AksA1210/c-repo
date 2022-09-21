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
int main()
{
    char choice;
    int N;
    do
    {
        cout<<"--------------------BUBBLE SORT--------------------"<<endl;
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
        bubble_sort(DATA,N);
        cout<<endl;
        cout<<"Do you want to continue(y/n)? : "<<" ";
        cin>>choice;
    } while (choice!='n');
    return(0);
}
