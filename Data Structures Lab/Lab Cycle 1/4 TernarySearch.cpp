#include<iostream>
#include<cmath>
using namespace std;
int ternary_search(int DATA[],int N,int ITEM,int LOC)
{
    int BEGIN=0;
    int END=N-1;
    while(BEGIN<=END)
    {
        int MID1=BEGIN+floor((END-BEGIN)/3);
        int MID2=BEGIN+floor(2*(END-BEGIN)/3);
        if (ITEM==DATA[MID1])
        {
            return (MID1);
        }
        else if (ITEM==DATA[MID2])
        {
            return (MID2);
        }
        else if (ITEM<DATA[MID1])
        {
            END=MID1-1;
        }
        else if (ITEM>DATA[MID2])
        {
            BEGIN=MID2+1;
        }
        else
        {
            BEGIN=MID1+1;
            END=MID2-1;
        }
    }
    return(-1);
}
int main()
{
    char choice;
    int ITEM,LOC,num;
    cout<<"--------------------TERNARY SEARCH--------------------"<<endl;
    cout<<"Enter the no: of elements : "<<" ";
    cin>>num;
    int DATA[num];
    for(int i=0;i<num;i++)
    {
        cout<<"Enter the element : "<<" ";
        cin>>DATA[i];
    }
    cout<<endl;
    cout<<"The elements are : "<<" ";
    for(int i=0;i<num;i++)
    {
        cout<<DATA[i]<<"   ";
    }
    cout<<endl<<endl;
    do
    {
        cout<<"Enter the item to be searched : "<<" ";
        cin>>ITEM;
        int t = ternary_search(DATA,num,ITEM,LOC);
        if (t==-1)
        {
            cout<<"Element not found"<<endl;
        }
        else
        {
            cout<<"Element is found at index number : "<<t<<endl;
        }
        cout<<endl;
        cout<<"Do you want to continue(y/n)? : "<<" ";
        cin>>choice;
    } while (choice!='n');
    return(0);
}