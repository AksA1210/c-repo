#include<iostream>
using namespace std;
int fib_search(int DATA[],int N,int ITEM,int LOC)
{
    int f2 = 0;
    int f1 = 1;
    int f = f1+f2;
    int offset = -1;
    while(f<=N)
    {
        f2 = f1;
        f1 = f;
        f = f1+f2;
    }
    while(f>1)
    {
        int i = offset + f2;
        if (DATA[i]<ITEM)
        {
            f = f1;
            f1 = f2;
            f2 = f-f1;
            offset = i;
        }
        else if (DATA[i]>ITEM)
        {
            f = f2;
            f1 = f1-f2;
            f2 = f-f1;
        }
        else
        {
            LOC=i;
            return(LOC);
        }
    }
    return(-1);    
}
int main()
{
    char choice;
    int ITEM,LOC,num;
    cout<<"-------------------FIBONACCCI SEARCH-------------------"<<endl;
    cout<<"Enter the no: of elements : "<<" ";
    cin>>num;
    int DATA[num];
    for(int i=0;i<num;i++)
    {
        cout<<"Enter the element : "<<" ";
        cin>>DATA[i];
    }
    cout<<"The elements are : "<<" ";
    for(int i=0;i<num;i++)
    {
        cout<<DATA[i]<<"   ";
    }
    cout<<endl;
    do
    {
        cout<<"Enter item to be searched : "<<" ";
        cin>>ITEM;
        int f=fib_search(DATA,num,ITEM,LOC);
        if (f==-1)
        {
            cout<<"Element not found"<<endl;
        }
        else
        {
            cout<<"Element is found at index number : "<<f<<endl;
        }
        cout<<endl;
        cout<<"Do you want to continue(y/n)? : "<<" ";
        cin>>choice;
    } while (choice!='n');
    return(0);
}
