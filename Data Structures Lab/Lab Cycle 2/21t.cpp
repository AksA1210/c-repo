#include <iostream>
using namespace std;

class Node
{
	int coeff,power;
	Node* link;
public:
	Node()
    {
		coeff = 0;
		power = 0;
		link = NULL;
	}
	Node(int coeff)
    {
		this->coeff = coeff;
		power = 0;
		link = NULL;
	}
	Node(int coeff,int power)
    {
		this->coeff = coeff;
		this->power = power;
		link = NULL;
	}
	int getPower(){
		return this->power;
	}
	int getCoefficient()
    {
		return this->coeff;
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
	void newNode(int val,int pow);
	void display();
	void addPolynomial(LinkedList poly1,LinkedList poly2);
};

void LinkedList::newNode(int val,int pow)
{
	Node* newNode = new Node(val,pow);
	if(head==NULL){
		head = newNode;
		return;
	}
	Node* temp = head;
	while(temp->link!=NULL){
		temp = temp->link;
	}
	temp->link = newNode;

}

void LinkedList::display()
{
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->coeff<<"x^"<<temp->power;
		if(temp->link!=NULL){
			cout<<" + ";
		}
		temp = temp->link;
	}
}

void LinkedList::addPolynomial(LinkedList p1,LinkedList p2)
{
	Node* temp1 = p1.head;
	Node* temp2 = p2.head;
	while(temp1!=NULL and temp2!=NULL){
		if(temp1->getPower()==temp2->getPower())
        {
			int sum = temp1->getCoefficient() + temp2->getCoefficient();
			newNode(sum, temp1->getPower());
			temp1 = temp1->link;
			temp2 = temp2->link;
		}
		else if (temp1->getPower()>temp2->getPower())
        {
			newNode(temp1->getCoefficient(), temp1->getPower());
			temp1 = temp1->link;
		}
		else{
			newNode(temp2->getCoefficient(), temp2->getPower());
			temp2 = temp2->link;
		}
	}
	while(temp1!=NULL)
    {
		newNode(temp1->getCoefficient(), temp1->getPower());
		temp1 = temp1->link;
	}
	while(temp2!=NULL)
    {
		newNode(temp2->getCoefficient(), temp2->getPower());
		temp2 = temp2->link;
	}
}

int main() 
{
	LinkedList p1;
	int polA,A,polB,B;
    char option;
    do
    {
        cout<<"\n--------------ADDITION OF POLYNOMIALS USING LINKED LIST--------------"<<endl;
        cout<<"POLYNOMIAL 1 : "<<endl;
        cout<<"Enter the highest degree of the poynomial equation 1 : ";
        cin>>polA;
        polA =polA+1;
        cout<<"\nEnter the corresponding constant values :\n";
        for(int i=0;i<polA;i++)
        {
         cout<<"  x^"<<i<<" : ";
         cin>>A;
         p1.newNode(A, i);
        }
	    LinkedList p2;
        cout<<"POLYNOMIAL 2 : "<<endl; 
        cout<<"Enter the highest degree of the poynomial equation 2 : ";
        cin>>polB;
        polB=polB+1;
        cout<<"Enter the corresponding constant values :\n";
        for(int i=0;i<polB;i++)
        {
            cout<<"  x^"<<i<<" : ";
            cin>>B;
            p2.newNode(B, i);
        }
        cout<<"POLYNOMIAL 1 : "<<" ";
        p1.display();
        cout<<endl;
        cout<<"POLYNOMIAL 2 : "<<" ";
	    p2.display();
        cout<<endl;
	    LinkedList sum;
	    sum.addPolynomial(p1, p2);
        cout<<"Polynomial sum : ";
	    sum.display();
        cout<<endl;
        cout<<"Do you want to continue(y/n) ? : "<<" ";
        cin>>option;
    } while (option !='n');
    cout<<"\n-------------------------END--------------------------------"<<endl;  
	return 0;
}
