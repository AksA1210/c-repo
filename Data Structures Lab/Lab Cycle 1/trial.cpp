#include<iostream>
#include<cmath>
using namespace std;
int linear_search(int DATA[],int N,int ITEM,int LOC)
{  cout<<"Enter the item to be located : "<< "  ";
    cin>>ITEM;
    int K;
    while (LOC=-1 && K<=N)
    {
        if  (DATA[K]==ITEM)
        {
            LOC=K;
            return(LOC);
        }
        K++;
    }
    return(-1);
}

int binary_search(int DATA[],int N,int ITEM)
{
    cout<<"Enter the item to be searched : "<<" ";
    cin>>ITEM;
    int LEFT=0;
    int RIGHT=N-1;
    while(LEFT<=RIGHT)
    {
        int MID=floor((LEFT+RIGHT)/2);
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
    return (-1);
}    
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
            int LOC=MID1;
            return (LOC);
        }
        else if (ITEM==DATA[MID2])
        {
            int LOC=MID2;
            break;
        }
        else if (ITEM<DATA[MID1])
        {
            END=MID1-1;
            break;
        }
        else if (ITEM>DATA[MID2])
        {
            BEGIN=MID2+1;
            break;
        }
        else
        {
            BEGIN=MID1+1;
            END=MID2-1;
        }
    }
    return(-1);
}
int inter_search(int DATA[],int N,int ITEM)
{
    int BEGIN=0;
    int END=N+2;
    int POS;
    while(BEGIN<=END && ITEM>=DATA[BEGIN]&& ITEM<=DATA[END])
    {
        POS=BEGIN+((ITEM-DATA[BEGIN])/(DATA[END]-DATA[BEGIN])) * (END-BEGIN);
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
    return(-1);
}


int fib_search(int DATA[],int N,int ITEM,int LOC)
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
        else if (DATA[i]>ITEM)
        {
            f=f1;
            f2=f2-f1;
            f1=f-f2;
        }
        else
        {
            LOC=i;
            return(LOC);
        }
    }
    if(f==1 && DATA[p+1]==ITEM)
    {
        LOC=p+1;
    }
    return(-1);    
}
void display(int DATA[],int N)
{
    cout<<"The elements are : "<<" ";
    for(int i=0;i<N;i++)
    {
        cout<<DATA[i]<<"  ";
    }
}

int main()      //Menu
{
    int choice,ITEM,LOC;
    int num;
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
    do{
    cout<<"\n------------------------SEARCH METHODS----------------";
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
          
            int l=linear_search(DATA,num,ITEM,LOC);
            if (l==-1)
           {
               cout<<"ITEM not found"<<endl;
           }
        else
        {
            cout<<"ITEM ("<<DATA[l]<<") is present at index number "<<l <<endl;
        }
			 break;
        }
       
        case 2:
        {
            int ITEM;
            int LOC=binary_search(DATA,num,ITEM);
            cout<<"The element is found at index no. "<<LOC<<"  " <<endl;
			break;
        }
        
        case 3:
        {
            int BEGIN,END;
             cout<<"Enter the item to be searched : "<<" ";
    cin>>ITEM;
    int t=ternary_search(DATA,num,ITEM,LOC);
    if (t==-1)
    {
        cout<<"Element not found"<<endl;
    }
    else
    {
        cout<<"Element is found at index number : "<<t<<endl;
    }
	 break;
	 }
        
       
        case 4:
        {
            int BEGIN,END;
	        cout<<"Enter the item to be searched : "<<" ";
            cin>>ITEM;
            int i=inter_search(DATA,num,ITEM);
            if (i==-1)
            {
                cout<<"Element not found"<<endl;
            }
            else
            {
                cout<<"Element is found at index number : "<<i<<endl;
            }
            break;   
        }
        case 5:
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
            break;
        }
        
        case 6:
        {
            display(DATA,num);
            break;
        }
        case 7:
        break;
        default:
			cout<<("Wrong choice\n");
	}		
       char p;
    if(choice!=7)
    {
        cout<<"\nDo you want to continue(y/n) ?  : "<<" ";
        cin>>p;
        if (p=='n')
        {
            choice=7;
        }
    }
    }while(choice!=7);
    return(0);   
    
}
//new
#include<iostream>
#include<cmath>
using namespace std;
int linear_search(int DATA[],int N,int ITEM,int LOC)
{  cout<<"Enter the item to be located : "<< "  ";
    cin>>ITEM;
    int K;
    while (LOC=-1 && K<=N)
    {
        if  (DATA[K]==ITEM)
        {
            LOC=K;
            return(LOC);
        }
        K++;
    }
    return(-1);
}

