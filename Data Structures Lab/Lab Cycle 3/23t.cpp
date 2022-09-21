#include <iostream>
using namespace std;

class Node 
{
public:
	int data;
	Node* next;
	Node* prev;
};

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;

	new_node->next = (*head_ref);
	new_node->prev = NULL;

	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	(*head_ref) = new_node;
}

void display(Node* node)
{
	Node* last;
	cout << "\nTraversal in forward direction : ";
	while (node != NULL) {
		cout << " " << node->data << " ";
		last = node;
		node = node->next;
	}

	cout << "\nTraversal in reverse direction : ";
	while (last != NULL) {
		cout << " " << last->data << " ";
		last = last->prev;
	}
	cout<<endl;
}

void search(Node** head_ref, int key)
{
    if ((*head_ref) == NULL)
        return;
    Node* current = *head_ref;
    while(current != NULL){
        if(current->data==key){
            cout<<"Key found"<<endl;
            return;
        }
        current = current->next;
    }
    cout<<"Key not found"<<endl;
}


int main()
{
    Node* head = NULL;
    int ITEM,choice;
    char option;
    do
    {
        cout<<"---------------SEARCHING IN TWO WAY LINKED LIST------------"<<endl;
        cout<<"1. Add Node "<<endl;
        cout<<"2. Search Node"<<endl;
        cout<<"3. Display the two way linked list"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter the choice : "<<" ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter the value  : "<<" ";
                cin>>ITEM;
                push(&head,ITEM);
                break;
            }
            case 2:
            {
                cout<<"Enter the element to be searched : "<<" ";
                cin>>ITEM;
                search(&head,ITEM);
                break;
            }
            case 3:
            {
                display(head);
                break;
            }
            case 4: break;
            default:cout<<"Wrong choice"<<endl;
            cout<<"Please try again !"<<endl;
        }
        if (choice != 4)
        {
            cout<<endl;
            cout<<"-----------------------------------------------------------"<<endl;
            cout<<"\nDo you want to continue(y/n) ? : "<<" ";
            cin>>option;
            cout<<endl;
            if(option == 'n')
            {
                choice = 4;
            }
        }
    } while (choice !=4);
    return (0);
}