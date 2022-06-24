#include <iostream>

using namespace std;
class bankaccount
{
    char cust_name[20];
    char acc_type[20];
    int acc_no;
    int balance;
  public:
    void getdetails()
    {
       cout<<"Enter the name of the depositor : "<<" ";
       cin>>cust_name;
       cout<<"Enter the type of account : "<<" ";
       cin>>acc_type;
       cout<<"Enter the balance amount : "<<"  ";
       cin>>balance;
       cout<<endl;
    }
    void deposit(void)
    {
        int amt;
        cout<<"Enter amount to be deposited : "<<" ";
        cin>>amt;
        balance=balance+amt;
        cout<<"-------------------Amount deposited successfully ------------------- "<<endl;
        cout<<"The total amount in your bank account is : "<<balance;
        cout<<"\n";
    }
    void withdraw(void);
    void display();
};
void bankaccount::withdraw()
{
    int Amount;
    cout<<"Enter the amount to be withdrawn : "<<" ";
    cin>>Amount;
    void getdetails();
    if (balance>=(Amount+500))
    {
        balance=balance-Amount;
        cout<<"The current bank balance in your account is : "<<balance;
        cout<<"\n";
        cout << "-------------------Amount withdrawn successfully-------------------"<<endl;
        cout<<endl;
    }
    else
    {
        cout<<"Insufficient bank balance "<<endl;
    }
}
void bankaccount::display()
{
    cout<<"The name of the depositor is : "<< cust_name;
    cout<<"\n";
    cout<<"The type of the account is : "<< acc_type;
    cout<<"\n";
    cout<<"The balance amount is : "<< balance;
    cout<<"\n";
    cout<<endl;
}
int main()
{
    bankaccount *customer=new bankaccount[100];
    int i=0;
    int x;
    int n;
    int acc_no;
    int count;
    do
    {
        cout<<"You can do the following : "<<endl;
        cout<<"Enter appropriate number : "<<endl;
        cout<<"1 : INPUT THE DETAILS OF THE CUSTOMER "<<endl;
        cout<<"2 : DISPLAY THE DETAILS OF THE BANK ACCOUNT"<<endl;
        cout<<"3 : DEPOSIT MONEY IN THE BANK ACCOUNT  "<<endl;
        cout<<"4 : WITHDRAW MONEY FROM THE BANK ACCOUNT "<<endl;
        cout<<"5 : QUIT "<<endl;
        cout<<endl;
        cout<<"\n\nWhat is your option ?"<<" ";
        cin>>x;
	    if(x==1)
        {
            customer[i].getdetails();
            cout<<"Account number : "<<i<<endl;
            i=i+1;
            cout<<endl;
        }
        else
        {
            cout<<"Enter account number : "<<" ";
            cin>>acc_no;
            if(acc_no>(i-1))
            {
                cout<<"This account doesn't exist"<<endl;
            }
            else
            {
                switch(x)
                {
                    case 2:customer[acc_no].display();
                    break;
                    case 3:
                    customer[acc_no].deposit();
                    break;
                    case 4:
                    customer[acc_no].withdraw();
                    break;
                    case 5: break;
                    default:cout<<"Error ! Please try again "<<endl;
                }
            }

            char a;
            if (x!=5)
            {
                cout<<"Do you want to continue(y/n)? : "<<" ";
                cin>>a;
                if (a=='n')
                {
                   x=5;
                }
            }
        }

      } while (x!=5);

    return(0);
}
