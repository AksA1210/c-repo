#include<iostream>
using namespace std;
int linear_search(int DATA[],int N,int ITEM)
{
    for(int K = 0; K < N; K++)
    {
        if  (DATA[K]==ITEM)
        {
            return(K);
        }
    }
    return(-1);
}
int main()
{
    char choice;
    int ITEM,LOC,num;
    cout<<"--------------------LINEAR SEARCH--------------------"<<endl;
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
    do
    {
        cout<<"\nEnter the item to be located : "<< "  ";
        cin>>ITEM;
        int LOC = linear_search(DATA,num,ITEM);
        if (LOC==-1)
        {
            cout<<"ITEM not found"<<endl;
        }
        else
        {
            cout<<"ITEM ("<<DATA[LOC]<<") is present at index number "<< LOC <<endl;
        }
        cout<<endl;
        cout<<"Do you want to continue(y/n)? : "<<" ";
        cin>>choice;
        cout<<"\n--------------------------------------------------------------"<<endl;
    } while (choice!='n');
    return(0);
}
