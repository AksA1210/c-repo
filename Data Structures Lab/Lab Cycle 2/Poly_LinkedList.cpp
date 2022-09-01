//Add polynomials using linkedlist

#include<iostream>
using namespace std;
class Node
{
public:
  int coeff,power;
  Node *link;
  
  Node(int coeff, int power)
  {
    this->coeff = coeff;
    this->power = power;
    this->link = NULL;
  }
};
  
void add(Node *head1, Node *head2)
{
    //head1 = head1->link;
    //head2 = head2->link;
  if(head1==NULL && head2==NULL)
  {
    return;
  }
  else if(head1->power == head2->power)
  {
    cout << " " << head1->coeff +  head2->coeff << "x^" << head1->power << "  ";
    add(head1->link,head2->link);
  }
  else if(head1->power > head2->power)
  {
    cout << " " << head1->coeff << "x^" << head1->power << "  ";
    add(head1->link, head2);
  }
  else
  {
    cout << " " << head2->coeff << "x^" << head2->power << " ";
    add(head1, head2->link);
  }
}
  
void insert(Node *head, int coeff, int power)
{
  Node *new_node = new Node(coeff,power);
  while(head->link != NULL)
  {
    head = head->link;
  }
  head->link = new_node;
}
  
void display(Node *head)
{
  cout << "The polynomial is : " << endl;
  head = head->link;
  while(head != NULL)
  {
    cout << " " << head->coeff << "x" << "^" << head->power<<"  ";
    head = head->link;
  }
}
int main()
{
    int coefficient,pow,num,max;
    cout<<"POLYNOMIAL 1 : "<<endl;
    cout<<"Enter the no: of terms : "<<" ";
    cin>>num;
    cout<<"Enter the highest power : "<<" ";
    cin>>max;
    Node *head1 = new Node(max,num);
    cout<<"Polynomial 1 =  "<<endl;
    for(int i = 0;i<num;i++)
    {
        cout<<"Enter the coefficient : "<<" ";
        cin>>coefficient;
        cout<<"Enter the power of x : "<<" ";
        cin>>pow;
        insert(head1,coefficient,pow);
    }
    cout<<"POLYNOMIAL 2 : "<<endl;
    cout<<"Enter the no: of terms : "<<" ";
    cin>>num;
    cout<<"Enter the highest power : "<<" ";
    cin>>max;
    Node *head2 = new Node(max,num);
    cout<<"Polynomial 2 =  "<<endl;
    for(int i = 0;i<num;i++)
    {
        cout<<"Enter the coefficient : "<<" ";
        cin>>coefficient;
        cout<<"Enter the power of x : "<<" ";
        cin>>pow;
        insert(head2,coefficient,pow);
    }
    display(head1);
    cout << endl;
    display(head2);
    cout << endl ;
    cout<<" After polynomial addition : " << endl;
    add(head1->link,head2->link);
    return (0);
}
