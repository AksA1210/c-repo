#include <iostream>
using namespace std;

class BinaryTree;
class Node
{
	int data;
	Node* left;
	Node* right;
   public:
	Node()
    {
		data = 0;
		left = NULL;
		right = NULL;
	}
	Node(int val)
    {
		data = val;
		left = NULL;
		right = NULL;
	}
	friend class BinaryTree;
};

class BinaryTree
{
	Node* root;
   public:
	BinaryTree()
    {
		root = NULL;
	}
	void createNode(int val);
	void display();
	void inorder(Node* node);
	void preorder(Node* node);
	void postorder(Node* node);
	Node* deleteNode(Node* node,int key);
	void deletion(int key){
		root = deleteNode(root, key);
	}
};

void BinaryTree::preorder(Node* node)
{
	if (node == NULL)
    {
	    return;
	}
	cout<<node->data<<"  ";
	preorder(node->left);
	preorder(node->right);
}

void BinaryTree::inorder(Node* node)
{
	if (node == NULL)
    {
	    return;
	}
	inorder(node->left);
	cout<<node->data<<"  ";
	inorder(node->right);
}

void BinaryTree::postorder(Node* node)
{
	if (node == NULL)
    {
	    return;
	}
	postorder(node->left);
	postorder(node->right);
	cout<<node->data<<"  ";
}
void BinaryTree::display()
{
	cout<<"Inorder Traversal :"<<" ";
	inorder(root);
    cout<<endl;
	cout<<"Preorder Traversal :"<<" ";
	preorder(root);
    cout<<endl;
	cout<<"Postorder Traversal :"<<" ";
	postorder(root);
	cout<<endl;
}

void BinaryTree::createNode(int val)
{
	Node* newNode = new Node(val);
	if (root==NULL)
    {
		root = newNode;
		return;
	}
	Node* temp = root;
	while (true)
    {
		if(val<temp->data)
        {
			if(temp->left==NULL)
            {
				temp->left = newNode;
				break;
			}
			else
            {
				temp = temp->left;
			}
		}
		else 
        {
			if(temp->right==NULL)
            {
				temp->right = newNode;
				break;
			}
			else
            {
				temp = temp->right;
			}
		}
	}

}

Node* BinaryTree::deleteNode(Node* node,int key)
{
	if (node==NULL)
    {
		return NULL;
	}
	else if(key>node->data)
    {
		node->right=deleteNode(node->right, key);
		return node;
	}
	else if(key<node->data)
    {
		node->left=deleteNode(node->left, key);
		return node;
	}
	else
    {
		if (node->left ==NULL)
        {
			Node* temp = node->right;
			delete node;
			return temp;
		}
		else if (root->right == NULL)
        {
			Node* temp = node->left;
			delete node;
			return temp;
		}
		else
        {
			Node* succParent = node;
			Node* succ = node->right;
			while (succ->left != NULL)
            {
				succParent = succ;
				succ = succ->left;
			}
			if (succParent != node)
            {
				succParent->left = succ->right;
			}
			else
            {
				succParent->right = succ->right;
			}
			node->data = succ->data;
			delete succ;
			return node;
		}
	}
}

int main() 
{
	BinaryTree Tree;
	int choice;
    char option;
	do
    {
        cout<<"---------------------OPERATIONS ON BINARY SEARCH TREE------------------"<<endl;
        cout<<"1. Create Node"<<endl;
        cout<<"2. Display Nodes"<<endl;
        cout<<"3. Delete Node"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter the choice : "<<" ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
				int val;
				cout<<"Enter the value  :"<<" ";
				cin>>val;
				Tree.createNode(val);
				break;
            }
            case 2:
            {
				Tree.display();
				break;
            }
            case 3:
            {
                int val;
				cout<<"Enter the delete key  :"<<" ";
				cin>>val;
				Tree.deletion(val);
				break;  
            }
            case 4: break;
            default:cout<<"Invalid choice"<<endl;
            cout<<"Please try again !"<<endl;     
        }
        if (choice != 4)
        {
            cout<<endl;
            cout<<"-----------------------------------------------------------------------"<<endl;
            cout<<"\nDo you want to continue(y/n) ? : "<<" ";
            cin>>option;
            cout<<endl;
            if(option == 'n')
            {
                choice = 4;
            }
        }
    } while (choice !=4);
    cout<<"\n-------------------------------END--------------------------------------"<<endl; 
    return(0);
}    