//Stack operations using array
#include<iostream>
using namespace std;
class StackArr
{
    int DATA[30];
    int TOP;
    int MAX;
    public:
        StackArr()
	    {
		    TOP = -1;
		    MAX = 30;
        }
        void push(int);
        void pop();
        void display();

};
void StackArr::push(int ITEM)
{
    if(TOP>=MAX)
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
        int ITEM = DATA[TOP];
        TOP--;
        cout<<"Item popped out of the stack........"<<endl;
    }
}
void StackArr::display()
{
    cout<<"\nSTACK =  "<<" ";
    cout<<"\n\t"<<endl;
    for(int i=0;i<=TOP;i++)
    {
        cout<<DATA[i]<<" < = ";
    }
    cout<<endl;
}

int main()
{
    int choice;
    char ch;
    StackArr S;
    do
    {
	    cout<<endl;    
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
            case 4: 
            cout<<"END"<<endl;
            break;
            default:cout<<"Error! Please choose another option"<<endl;
        }
    } while (choice!=4);
}