#include<iostream>
//#include<cmath>
using namespace std;
int binary_search(int DATA[],int N,int ITEM)
{
    for(int i =0;i<N;i++)
    {
        int LEFT=0;
        int RIGHT=N-1;
        int MID=(LEFT+RIGHT)/2;
        if (ITEM==DATA[MID])
        {
            return(MID);
        }
        else if (DATA[MID]>ITEM)
        {
            RIGHT=MID-1;
        }
        else
        {
            LEFT=MID+1;
        }
    }
    return(-1);
}
int main()
{
    char choice;
    int value,num;
    cout<<"-------------------BINARY SEARCH-------------------"<<endl;
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
        cout<<"Enter the item to be searched : "<<" ";
        cin>>value;
        int b = binary_search(DATA,num,value);
        if (b==-1)
        {
            cout<<"ITEM not found"<<endl;
        }
        else
        {
            cout<<"ITEM ("<<DATA[b]<<") is present at index number "<<b <<endl;
        }
        cout<<endl;
        cout<<"Do you want to continue(y/n)? : "<<" ";
        cin>>choice;
        cout<<"\n-----------------------------------------------------"<<endl;
    } while (choice!='n');
    return(0);
}