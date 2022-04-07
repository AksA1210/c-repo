

#include <iostream>
#include <cstring>
using namespace std;
class strings
{
    char *name;
    int length;
  public:
    strings()
    {
        length=0;
        name=new char[length+1]  ;
    }
    strings(const char*s)
    {
        length= strlen(s)  ;
        name=new char[length+1] ;
        strcpy(name,s);
    }
    void input()
    {
        cin>>name;
    }
    void display(void)
    {
        cout<<name<<endl;
    }
    void Length()
    {
        int length;
        length=strlen(name);
        cout<<length<<endl;
    }
    void join(strings x,strings y);
    void compare(strings x,strings y);
};
void strings::join(strings x,strings y)
{
    length=x.length+y.length;
    delete name;
    name=new char[length+1];
    strcpy(name,x.name);
    strcat(name,y.name);

}

void strings::compare(strings x,strings y)
{
    int len1,len2;
    len1=strlen(x.name);
    len2=strlen(y.name);
    if (len1>len2)
    {
        cout<<x.name<<" has more characters than "<<y.name<<endl;
    }
    else
    {
        cout<<y.name<<" has more characters than "<<x.name<<endl;
    }
}

int main()
{
    strings s1,s2,s3;
    int x;
    do
    {
        cout<<"-------------STRING OPERATIONS------------- "<<endl;
        cout<<"1.Concatenate the strings "<<endl;
        cout<<"2.Display the strings "<<endl;
        cout<<"3.Compare the strings "<<endl;
        cout<<"4.Exit "<<endl;
        cout<<endl;
        cout<<"\n\nEnter your choice : "<<" ";
        cin>>x;
        switch(x)
        {
            case 1: 
               cout<<"Enter the first string : "<<" ";
               s1.input();
               cout<<"Enter the second string : "<<" ";
               s2.input();
               cout<<"The first string is : ";
               s1.display();
               cout<<"The second string is : ";
               s2.display();
               s3.join(s1,s2);
               cout<<"After concatenation : "<<endl;
               s3.display();
            break;
            case 2:
               cout<<"The first string is : ";
               s1.display();
               cout<<"The second string is : ";
               s2.display();
            break;
            case 3:
               cout<<"Length of the first string : ";
               s1.Length();
               cout<<endl;
               cout<<"Length of the second string : ";
               s2.Length();
               cout<<endl;
               cout<<"Length of the concatenated string : ";
               s3.Length();
               cout<<endl;
               s3.compare(s1,s2);
            break;
            case 4: break;
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
