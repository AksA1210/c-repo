#include <iostream>
using namespace std;

class Node
{
	int data;
	Node* link;
  public:
	Node()
    {
		this->data = 0;
		this->link = NULL;
	}
	Node(int val)
    {
		this->data = val;
		this->link = NULL;
	}
	friend class LinkedList;
};

class LinkedList
{
	Node* head;
   public:
	LinkedList()
    {
		head = NULL;
	}
	void create(int val);
	void display();
	void insertInBetween(int val);
};

void LinkedList::create(int val)
{
	Node* newNode = new Node(val);
	if(head==NULL)
    {
		head = newNode;
		return;
	}
	Node* temp = head;
	while(temp->link!=NULL)
    {
		temp = temp->link;
	}
	temp->link = newNode;
}

void LinkedList::display()
{
	Node* temp = head;
	while(temp!=NULL)
    {
		cout<<temp->data<<"  ";
		temp = temp->link;
	}
    cout<<endl;
}

void LinkedList::insertInBetween(int val)
{
	Node* temp = head;
	if(val<head->data)
    {
		Node* newNode = new Node(val);
		newNode->link = head;
		head = newNode;
		return;
	}
	while(temp->link!=NULL)
    {
		Node* succ = temp->link;
		if(val>temp->data and val<succ->data)
        {
			Node* newNode = new Node(val);
			newNode->link = succ;
			temp->link = newNode;
			return;
		}
		temp = temp->link;
	}
	if(val>temp->data)
    {
		Node* newNode = new Node(val);
		temp->link = newNode;
	}
}

int main() 
{
	LinkedList list;
	int choice;
    char option;
    do
    {
        cout<<"-------------INSERTION IN LINKED LIST-------------"<<endl;
        cout<<"1. Add Node to the Linked List"<<endl;
        cout<<"2. Display the Linked List "<<endl;
        cout<<"3. Insert New Node to the Linked List"<<endl;
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
				list.create(value);
                break;
            }
            case 2:
            {
                list.display();
                break;
            }
            case 3:
            {
                int value;
                cout<<"Enter the value  : "<<" ";
				cin>>value;
				list.insertInBetween(value);
                break;
            }
            case 4:
            cout<<"\n\t END "<<endl;
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
    } while (choice !=4);
	return 0;
}