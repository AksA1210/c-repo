

#include <iostream>

using namespace std;
class ITEMS
{
    
    int itemcode[50];
    float itemprice[50];
    int count;
  public:
    void CNT(void)
    {
        count=0;
    }
    void getitem(void);
    void displaysum(void);
    void Remove(void);
    void displayitems(void);
};
void ITEMS::getitem(void)
{
    cout<<" TO ADD AN ITEM "<<endl;
    int n;
    cout<<"Enter the number of items : "<<" ";
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cout<<"Enter item code : ";
        cin>>itemcode[count];
        cout<<"Enter item cost : ";
        cin>>itemprice[count];
        count++;
    }
    
}
void ITEMS::displaysum(void)
{
    cout<<" TO DISPLAY TOTAL VALUE "<<endl;
    float sum=0;
    for (int i=0; i<count; i++)
    {
        sum=sum+itemprice[i];
    }
    cout<<"Total value : "<<sum<<endl;
}
void ITEMS::Remove(void)
{
   cout<<" TO DELETE AN ITEM "<<endl;
   int a;
   cout<<"Enter item code : "<<" ";
   cin>>a;
   for(int i=0;i<count;i++)
   {
       if (itemcode[i]==a)
       {
           itemcode[i]=0;
           itemprice[i]=0;
           cout<<"Item deleted"<<endl;
       }
       else
       {
           cout<<"Code not found"<<endl;
       }
   }
}
void ITEMS::displayitems(void)
{
    cout<<" TO DISPLAY ALL ITEMS "<<endl;
    for (int i=0;i<count;i++)
    {
        cout<<" "<<"Code :   "<<itemcode[i]<<endl;
        cout<<" "<<"Price :  "<<itemprice[i]<<endl;
        cout<<"\n";
    }
}
int main()
{
    ITEMS order;
    order.CNT();
    int x;
    do
    {
        cout<<"You can do the following  "<<endl;
        cout<<"1 : Adding items to the shopping list "<<endl;
        cout<<"2 : Deleting items from the shopping list "<<endl;
        cout<<"3 : Display the total no: of items  "<<endl;
        cout<<"4 : Display the total value of an order "<<endl;
        cout<<"5 : Quit "<<endl;
        cout<<endl;
        cout<<"\n\nEnter your choice : "<<" ";
        cin>>x;
        switch(x)
        {
            case 1: order.getitem();
            break;
            case 2: order.Remove();
            break;
            case 3: order.displayitems();
            break;
            case 4: order.displaysum();
            break;
            case 5: break;
            default:cout<<"Error ! Please try again "<<endl;
        }
        char a;
        if (x!=4)
        {
        cout<<"Do you want to continue(y/n)?"<<" ";
        cin>>a;
        if (a=='n')
        {
            x=4;
        }
        }
    } while (x!=4);
    
    return(0);
}
  

