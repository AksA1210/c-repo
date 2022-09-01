

//Stack operations using array
#include<iostream>
using namespace std;
class StackArr
{
    int DATA[20];
    int TOP;
    int MAX;
    //int LAST;
    public:
        StackArr()
	      {
		      TOP = -1;
		       MAX = 20;
        }
        void push(int*,int);
        void pop();
        void display();

};
void StackArr::push(int ITEM)
{
    if(TOP>=MAX)
    {
        cout<<"Overflow"<<endl;
    }
    else
    {
        TOP++;
        DATA[TOP]=ITEM;
        cout<<"Item successfully pushed into the stack........"<<endl;
    }
}
void StackArr::pop()
{
    if(TOP<0)
    {
        cout<<"Underflow"<<endl;
    }
    else
    {
        int ITEM = DATA[TOP];
        TOP--;
        cout<<"Item popped out of the stack........"<<endl;
    }
}
void StackArr::display()
{

        int item = DATA[TOP];
        cout<<item<<" < == "<<" ";
        for(int i = TOP-1; i>=0; i--)
        {
            cout<<DATA[i]<<endl;
        }
        cout<<endl;

}

int main()
{
    int choice;
    char ch;
    StackArr S;
    //int MAXSTK = len;
    do
    {
	cout<<endl;    
        cout<<"------------------STACK OPERATIONS USING ARRAY---------------"<<endl;
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
                S.push(item);
                break;
            }
            case 2:
            {
                S.pop();
                break;
            }
            case 3:
            {
                S.display();
                break;
            }
            case 4: break;
            default:cout<<"Error! Please choose another option"<<endl;
        }
    } while (choice!=4);
}
