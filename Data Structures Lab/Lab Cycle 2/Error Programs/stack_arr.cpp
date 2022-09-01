//Stack operations using array
#include<iostream>
using namespace std;
class StackArr
{
    int* DATA;
    int TOP;
    int LAST;
    public:
        StackArr(int* A,int len)
        {
            int N;
            DATA = new int[N];
            // MAXD points to the last element
            LAST = N;
            for(int i = 0 ; i < len ; i++)
            {
                DATA[i] = A[i]; 
            }
            // TOP points to the last element
            // Nels - 1 since index starts from 0
            TOP = len-1;
        }    
        void push(int*,int,int,int);
        void pop(int*,int,int);
        void display(int*,int);

};
void StackArr::push(int Stack[],int TOP,int MAXSTK,int ITEM)
{
    if(TOP==MAXSTK-1)
    {
        cout<<"Overflow"<<endl;
    }
    else
    {
        TOP++;
        Stack[TOP]=ITEM;
        cout<<"Item successfully pushed into the stack........"<<endl;
    }
}
void StackArr::pop(int Stack[],int TOP,int ITEM)
{
    if(TOP<0)
    {
        cout<<"Underflow"<<endl;
    }
    else
    {
        Stack[TOP]=ITEM;
        TOP--;
        cout<<"Item popped out of the stack........"<<endl;
    }
}
void StackArr::display(int Stack[],int TOP)
{
    if(TOP==0)
    {
        cout<<"No elements in the stack"<<endl;
    }
    else
    {
        cout<<Stack[TOP]<<" < == "<<" ";
        for(int i = TOP-1; i>=0; i--)
        {
            cout<<Stack[i]<<endl;
        }
        cout<<endl;

    }
}

int main()
{
    int choice,len;
    char ch;
    int top = -1;
    int* Stack;

    cout<<"Enter the number of elements in the stack : "<<" ";
    cin>>len;
    Stack=new int[len];
    cout<<"Enter the elements : "<<endl;
    for(int i=0;i<len;i++)
    {
        cin>>Stack[i];
    }
    cout<<"Displaying the stack......."<<endl;
    //for(int i=0;i<len;i++)
    //{
    //    cout<<A[i]<<" ";
    //}
    StackArr S(Stack,len);
    S.display(Stack,top);
    cout<<endl;
    //int MAXSTK = len;
    do
    {
        cout<<"------------------STACK OPERATIONS USING ARRAY---------------"<<endl;
        cout<<"Choose any option from the following  : "<<endl;
        cout<<"1.Push"<<endl;
        cout<<"2.Pop"<<endl;
        cout<<"3.Display the stack"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter the choice : "<<" ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int item;
                cout<<"Enter the item to be pushed : "<<" ";
                cin>>item;
                S.push(Stack,top,len,item);
                break;
            }
            case 2:
            {
                int item;
                cout<<"Enter the item to be deleted : "<<" ";
                cin>>item;
                S.pop(Stack,top,item);
                break;
            }
            case 3:
            {
                S.display(Stack,top);
                break;
            }
            case 4: break;
            default:cout<<"Error! Please choose another option"<<endl;
        }
    } while (choice!=4);
}
