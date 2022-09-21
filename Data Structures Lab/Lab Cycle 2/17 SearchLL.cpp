#include<iostream>
using namespace std;
class Node 
{
    public:
        int data;
        Node* next;
};
void create(Node** head_ref, int new_data)
{
    Node* temp = new Node();
    Node* temp1 = *head_ref;
    temp->data = new_data;
    temp->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = temp;
        return;
    }
    else
    {
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        return;
	}
}
void search(Node** head, int item) 
{
    Node* loc = *head;
    int flag = 0,count = 0;
    while (loc != NULL) 
    {
        count++;
        if (loc->data == item) 
        {
            cout << "Item found at position : " << count << endl;
            flag = 1;
            break;
        }
        loc = loc->next;
    }
    if (flag == 0) 
    {
        cout << "Item not found" << endl;
    }
}
void display(Node *Node)
{
    cout << "LINKED LIST : ";
    while (Node != NULL) 
    {
        cout << Node->data<<" ";
        Node = Node->next;
    }
    cout<<endl;
}
int main() 
{
	int choice,value;
    char option;
    Node* head = NULL;
    do
    {
        cout<<"-------------SEARCHING IN LINKED LIST-------------"<<endl;
        cout<<"1. Add Node to the Linked List"<<endl;
        cout<<"2. Display the Linked List "<<endl;
        cout<<"3. Searching for Node in the Linked List"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter the choice : "<<" ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int value;
				cout<<"Enter the value  : "<<" ";
				cin>>value;
				create(&head , value);
                break;
            }
            case 2:
            {
                display(head);
                break;
            }
            case 3:
            {
                int value;
                cout<<"Enter the Node to be searched  : "<<" ";
				cin>>value;
				search(&head , value);
                break;
            }
            case 4:
            cout<<"\n\t\t       END "<<endl;
            cout<<"-------------------------------------------------"<<endl;
            break;
            default:cout<<"Error ! Please try again "<<endl;
            break;
        }
        if (choice!=4)
        {
          cout<<"Do you want to continue(y/n)? : "<<" ";
          cin>>option;
          if (option=='n')
          {
            choice=4;
          }
       }
    } while (choice != 4);
	return 0;
}