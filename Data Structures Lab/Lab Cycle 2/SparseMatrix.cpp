//Sparse Matrix
//sparse matrix------transpose and addn
//3 columns
//No of rows depends on no: of nonzero entries
#include<iostream>
#include<iomanip>
using namespace std;
class SparseMx
{
    int r;
    //int r1,r2;
    int** p;
   public:
    SparseMx(){};
    SparseMx(int n);
    void create();
    void transpose(SparseMx&);
    friend SparseMx operator+(SparseMx,SparseMx);
    void display();

};
SparseMx::SparseMx(int n)
{
    r = n;
    p = new int*[r];
    for(int i = 0; i<r; i++)
    {
        p[i] = new int[3];
    }
}

void SparseMx::create()
{
    cout<<"Enter the elements : "<<" ";
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cin>>p[i][j];
        }
    }
}

void SparseMx::transpose(SparseMx&A)
{
    A.p[0][0] = this->p[0][1];
    A.p[0][1] = this->p[0][0];
    A.p[0][2] = this->p[0][2];
    int x = 1;
    int VAL = this->p[0][2];
    for(int i = 0; i<p[0][1] ; i++)
    {
        for(int j = 1; j<VAL; j++)
        {
            if (p[j][1] == i)
            {
                A.p[x][0] = i;
                A.p[x][1] = p[j][0];
                A.p[x][2] = p[j][2];
                x = x+1;
            }
        }
    }
}
SparseMx operator+(SparseMx SP1,SparseMx SP2)
{
    //SparseMx SP3;
    if(SP1.p[0][0]!= SP2.p[0][0] || SP1.p[0][1]!= SP2.p[0][1])
    {
        cout<<"Matrix Addition is not possible "<<endl;
        //SP3.r1 = 0;
        //SP3(0);
        //return SP3;
    }
    //no: of non zero entries in SP1
    int SP1_no = SP1.r - 1;
    int SP2_no = SP2.r - 1;
    SparseMx SP3(SP1_no+SP2_no);
    //int T1 = SP1.p[0][2];
    //int T2 = SP2.p[0][2];
    int i,j,k;
    i = j = k;
    SP3.p[0][0] = SP1.p[0][0];
    SP3.p[0][1] = SP1.p[0][1];
    while(i<=SP1_no && j<=SP2_no)
    {
        if (SP1.p[i][0] < SP2.p[j][0])
        {
            SP3.p[k][0] = SP1.p[i][0];
            SP3.p[k][1] = SP1.p[i][1];
            SP3.p[k][2] = SP1.p[i][2];
            k++;
            i++;
        }
        else if (SP2.p[j][0] < SP1.p[i][0])
        {
            SP3.p[k][0] = SP2.p[j][0];
            SP3.p[k][1] = SP2.p[j][1];
            SP3.p[k][2] = SP2.p[j][2];
            k++;
            j++;   
        }
        else if (SP2.p[j][1] < SP1.p[i][1])
        {
            SP3.p[k][0] = SP2.p[j][0];
            SP3.p[k][1] = SP2.p[j][1];
            SP3.p[k][2] = SP2.p[j][2];
            k++;
            j++;   
        }
        else if (SP1.p[i][1] < SP2.p[j][1])
        {
            SP3.p[k][0] = SP1.p[i][0];
            SP3.p[k][1] = SP1.p[i][1];
            SP3.p[k][2] = SP1.p[i][2];
            k++;
            i++;
        }
        else
        {
            SP3.p[k][0] = SP1.p[i][0];
            SP3.p[k][1] = SP1.p[i][1];
            SP3.p[k][2] = SP1.p[i][2] + SP2.p[j][2];
            k++;
            i++;
            j++;
        }
    }
    while(i<SP1_no)
    {
        SP3.p[k][0] = SP1.p[i][0];
        SP3.p[k][1] = SP1.p[i][1];
        SP3.p[k][2] = SP1.p[i][2];
        k++;
        i++;
    }
    while(j<SP2_no)
    {
        SP3.p[k][0] = SP1.p[j][0];
        SP3.p[k][1] = SP1.p[j][1];
        SP3.p[k][2] = SP1.p[j][2];
        k++;
        j++;
    }
    SP3.p[0][2] = k-1;
    SP3.r = k;
    return SP3;
}
void SparseMx::display()
{
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout<<setw(4)<< p[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    //SparseMx SP1,SP2,SP3;
    int nr1,nr2;
    cout<<"Enter the no: of rows of the first matrix : "<<" ";
    cin>>nr1;
    cout<<"Enter the no: of rows of the second matrix : "<<" ";
    cin>>nr2;
    SparseMx SP1(nr1);
    SparseMx SP2(nr2);
    int choice;
    do
    {
        //SparseMx SP1;
        SP1.create();
        //SparseMx SP2;
        SP2.create();
        cout<<"SPARSE MATRIX 1 = "<<endl;
        cout<<"\t\t"<<endl;
        SP1.display();
        cout<<"SPARSE MATRIX 2 = "<<endl;
        cout<<"\t\t"<<endl;
        SP2.display();
        cout<<"-------------SPARSE MATRIX OPERATIONS--------------"<<endl;
        cout<<"Choose any option from the following : "<<endl;
        cout<<"1. Transpose"<<endl;
        cout<<"2. Addition"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter the choice : "<<" ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"-------------------TRANSPOSE OF MATRIX 1-------------------------"<<endl;
                cout<<endl;
                SP1.transpose(SP1);
                cout<<"-------------------TRANSPOSE OF MATRIX 2-------------------------"<<endl;
                cout<<endl;
                SP2.transpose(SP2);
                break;
            }
            case 2:
            {
                SparseMx SP3 = SP1 + SP2;
                cout<<"The resultant matrix is : "<<endl;
                SP3.display();
                break;
            }
            case 3:
            {
                cout<<"SPARSE MATRIX 1 = "<<endl;
                cout<<"\t\t"<<endl;
                SP1.display();
                cout<<"SPARSE MATRIX 2 = "<<endl;
                cout<<"\t\t"<<endl;
                SP2.display();
                break;
            }
            case 4:
            {
                break;
                default:cout<<"Invalid choice ! Please choose another option"<<endl;
            }
        }
    } while (choice!=4);
    
}


