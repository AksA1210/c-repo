#include<iostream>
using namespace std;
class items
{
    int code[50];
    double price[50];
    string name[50];
    int num,cost;
    public:
    void number(void)
    {
        num=0;
        
    }
    void item(void)
    {
        cost=0;
        
    }
    void input()
    {
        cout<<"\nEnter the code of the item : ";
        cin>>code[num];
        cout<<"Enter the name of the item : ";
        cin>>name[num];
        cout<<"Enter the price : ";
        cin>>price[num];
        num++;
    }
    void output(void)
    {
        cout<<"\n  Code    :  "<<endl;
        cout<<"\n  Name  :  "<<endl;
        cout<<"\n  Price :  "<<endl;
        for(int i=0;i<num;i++)
        {
            cout<<code[i]<<" "<<endl;
            cout<<name[i]<<" "<<endl;
            cout<<price[i]<<" "<<endl;
        }
    }
    void deletes(void);
    void summing(int);
    void bill(int );
    
    
};
int num;
items list[50];
void items::deletes(void)
{
	int rcode=0;

    int a;
    cout<<"\n\n Enter the code to delete : ";
    cin>>a;
	for(int i=0;i<num;i++)
	{
	    if(code[i]==a)
        {
            rcode=i;
            for(int i=rcode;i<num;i++)
            {
	            price[i]=price[i+1];
	            code[i]=code[i+1];
                    name[i]=name[i+1];
                num--;
                cout<<" You have removed the item from stock\n\n";
            }
            break;
        }
	}
    if(rcode==0)
    {
        cout<<" This item does not exist\n";
        
    }
}    
	
void items::summing(int customer)
{
    for(int i=0;i<num;i++)
    {
        if(code[i]==customer)
        {
            cost+=price[i];
                
        }
            
    }
}
void items:: bill(int customer)
{
    cout<<"Enter the code of the item"<<endl;
    for(int i=0;i<num;i++)
    {
        if(code[i]==customer)
        {
           cout<<"\n\n The total price : "<<cost<<"\n\n";
        }
    }    
}


int main()
{
    int ch;
    do
    {    
        items order1;
        order1.number();
        order1.item();
        cout<<"1.ADDING AN ITEM TO THE STOCK " <<endl;
        cout<<"2.DELETING AN ITEM FROM THE STOCK"<<endl;
        cout<<"3.DISPLAY ITEMS AVAILABLE"<<endl;
        cout<<"4.PURCHASE AN ITEM FROM THE STOCK"<<endl;
        cout<<"5.DISPLAY THE BILL"<<endl;
	cout<<"6.QUIT"<<endl;
	cout<<"\n\n Enter your choice : "<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            int items;
            cout<<"\n Enter the number of items to stock : ";
	    cin>>items;
            for(int i=0;i<items;i++)
            {
                order1.input();
            }
            break;
            case 2:
            {
                order1.deletes();
                
            }
            break;
            case 3:
            {
                order1.output();
            }
            break;
            case 4:
            {
                int items_no;
                cout<<"\n Enter the number of items to buy : ";
	        cin>>items_no;
                int list[items_no];
                for(int i=0;i<items_no;i++)
                {
                    cout<<"\n Enter the 3-digit code of item "<<i+1<<" : ";
		    cin>>list[i];
                    order1.summing(list[i]);
                }
            }
            break;
            case 5:
            {
                int k;
                order1.bill(k);
                cout<<" Item code  "<<" Item name "<<" Unit Price "<<" Quantity "<<" Total Price "<<endl;
                for(int i=0;i<items;i++)
                {
                    cout<<code[i] << name[i]<<price[i]<<n<<;
                }
                
                
            }
            break;
            case 6:
            {
                cout<<" You have entered a wrong option "<<endl;
                break;
            }
            
        }
        char a;
        if (ch!=6)
        {
            cout<<"Do you want to continue(y/n)?"<<" ";
            cin>>a;
            if (a=='n')
            {
                ch=6;
            }
        }
    }while (ch!=6);
    
    return(0);

}

