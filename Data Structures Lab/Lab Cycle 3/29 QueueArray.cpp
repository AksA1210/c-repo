
#include<iostream>
using namespace std;
const int size = 10;
class Queue
{   
    int FRONT;
    int REAR;
    int Q[size];
    public:
    Queue() 
    {
        FRONT = -1;
        REAR = -1;
        for (int i = 0; i < size; i++) 
        {
            Q[i] = 0;
        }  
    } 
     
    void q_insert(int);
    void q_delete();
    void display();

};
void Queue::q_insert(int ITEM)
{
    if (REAR == size - 1)
    {
        cout << "OVERFLOW" << endl;
    }
    else if (FRONT == -1 && REAR == -1)
    {
        REAR = 0;
        FRONT = 0;
        Q[REAR] = ITEM;
    }
    else
    {
        REAR++;
        Q[REAR] = ITEM;
    }
    cout<<"Item has been successfully added to the queue....."<<endl<<endl;
}
void Queue::q_delete()
{
    int ITEM;
    if (FRONT == -1 && REAR == -1)
    {
        cout << "UNDERFLOW" << endl;
    }
    else if (REAR == FRONT)
    {
        ITEM = Q[REAR];
        REAR = -1;
        FRONT = -1;
        cout<<"Item has been successfully deleted from the queue....."<<endl<<endl;
        FRONT++;
    }
    else
    {
        ITEM = Q[FRONT];
        Q[FRONT] = 0;
        cout<<"Item has been successfully deleted from the queue......"<<endl<<endl;
        FRONT++;
    }
}
void Queue::display()
{
    if (FRONT == -1)
    {
        cout << "EMPTY QUEUE" << endl;
    }
    else
    {
        cout << "\nQUEUE : " <<endl<<endl;
        for (int i = 0; i < size; i++)
        {
            cout << Q[i] << "  ";
        }
        cout<<endl<<endl;
        cout << "Front : " << FRONT << endl;
        cout << "Rear  : " << REAR << endl;
        cout << endl;
    }
}
int main()

{
    int choice;
    Queue q1;
    do
    {
        cout<<"--------------------------QUEUE OPERATIONS---------------------"<<endl;
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
                cout<<endl;
                q1.q_insert(item);
                break;
            }
            case 2:
            {
                q1.q_delete();
                break;
            }
            case 3:
            {
                q1.display();
                break;
            }
            case 4:
            {
                cout<<"\n\t\t\t     END "<<endl;
                cout<<"----------------------------------------------------------------"<<endl;
                break;
                default:cout<<"Invalid choice ! Please choose another option"<<endl;
            }
        }
    } while (choice!=4); 
}