

//Substring extraction
#include<iostream>
using namespace std;
void substring(char *str,int pos,int len)
{
    int count =0;
    char *sub = new char [len+1];
    while(count<len)
    {
        sub[count] = str[pos+count-1];
        count++;
    }
    sub[count] = '\0';
    for(int i=0;i<count;i++)
    {
        cout<<sub[i];
    }
    cout << "\n";

}

int main()
{
    int p,l;
    char str[20];
    char ch;
    do
    {
        cout<<"Enter the string : "<<" ";
        cin>>str;
        cout<<"Enter the position : "<<" ";        //Starting posn 
        cin>>p;
        cout<<"Enter the required length of the substring : "<<" ";
        cin>>l;
        cout<<"Substring : "<<" ";
        substring(str,p,l);
        cout<<endl;
        cout<<"Do you want to continue(y/n)? : "<<" ";
        cin>>ch;
    } while (ch!='n');
    return(0);
}
