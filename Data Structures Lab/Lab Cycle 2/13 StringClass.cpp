#include <iostream>
#include<cstring>
using namespace std;
void SUBSTRING(string STR , int E_P , int E_L)
{
    int n = STR.length();
    char str[n+1];
    strcpy(str,STR.c_str());
    char SUB[E_L];
    int count;
    for(count=0;count<E_L;count++)
    {   
        SUB[count] = STR[E_P+count-1];
    }
    SUB[count]= '\0';
    cout<<"\n\tSUBSTRING : "<<SUB;
}
string insert(string STR, int E_p, string SUB)
{
    int i;
    int j = 0;
    int len_str  = STR.length();
    SUB = SUB+" ";
    int len_sub = SUB.length();
    int total = len_str+len_sub+1;
    char str[total];
    strcpy(str,STR.c_str());
    char Sub[len_sub+1];
    strcpy(Sub , SUB.c_str());
    string tep=STR;
    char temp[total];
    strcpy(temp , tep.c_str());
    for(i=E_p;i<len_sub+E_p;i++)
    {
        str[i] = Sub[j];
        j++;
    }
    for(i=E_p+len_sub,j=E_p;i<(len_str+len_sub+1);i++)
    {
        str[i] = temp[j];
        j++;
    }
    cout<<"\n\tSTRING : "<<str<<endl;
    return(string(str));
}
string del(string STR, int pos , int len )
{
    int nm = pos+len;
    int n = STR.length();
    char str[n+1];
    strcpy(str,STR.c_str());
    string tep=STR;
    char temp[n+1];
    strcpy(temp , tep.c_str());
    for(int i=0,j=pos;j<n+1;i++)
    {
        str[j]=temp[nm];
        nm =nm+1;
        j=j+1;
    }
    return (string(str));
}
int main()
{
    int n,E_POS,E_LEN,choice,P,length, del_i,DS,OLD,POS;
    char option;
    string STR,SubS,NEW;
    cout<<"\nEnter the string : "<<" ";
    cin>>STR;
    do
    {
    cout<<"-------------------OPERATIONS ON SUBSTRING--------------------"<<endl;
    cout<<"1.Extraction"<<endl;
    cout<<"2.Insertion"<<endl;
    cout<<"3.Deletion"<<endl;
    cout<<"4.Replacement"<<endl;
    cout<<"5.Exit"<<endl;
    cout<<"Enter the choice : "<<" ";  
    cin>>choice;
    switch(choice)
    {
        case 1:
        { 
            cout<<endl;
            cout<<"Enter the position from which string has to be extracted : ";
            cin>>E_POS;
            cout<<"Enter the length of the Substring to extract : ";
            cin>>E_LEN;
            cout<<endl;
            SUBSTRING(STR, E_POS ,E_LEN);
            cout<<endl;
            break;
        }
        case 2:
        {
            cout<<"\nEnter the substring to be inserted into the string : ";
            cin>>SubS;
            cout<<"Enter the position from which the substring has to be inserted : ";
            cin>>P;
            cout<<endl<<endl;
            STR = insert(STR ,P-1,SubS);
            cout<<endl;
            break;
        }
        case 3:
        {
            cout<<"\nEnter the position from which the string have to be deleted : ";
            cin>>del_i;
            cout<<"Enter the length of string which is to be removed : ";
            cin>>DS;
            STR = del(STR , del_i-1 , DS);
            cout<<endl<<endl;
            cout<<"\n\t STRING : "<<STR;
            cout<<endl;
            break;
        }
        case 4:
        {
            cout<<"\nEnter the position from which the string have to be replaced : ";
            cin>>POS;
            cout<<"Enter the length of string to be removed : ";
            cin>>OLD;
            cout<<"Enter the substring to be inserted : ";
            cin>>NEW;
            cout<<endl;
            STR = del(STR ,POS,OLD);
            STR = insert(STR ,POS-1 ,NEW);
            cout<<endl<<endl;
            break;
        }
        case 5:
        cout<<"\n--------------------------END----------------------------"<<endl;
        break;
        default:cout<<"\nWrong choice"<<endl;
        cout<<"Please try again ! "<<endl;
    }
    if (choice != 5)
    {
        cout<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"\nDo you want to continue(y/n) ? : "<<" ";
        cin>>option;
        cout<<endl;
        if(option == 'n')
        {
            choice = 5;
        }
    }
    }while(choice!=5);
    return 0;
}
