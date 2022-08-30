//Pattern Matching
#include<iostream>
#include<cstring>
using namespace std;
int matching(char txt[],int len_t,char ptn[],int len_p)
{
    int k=1 ;
    int max=len_t-len_p+1;
    while (k<=max)
    {
        for(int i=0 ;i<len_p;i++)
        {
            if (ptn[i]!= txt[k+i])
            {
                k++;
            }
            else
            {
                int index = k;
                return k;
            }
        }
        k++;
    }
    return -1;
}
int main()
{
    char txt[10];
    char ptn[8];
    int lent,lenp,x;
    char ch;
    do
    {
        cout<<"Enter the text : ";
        cin>>txt;
        cout<<"Enter the pattern : ";
        cin>>ptn;
        lent=strlen(txt);
        lenp=strlen(ptn);
        cout<<endl;
        x=matching(txt,lent,ptn,lenp)+1;
        if(x==0)
        {
            cout<<"Pattern not found"<<endl;
        }
        else
        {
            cout<<"Pattern is present at position number : "<<x<<endl;
        }
        cout<<endl;
        cout<<"Do you want to continue(y/n)? :  "<<" ";
        cin>>ch;
    }while(ch!='n');
    return (0);
}
