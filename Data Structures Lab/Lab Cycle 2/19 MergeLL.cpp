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
	void create(int);
	void display();
	void merge(LinkedList List_1,LinkedList List_2);
};
void LinkedList::create(int val)
{
	Node* newNode = new Node(val);
	if(head==NULL)
    {
		head = newNode;
		return;
	}
	Node* temp = new Node();
	temp = head;
	while(temp->link!=NULL)
    {
		temp = temp->link;
	}
	temp->link = newNode;
}

void LinkedList::display()
{
	Node* temp = new Node();
	temp = head;
	while(temp!=NULL)
    {
		cout<<temp->data<<"  ";
		temp = temp->link;
	}
	cout<<endl;
}

void LinkedList::merge(LinkedList List_1,LinkedList List_2)
{
	Node* temp1 = List_1.head;
	Node* temp2 = List_2.head;
	while(temp1!=NULL and temp2!=NULL){
		if(temp1->data>temp2->data)
        {
			create(temp2->data);
			temp2 = temp2->link;
		}
		else
        {
			create(temp1->data);
			temp1 = temp1->link;
		}
	}
	while(temp1!=NULL)
    {
		create(temp1->data);
		temp1 = temp1->link;
	}
	while(temp2!=NULL)
    {
		create(temp2->data);
		temp2 = temp2->link;
	}
}

int main()
{
	LinkedList List_1;
	LinkedList List_2;
	int choice;
    char option;
    do
    {
        cout<<"-----------MERGE TWO SORTED LINKED LIST-----------"<<endl;
	    cout<<"1.Add Node to Linked List 1"<<endl;
        cout<<"2.Add Node to Linked List 2"<<endl;
        cout<<"3.Merge "<<endl;
        cout<<"4.Exit "<<endl;
        cout<<"Enter the choice : "<<" ";
	    cin>>choice;
	    switch (choice)
        {
	        case 1:
            {
			    int val;
			    cout<<"Enter the value  : "<<" ";
			    cin>>val;
			    List_1.create(val);
                cout<<endl;
                cout<<"LINKED LIST 1 = "<<" ";
			    List_1.display();
			    break;
            }       
		    case 2:
            {
                int val;
			    cout<<"Enter the value  : "<<" ";
			    cin>>val;
			    List_2.create(val);
                cout<<endl;
                cout<<"LINKED LIST 2 = "<<" ";
			    List_2.display();
			    break;
            }    
		    case 3:
		    {
			    LinkedList list3;
			    list3.merge(List_1, List_2);
				cout<<endl;
				cout<<"MERGED LIST  = "<<" ";
			    list3.display();
			    break;
		    }
            case 4: break;
		    default:cout<<"Invalid choice"<<endl;
            cout<<"Please try again"<<endl;
	    }   
        if (choice != 4)
        {
            cout<<endl;
            cout<<"-------------------------------------------------"<<endl;
            cout<<"\nDo you want to continue(y/n) ? : "<<" ";
            cin>>option;
            cout<<endl;
            if(option == 'n')
            {
                choice = 4;
            }
        }
    } while (choice !=4);
	cout<<"\n-----------------------END------------------------"<<endl; 
    return(0);
}