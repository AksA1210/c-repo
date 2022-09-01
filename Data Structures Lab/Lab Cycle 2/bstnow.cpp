# include <iostream>
# include <cstdlib>
using namespace std;
class node
{
   public:
    int data;
    node *left;
    node *right;

}*root;

class BST
{
    public:
    void find(int, node **, node **);    
    void insert(node *, node *);
    void del(int);
    void case_0(node *,node *);
    void case_1(node *,node *);
    void case_2(node *,node *);
    void preorder(node *);
    void inorder(node *);
    void postorder(node *);
    BST()
    {
        root = NULL;
    }

};
 
     

void BST::find(int item, node **par, node **loc)
{

    node *ptr, *ptrsave;
    if (root == NULL)
    {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == root->data)
    {
        *loc = root;
        *par = NULL;
        return;
    }
    if (item < root->data)
    {
        ptr = root->left;
    }
    else
    {
        ptr = root->right;
        ptrsave = root;
        while (ptr != NULL)
        {
            if (item == ptr->data)
            {
                *loc = ptr;
                *par = ptrsave;
                return;
            }
            ptrsave = ptr;
            if (item < ptr->data)
            {
                ptr = ptr->left;
            }
    	else
    	{
    	    ptr = ptr->right;
        }
        *loc = NULL;
        *par = ptrsave;
    }
void BST::insert(node *tree, node *newnode)
{

    if (root == NULL)
    {
        root = new node;
        root->data = newnode->data;
        root->left = NULL;
        root->right = NULL;    
        cout<<"Root Node is Added"<<endl;
        return;    
    }

    if (tree->data == newnode->data)
    {
        cout<<"Element already in the tree"<<endl;
        return;
    }
    if (tree->data > newnode->data)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);	
        }
    	else
    	{
    	    tree->left = newnode;
    	    (tree->left)->left = NULL;
    	    (tree->left)->right = NULL;
    	    cout<<"Node Added To Left"<<endl;
    	    return;
    	    
    	}
    }

    else
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
            
        }
        else
        {

                tree->right = newnode;

                (tree->right)->left = NULL;

                (tree->right)->right = NULL;

                cout<<"Node Added To Right"<<endl;

                return;

            }	

        }

    }

    void BST::del(int item)

    {

        node *parent, *location;
        if (root == NULL)
        {
            cout<<"Tree empty"<<endl;
            return;
        }
        find(item, &parent, &location);
        if (location == NULL)
        {
            cout<<"Item not present in tree"<<endl;
            return;
        }
        if (location->left == NULL && location->right == NULL)
            case_0(parent, location);
        if (location->left != NULL && location->right == NULL)
            case_1(parent, location);
        if (location->left == NULL && location->right != NULL)
            case_1(parent, location);
        if (location->left != NULL && location->right != NULL)
            case_2(parent, location);
    }
    //0 child
    void BST::case_0(node *par, node *loc )
    {
        if (par == NULL)
        {
            root = NULL;
        }
        else
        {
            if (loc == par->left)
                par->left = NULL;
            else
                par->right = NULL;
        }
    }

//1 child
void BST::case_1(node *par, node *loc)
{

    node *child;
    if (loc->left != NULL)
    {
        child = loc->left;
    }
    else
    {
        child = loc->right;
    }
    if (par == NULL)
    {
        root = child;
    }
    else
    {
        if (loc == par->left)
                par->left = child;
        else
                par->right = child;
        }

    }
//2 child
void BST::case_2(node *par, node *loc)
{
    node *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->right;
    while (ptr->left != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->left;
    }
    suc = ptr;
    parsuc = ptrsave;
    if (suc->left == NULL && suc->right == NULL)
            case_0(parsuc, suc);

    else
        case_1(parsuc, suc);
        if (par == NULL)
        {
            root = suc;
        }
        else
        {
            if (loc == par->left)
                par->left = suc;

            else
                par->right = suc;

        }

        suc->left = loc->left;
        suc->right = loc->right;

    }


void BST::preorder(node *ptr)
{
        if (root == NULL)
        {
            cout<<"Tree is empty"<<endl;
            return;
        }
        if (ptr != NULL)
        {
            cout<<ptr->data<<"  ";
            preorder(ptr->left);
            preorder(ptr->right);
        }
    }
 void BST::inorder(node *ptr)
    {
        if (root == NULL)
        {
            cout<<"Tree is empty"<<endl;
            return;
        }
        if (ptr != NULL)
        {
            inorder(ptr->left);
            cout<<ptr->data<<"  ";
            inorder(ptr->right);
        }
    }

     
void BST::postorder(node *ptr)
    {

        if (root == NULL)

        {
            cout<<"Tree is empty"<<endl;
            return;
        }
        if (ptr != NULL)
        {
            postorder(ptr->left);
            postorder(ptr->right);
            cout<<ptr->data<<"  ";
        }
    }

     

   
int main()
{

    int choice, num;
    BST bst;
    node *temp;
    do
    {

        
        cout<<"--------------------Operations on BST---------------------"<<endl;
        cout<<"1.Insert  "<<endl;
        cout<<"2.Delete  "<<endl;
        cout<<"3.Inorder Traversal"<<endl;
        cout<<"4.Preorder Traversal"<<endl;
        cout<<"5.Postorder Traversal"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {

            case 1:

                temp = new node;
                cout<<"Enter the number to be inserted : ";
    	        cin>>temp->data;
                bst.insert(root, temp);
                break;

            case 2:

                if (root == NULL)
                {
                    cout<<"Tree is empty"<<endl;
                }
                cout<<"Enter the number to be deleted : ";
                cin>>num;
                bst.del(num);
                break;

            case 3:

                cout<<"Inorder Traversal of BST:"<<endl;
                bst.inorder(root);
                cout<<endl;
                break;

    	case 4:

                cout<<"Preorder Traversal of BST:"<<endl;
                bst.preorder(root);
                cout<<endl;
                break;

        case 5:

                cout<<"Postorder Traversal of BST:"<<endl;
                bst.postorder(root);
                cout<<endl;
                break;


        case 6:

                break;
                default:cout<<"Wrong choice"<<endl;

            }

        }while(choice!=6);
        return(0);

    }

     
