
//Stack operations using linked list
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
        this->data = data;
        this->link = NULL;
    }

};
class linkedlist
{
    Node* TOP;
    public:
    void set_TOP(Node* N)
    {
        TOP=N;
    }
    void push(int*,int);
    void pop(int*,int);
    void display(linkedlist &S);
};
void linkedlist::push(int A[],int ITEM)
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
    //NEW->data=ITEM;
    //NEW->link=TOP;
}
void linkedlist::pop(int A[],int ITEM)
{
    if(TOP==NULL)
    {
        cout<<"Underflow"<<endl;
        return;
    }
    Node* TEMP = NULL;
    TEMP = TOP;
    TOP = TOP->link;
    TEMP->data = ITEM;
    delete TEMP;
}
void linkedlist::display(linkedlist&S)
{
    Node* TEMP = S.TOP;
    //cout << " ";
    while(TEMP->link!= NULL)
    {
        cout << TEMP->data<< " ";
        TEMP = TEMP->link;
    }
    //cout << " ]\n";
    /*
    Node* TEMP = TOP;
    cout<<"Data inside linked list : "<<endl;
    while(TEMP!=NULL)
    {
        cout<<TEMP->data<<" ";
        TEMP=TEMP->link;
    }
    */
}


int main()
{
    linkedlist l;
    int choice,top,len;
    int A[len];
    cout<<"Enter the number of elements in the stack : "<<" ";
    cin>>len;
    cout<<"Enter the elements : "<<endl;
    for(int i=0;i<len;i++)
    {
        cin>>A[i];
    }
    cout<<"Displaying the stack......."<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    do
    {
        cout<<"----------------STACK OPERATIONS USING LINKED LIST---------------"<<endl;
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
                l.push(A,item);
                break;
            }
            case 2:
            {
                int item;
                cout<<"Enter the item to be deleted : "<<" ";
                cin>>item;
                l.pop(A,item);
                break;
            }
            /*case 3:
            {
                l.display();
                break;
            }*/
            case 4: break;
            default:cout<<"Error! Please choose another option"<<endl;
        }
    } while (choice!=4);
    
}