int binary_search(int DATA[],int N,int ITEM)
{
    cout<<"Enter the item to be searched : "<<" ";
    cin>>ITEM;
    int LEFT=0;
    int RIGHT=N-1;
    while(LEFT<=RIGHT)
    {
        int MID=floor((LEFT+RIGHT)/2);
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
    return (-1);
}    
int ternary_search(int DATA[],int N,int ITEM,int LOC)
{
    int BEGIN=0;
    int END=N;
    while(BEGIN<=END)
    {
        int MID1=BEGIN+floor((END-BEGIN)/3);
        int MID2=BEGIN+floor(2*(END-BEGIN)/3);
        if (ITEM==DATA[MID1])
        {
            int LOC=MID1;
            return (LOC);
            break;
        }
        else if (ITEM==DATA[MID2])
        {
            int LOC=MID2;
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
int inter_search(int DATA[],int N,int ITEM)
{
    int BEGIN=0;
    int END=N+2;
    int POS;
    while(BEGIN<=END && ITEM>=DATA[BEGIN]&& ITEM<=DATA[END])
    {
        POS=BEGIN+((ITEM-DATA[BEGIN])/(DATA[END]-DATA[BEGIN])) * (END-BEGIN);
        if (ITEM==DATA[POS])
        {
            return(POS);
            break;
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
    return(-1);
}


int fib_search(int DATA[],int N,int ITEM,int LOC)
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
        else if (DATA[i]>ITEM)
        {
            f=f1;
            f2=f2-f1;
            f1=f-f2;
        }
        else
        {
            LOC=i;
            return(LOC);
        }
    }
    if(f==1 && DATA[p+1]==ITEM)
    {
        LOC=p+1;
    }
    return(-1);    
}
void display(int DATA[],int N)
{
    cout<<"The elements are : "<<" ";
    for(int i=0;i<N;i++)
    {
        cout<<DATA[i]<<"  ";
    }
}

int main()      //Menu
{
    int choice,ITEM,LOC;
    int num;
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
    do{
    cout<<"\n------------------------SEARCH METHODS----------------";
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
          
            int l=linear_search(DATA,num,ITEM,LOC);
            if (l==-1)
           {
               cout<<"ITEM not found"<<endl;
           }
        else
        {
            cout<<"ITEM ("<<DATA[l]<<") is present at index number "<<l <<endl;
        }
			 break;
        }
       
        case 2:
        {
            int ITEM;
            int LOC=binary_search(DATA,num,ITEM);
            cout<<"The element is found at index no. "<<LOC<<"  " <<endl;
			break;
        }
        
        case 3:
        {
            int BEGIN,END;
             cout<<"Enter the item to be searched : "<<" ";
    cin>>ITEM;
    int t=ternary_search(DATA,num,ITEM,LOC);
    if (t==-1)
    {
        cout<<"Element not found"<<endl;
    }
    else
    {
        cout<<"Element is found at index number : "<<t<<endl;
    }
	 break;
	 }
        
       
        case 4:
        {
            int BEGIN,END;
	        cout<<"Enter the item to be searched : "<<" ";
            cin>>ITEM;
            int i=inter_search(DATA,num,ITEM);
            if (i==-1)
            {
                cout<<"Element not found"<<endl;
            }
            else
            {
                cout<<"Element is found at index number : "<<i<<endl;
            }
            break;   
        }
        case 5:
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
            break;
        }
        
        case 6:
        {
            display(DATA,num);
            break;
        }
        case 7:
        break;
        default:
			cout<<("Wrong choice\n");
	}		
       char p;
    if(choice!=7)
    {
        cout<<"\nDo you want to continue(y/n) ?  : "<<" ";
        cin>>p;
        if (p=='n')
        {
            choice=7;
        }
    }
    }while(choice!=7);
    return(0);   
    
}

 


