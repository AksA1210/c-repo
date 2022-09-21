#include<iostream>
using namespace std;
class node 
{
public:
    int data;
    node* next;
};
void insert(node** head, int item) 
{
    node* temp = new node();
    temp->data = item;
    temp->next = *head;
    if (*head != NULL) 
    {
        node* temp1 = *head;
        while (temp1->next != *head) 
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    else 
    {
        temp->next = temp;
        *head = temp;
    }
}
node* del(node* head, int item) 
{
    int flag = 0;
    if (head == NULL) 
    {
        cout << "List is Empty" << endl;
        flag = 1;
        return head;
    }
    else if (head->next == head) 
    {
        if (head->data == item) 
        {
            head = NULL;
            delete head;
            cout << "Element deleted" << endl;
            flag = 1;
        }
        return head;
    }
    else 
    {
        node* temp = head;
        node* ptr;
        if(head->data == item)
        {
            flag = 1;
            while (temp->next != head) 
            {
                temp = temp->next;
            }
            temp->next = head->next;
            delete head;
            head = temp->next;
        }
        else 
        {
            while (temp->next != head && temp->next->data != item) 
            {
                temp = temp->next;
            }
            if (temp->next->data == item) 
            {
                flag = 1;
                ptr = temp->next;
                temp->next = ptr->next;
                delete ptr;
            }
        }
    }
    if (flag == 0) 
    {
        cout << "Element not found" << endl;
    }
    return head;
}
void print(node* head)
{
    cout << "CIRCULAR HEADER LIST  : ";
    if (head == NULL) 
    {
        cout << "List is Empty" << endl;
    }
    else 
    {
        node* temp = head;
        do 
        {
            cout << temp->data <<" ";
            temp = temp->next;
        } while (temp != head);
    }
}
int main() 
{
    node* head = NULL;
    int choice , item;
    char option;
    do 
    {
        cout << "----------CIRCULAR HEADER LIST OPERATIONS----------"<<endl;
        cout<<"1. Add Node"<<endl;
        cout<<"2. Delete Node"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter the choice : "<<" ";
        cin>>choice;
        switch (choice) 
        {
            case 1:
            cout << "Enter number of elements to insert : ";
            int num;
            cin >> num;
            cout << "Enter the elements : ";
            for (int i = 0; i < num; i++) 
            {
                cin >> item;
                insert(&head, item);
            }
            print(head);
            break;
            case 2:
            cout << "Enter the element to be deleted : ";
            cin >> item;
            head = del(head, item);
            print(head);
            break;
            case 3: break;
            default:cout<<"Invalid choice ! Please choose another option"<<endl;
        }
        if (choice != 3)
        {
            cout<<endl;
            cout<<"------------------------------------------------------------"<<endl;
            cout<<"\nDo you want to continue(y/n) ? : "<<" ";
            cin>>option;
            cout<<endl;
            if(option == 'n')
            {
                choice = 3;
            }
        }
    } while (choice!=3);
    cout<<"\n-------------------------END--------------------------------"<<endl; 
    return 0;
}