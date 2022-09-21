//Pattern Matching
#include<iostream>
#include<cstring>
using namespace std;
void matching(char* str,char *pattern)
{
    int strLen = strlen(str);
    int pattLen = strlen(pattern);
    for (int i = 0; i < strLen-pattLen; i++) 
    {
        int j;
        for (j = 0; j < pattLen; j++) 
        {
            if(str[i+j]!=pattern[j])
            {
                break;
            }
        }
        if(j==pattLen)
        {
            cout<<"Pattern found at "<<i<<endl;
        }
    }
}
int main()
{
    char txt[40];
    char ptn[20];
    int lent,lenp;
    char ch;
    do
    {
        cout<<"--------------------PATTERN MATCHING---------------------"<<endl;
        cout<<"Enter the text : ";
        cin>>txt;
        cout<<"Enter the pattern : ";
        cin>>ptn;
        cout<<endl;
        matching(txt,ptn);
        cout<<"Do you want to continue(y/n)? :  "<<" ";
        cin>>ch;
    }while(ch!='n');
    return (0);
}