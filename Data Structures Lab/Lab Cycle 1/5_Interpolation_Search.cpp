#include<iostream>
#include<cmath>
using namespace std;
int inter_search(int DATA[],int N,int ITEM)
{
    int BEGIN=0;
    int END=N-1;
    while(BEGIN<=END && ITEM >= DATA[BEGIN] && ITEM<=DATA[END])
    {
        int POS=BEGIN+((ITEM-DATA[BEGIN])*(END-BEGIN))/(DATA[END]-DATA[BEGIN]);
        cout<<"Position : "<<POS<<endl;
        if (ITEM==DATA[POS])
        {
            return(POS);
        }
        else if(ITEM>DATA[POS])
        {
            BEGIN=POS+1;
        }
        else
        {
            END=POS-1;
        }
    }
    return -1;
}
int main()
{
    char choice;
    int ITEM,LOC,num;
    cout<<"----------------INTERPOLATION SEARCH----------------"<<endl;
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
        cin>>ITEM;
        int i = inter_search(DATA,num,ITEM);
        if (i==-1)
        {
            cout<<"Element not found"<<endl;
        }
        else
        {
            cout<<"Element is found at index number : "<<i<<endl;
        }
        cout<<endl;
        cout<<"Do you want to continue(y/n)? : "<<" ";
        cin>>choice;
        cout<<"----------------------------------------------------"<<endl;
    } while (choice!='n');
    return(0);
}
