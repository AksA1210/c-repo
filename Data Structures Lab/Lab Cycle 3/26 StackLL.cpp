#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* link;
    Node()
    {
		data = 0;
		link = NULL;
	}
    Node(int ITEM)
    {
        this->data = ITEM;
        this->link = NULL;
    }
    friend class Stack;
};
class Stack
{
    Node* TOP;
public:
    Stack()
    {
        TOP=NULL;
    }
    void push(int);
    void pop();
    void display();
};
void Stack::push(int ITEM)
{
    Node* NEW=new Node(ITEM);
    if(TOP==NULL)
    {
        TOP = NEW;
        cout<<"Item pushed into the stack"<<endl;
        return;
    }
    Node* TEMP = TOP;
    TOP = NEW;
    TOP->link = TEMP; 
}
void Stack::pop()
{
    if(TOP==NULL)
    {
        cout<<"Underflow"<<endl;
        return;
    }
    Node* TEMP = NULL;
    TEMP = TOP;
    TOP = TOP->link;
    cout<<"Element which was popped out of the stack : "<<TEMP->data <<endl;;
    delete TEMP;
}
void Stack::display()
{
    Node* TEMP = TOP;
    while(TEMP!= NULL)
    {
        cout << TEMP->data<< " ";
        TEMP = TEMP->link;
    }
    cout<<endl;
}


int main()
{
    Stack S;
    int choice,top;
    do
    {
        cout<<"----------------STACK OPERATIONS USING LINKED LIST--------------"<<endl;
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
    cout<<"\n-----------------------------END----------------------------------"<<endl;
    return(0);
}