
#include<iostream>
#include<cmath>
using namespace std;
void linear_search(DATA,N,ITEM,LOC)
{
    cout<<"Enter the item to be located : "<<endl;
    cin>>ITEM;
    while (LOC=NULL && K<=N)
    {
        if  DATA[K]==ITEM
        {
            LOC=K;
        }
        K++;
    }
    if (LOC==NULL)
    {
        cout<<"ITEM not found"<<endl;
    }
    else
    {
        cout<<"ITEM is present at",LOC," ",DATA[LOC]<<endl;
    }
}

void binary_search(int DATA[],int LB,int UB,int ITEM,int LOC)
{
    int BEGIN,END,MID;
    BEGIN=LB;
    END=UB;
    MID=floor((BEGIN+END)/2);
    while ((DATA[MID])!=ITEM && BEGIN<=END)
    {
        if (ITEM<DATA[MID])
        {
            END=MID-1;
        }
        else
        {
            BEGIN=END-1;
        }
        MID=floor((BEGIN+END)/2);
    }        
    if (DATA[MID]==ITEM)
    {
        LOC=MID;
    }
    else
    {
        LOC=-1;
    }
    
}
int ternary_search(int DATA[],int N,int ITEM,int LOC)
{
    int BEGIN=1;
    int END=N;
    while(BEGIN<=END)
    {
        int MID1=BEGIN+floor((END-BEGIN)/3);
        int MID2=BEGIN+floor(2*(END-BEGIN)/3);
        if (ITEM==DATA[MID1])
        {
            int LOC=MID1;
            break;
        }
        if (ITEM==DATA[MID2])
        {
            int LOC=MID2;
            break;
        }
        if (ITEM<DATA[MID1])
        {
            END=MID1-1;
            break;
        }
        if (ITEM>DATA[MID2])
        {
            BEGIN=MID2+1;
            break;
        }
        else
        {
            BEGIN=MID1+1;
            END=MID2-1;
        }
        return(LOC+1);
    }
   //LOC=-1;
}
int inter_search(int DATA[],int N,int ITEM,int POS)
{
    int BEGIN=0;
    int END=N;
    int LOC;
    while(BEGIN<=END && ITEM>=DATA[BEGIN]&& ITEM<=DATA[END])
    {
        POS=BEGIN+((ITEM-DATA[BEGIN])/DATA[END]-DATA[BEGIN]) * (END-BEGIN);
        if (ITEM=DATA[POS])
        {
            int LOC=POS;
        }
        if(ITEM>DATA[POS])
        {
            BEGIN=POS+1;
        }
        else
        {
            END=POS-1;
        }
    }
    return(LOC+1);
    LOC=-1;
}

void fib_search()
{
      int fib_search(int DATA[],int ITEM,int N,int LOC)
{
    int f1=0;
    int f2=1;
    int f=f1+f2;
    int p=-1;
    while(f<N)
    {
        f1=f2;
        f2=f;
        f=f1+f2;
    }
    while(f>1)
    {
        int i=p+f1;
        if (DATA[i]<ITEM)
        {
            f=f2;
            f2=f1;
            f1=f-f2;
            p=i;
        }
        if (DATA[i]>ITEM)
        {
            f=f1;
            f2=f-f1;
            f1=f-f2;
        }
        else
        {
            int LOC=i;
        }
    return(LOC);    
    }
}

    
}
void display()
{
    
}

int main()      //Menu
{
    int choice;
    //LOC=NULL;
    int num;
    cout<<"Enter the no: of elements : "<<" ";
    cin>>num;
    int DATA[num];
    for(int i=0;i<num;i++)
    {
        cin>>DATA[i];
    }
    cout<<"\nSEARCH METHODS";
    cout<<"\n1.Linear Search";
    cout<<"\n2.Binary Search";
    cout<<"\n3.Ternary Search";
    cout<<"\n4.Interpolation Search";
    cout<<"\n5.Fibonacci Search";
    cout<<"\n6.Display";
    cout<<"\n7.Exit";
    cout<<"\nEnter your choice : "<<" ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            //int BEGIN,END;
           // linear_search();
            linear_search(DATA,N,ITEM,LOC)
        }
        break;
        case 2:
        {
            int LB,UB,ITEM,LOC;
            binary_search(DATA[],LB,UB,ITEM,LOC);
        }
        break;
        case 3:
        {
            int BEGIN,END;
             cout<<"Enter the item to be searched : "<<" ";
    cin>>ITEM;
    int t=ternary_search(DATA,num,ITEM,LOC);
    if (t==0)
    {
        cout<<"Element not found"<<endl;
    }
    else
    {
        cout<<"Element is found at position number : "<<t+1<<endl;
    }
}
           // ternary_search();
        }
        break;
        case 4:
        {
            int BEGIN,END;
	 cout<<"Enter the item to be searched : "<<" ";
    cin>>ITEM;
    int i=inter_search(DATA,num,ITEM,LOC);
    if (i==0)
    {
        cout<<"Element not found"<<endl;
    }
    else
    {
        cout<<"Element is found at position number : "<<i+2<<endl;
    }

            inter_search();
        }
        break;
        case 5:
        {
            fib_search();
        }
        break;
        case 6:
        {
            display();
        }
        case 7:
        break;
        default:
			cout<<("Wrong choice\n");
       char p;
    if(choice!=7)
    {
        cout<<"\nDo you want to continue(y/n) ?  : "<<" ";
        cin>>p;
        if (p=='n')
        {
            choice=7;
        }
    }while(choice!=7);
    }
    return(0);   
    
}
