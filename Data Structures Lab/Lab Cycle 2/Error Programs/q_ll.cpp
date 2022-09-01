//Problem with display
//Implementation of queue using linked list
#include<iostream>
using namespace std;
class Node 
{
    public: 
    int data;
    Node* link;
};

class Queue
{
        Node* FRONT = NULL;
        Node* REAR = NULL;
    public:
        void q_insert(int );
        void q_delete(int );
        void display();
};

void Queue::display()
{
    /*Node* PTR = L.FRONT;
    while(PTR->link!= NULL)
    {
        cout << PTR->data << "  ";
        PTR = PTR->link ;
    }*/
    //Node* PTR ;
    if(FRONT == NULL && REAR == NULL)
    {
        cout<<"Empty Queue"<<endl;
    }
    else
    {
        Node* PTR = FRONT;
        cout<<PTR->data<<" -->>-- ";
        while(PTR->link!= NULL)
        {
            PTR = PTR->link;
            cout << PTR->data << " -->>-- ";
            //PTR = PTR->link ;
            
        }
    }
    cout<<endl<<endl;
}

void Queue::q_insert(int item)
{
    Node* NEW = new Node ;
    if (NEW == NULL)
    {
        cout<< "OVERFLOW";
    }
    NEW->data = item;
    if (FRONT == NULL)
    {
        FRONT = NEW;
        NEW->link = NULL;
        REAR = NEW;
        cout<<"Item has been successfully added to the queue........"<<endl;
    }
    else
    {
        REAR->link = NEW;
        NEW->link = NULL;
        cout<<"Item has been successfully added to the queue........"<<endl;
    }
}

void Queue::q_delete(int ITEM)
{
    if(FRONT == NULL)
    {
        cout<<"UNDERFLOW"<<endl;
    }
    Node* PTR = FRONT;
    ITEM = PTR->data;
    FRONT = PTR->link;
    PTR->link = NULL;
    cout<<"Item has been successfully deleted............"<<endl;

}
int main()
{
    int choice;
    Queue q1;
    do
    {
        cout<<endl;
        cout<<"----------------IMPLEMENTATION OF QUEUE USING LINKED LIST ------------------"<<endl;
        cout<<"1.Insert"<<endl;
        cout<<"2.Delete"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter the choice : "<<" ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int item;
                cout<<"Enter the element to be added : "<<" ";
                cin>>item;
                q1.q_insert(item);
                break;
            }
            case 2:
            {
                int item;
                q1.q_delete(item);
                break;
            }
            case 3:
            {
                q1.display();
                break;
            }
            case 4:
            {
                break;
                default:cout<<"Invalid choice ! Please choose another option"<<endl;
            }

        }
    } while (choice!=4); 
    return(0);
}

