//Failed to modify
#include<iostream>
using namespace std;
void Insert(int DATA[],int N,int k,int ITEM)
{
  int j=N;
  while(j>=k-1)
  {
      DATA[j+1]=DATA[j];
      j--;
  }
  DATA[k-1]=ITEM;
  N++;
  cout<<"Element inserted"<<endl;
  cout<<"ARRAY AFTER INSERTION "<<endl;
  for(int i=0;i<N;i++)
  {
     cout<<DATA[i]<<" ";
  }
  cout<<endl;
}    
void del(int DATA[],int N,int ITEM)
{
    int k;
    cout<<"Enter the position of the element which is to be deleted : "<<" ";
    cin>>k;
    ITEM=DATA[k];
    for(int j=k;j<N;j++)
    {
        DATA[j-1]=DATA[j];
    }
    N=N--;
    cout<<"Element deleted"<<endl;
    cout<<"ARRAY AFTER DELETION"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<DATA[i]<<" ";
    }
    cout<<endl;

}
int main()
{
    int ch,n,k,l,o,d;
    char p;
    cout<<"Enter the number of elements : " <<" ";
    cin>>n;
    int DATA[n];
    do
    {
        cout<<"---------------ARRAY OPERATIONS----------------"<<endl;
        cout<<"1.Add"<<endl;
        cout<<"2.Insert"<<endl;
        cout<<"3.Delete"<<endl;
        cout<<"4.Display"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter your choice : "<<" ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                for(int i=0;i<n;i++)
                {
                    cout<<"Enter the element : "<<" ";
                    cin>>DATA[i];
                }
                break;
            }
           
            case 2:
            {
                int num;
                cout<<"Enter the number of elements to be inserted : "<<" ";
                cin>>num;
                for(int i=0;i<num;i++)
                {
                    cout<<"Enter the position : "<< " ";
                    cin>>k;
                    cout<<"Enter the element : "<<" ";
                    cin>>l;
                    Insert(DATA,n+i+1,k,l);
                }
                break;
            }
            case 3:
            {
                cout<<"Enter the element to be deleted : "<<" ";
                cin>>l;
                del(DATA,n,l);
                break;
            }
           
            case 4:
            {
                cout<<"ARRAY = "<<" ";
                for(int i=0;i<n;i++)
                {
                    cout<<DATA[i]<<"  ";
                }
                cout<<endl;
                break;
            }
            
            case 5:
            break;
            default:cout<<"Error ! Please try again "<<endl;
            break;
        }
        if (ch!=5)
        {
          cout<<"Do you want to continue(y/n)? : "<<" ";
          cin>>p;
          if (p=='n')
          {
              ch=5;
          }
       }
    } while (ch!=5);
    
    return(0);
  
    
}
