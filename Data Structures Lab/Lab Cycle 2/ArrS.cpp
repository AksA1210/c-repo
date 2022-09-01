

//Stack operations using array
#include<iostream>
using namespace std;
class StackArr
{
    int DATA[20];
    int TOP;
    int LAST;
    public:
        StackArr()
	      {
		      TOP = -1;
		      MAX = 20;
        }
        void push(int*,int,int,int);
        void pop(int*,int,int);
        void display(int*,int);

};
void StackArr::push(int ITEM)
{
    if(TOP==MAX-1)
    {
        cout<<"Overflow"<<endl;
    }
    else
    {
        TOP++;
        DATA[TOP]=ITEM;
        cout<<"Item successfully pushed into the stack........"<<endl;
    }
}
void StackArr::pop()
{
    if(TOP<0)
    {
        cout<<"Underflow"<<endl;
    }
    else
    {
        DATA[TOP]=ITEM;
        TOP--;
        cout<<"Item popped out of the stack........"<<endl;
    }
}
void StackArr::display()
{
    if(TOP==0)
    {
        cout<<"No elements in the stack"<<endl;
    }
    else
    {
        int item = DATA[TOP];
        cout<<item<<" < == "<<" ";
        for(int i = TOP-1; i>=0; i--)
        {
            cout<<DATA[i]<<endl;
        }
        cout<<endl;

    }
}

int main()
{
    int choice,len;
    char ch;
    int top = -1;
    int Stack[10];

    cout<<"Enter the number of elements in the stack : "<<" ";
    cin>>len;
    cout<<"Enter the elements : "<<endl;
    for(int i=0;i<len;i++)
    {
        cin>>Stack[i];
    }
    cout<<"Displaying the stack......."<<endl;
    //for(int i=0;i<len;i++)
    //{
    //    cout<<Stack[i]<<" ";
    //}
    //StackArr S(Stack,len);
   // S.display(Stack,top);
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
                S.push(item);
                break;
            }
            case 2:
            {
                S.pop();
                break;
            }
            case 3:
            {
                S.display();
                break;
            }
            case 4: break;
            default:cout<<"Error! Please choose another option"<<endl;
        }
    } while (choice!=4);
}
