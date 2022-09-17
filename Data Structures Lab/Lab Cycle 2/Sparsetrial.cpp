#include <iostream>
using namespace std;
class Matrix
{
    int **data;
    int sparseRow,sparseCol;
    int rowSize,colSize;
public:
    Matrix()
    {
        sparseCol = 3;
    }
    Matrix(int sR,int r,int c)
    {
        sparseRow = sR;
        sparseCol = 3;
        rowSize = r;
        colSize = c;
        data = new int*[sparseRow];
        for (int i = 0; i < sparseRow; ++i) 
        {
            data[i] = new int[sparseCol];
        }
    }
    void create(int sR,int r,int c)
    {
        sparseRow = sR;
        sparseCol = 3;
        rowSize = r;
        colSize = c;
        data = new int*[sparseRow];
        for (int i = 0; i < sparseRow; ++i) 
        {
            data[i] = new int[sparseCol];
        }
    }
    void insert(int i,int j,int value)
    {
        data[i][j] = value;
    }
    void allocate()
    {
        cout<<"Enter the row size of the matrix : "<<" ";
        cin>>rowSize;
        cout<<"Enter the column size of the matrix : "<<" ";
        cin>>colSize;
        cout<<"Enter the no: of non zero values in matrix : "<<" ";
        cin>>sparseRow;
        data = new int*[sparseRow];
        for (int i = 0; i < sparseRow; ++i) 
        {
            data[i] = new int[sparseCol];
        }
    }
    void addEntries()
    {
        cout<<"Enter the elements in the matrix : "<<endl;
        for (int i = 0; i < sparseRow; ++i) 
        {
            cout<<"Row - "<<i+1<<endl;
            for (int j = 0; j < sparseCol; ++j) 
            {
                cin>>data[i][j];
            }
        }
    }
    void display()
    {
        cout<<"Row    Column    Value"<<endl;
        for (int i = 0; i < sparseRow; ++i) 
        {
            for (int j = 0; j < sparseCol; ++j) 
            {
                cout<<data[i][j]<<"         ";
            }
        cout<<endl;
        }
    }
    void transpose()
    {
        Matrix trans;
        trans.create(sparseRow, colSize, rowSize);
        for (int i = 0; i < sparseRow; ++i) 
        {
            trans.insert(i,0,data[i][1]);
            trans.insert(i,1,data[i][0]);
            trans.insert(i,2,data[i][2]);
        }
        trans.display();
    }
    friend void addMatrix(const Matrix &a,const Matrix &b);
};
void addMatrix(const Matrix &a,const Matrix&b)
{
    if(a.rowSize!=b.rowSize and a.colSize!=b.colSize)
    {
        cout<<"Addition not possible"<<endl;
        return;
    }
    Matrix sum;
    sum.create(a.sparseRow, a.rowSize, a.colSize);
    int aNum=0;
    int bNum=0;
    while(aNum < a.sparseRow and bNum < b.sparseRow)
    {
        if(a.data[aNum][0]>b.data[bNum][0] or (a.data[aNum][0]==b.data[bNum][0] and
        a.data[aNum][1]>b.data[bNum][1]))
        {
            sum.insert(b.data[bNum][0],b.data[bNum][1],b.data[bNum][2]);
            bNum++;
        } 
        else if (a.data[aNum][0] < b.data[bNum][0] or (a.data[aNum][0] == b.data[bNum][0]
        and a.data[aNum][1] < b.data[bNum][1]))
        {
            sum.insert(a.data[aNum][0],a.data[aNum][1],a.data[aNum][2]);
            aNum++;
        } 
        else 
        {
            int addedval = a.data[aNum][2] + b.data[aNum][2];
            if (addedval != 0)
            {
                sum.insert(a.data[aNum][0],a.data[aNum][1],addedval);
            }
            aNum++;
            bNum++;
        }
    }
    while (aNum < a.sparseRow)
    {
        sum.insert(a.data[aNum][0],a.data[aNum][1],a.data[aNum][2]);
        aNum++;
    }
    while (bNum < b.sparseRow)
    {
        sum.insert(b.data[bNum][0],b.data[bNum][1],b.data[bNum][2]);
        bNum++;
    }
    sum.display();
}
int main() 
{
    Matrix a;
    int choice;
    char option;
    do
    {
        cout<<"------------------SPARSE MATRIX  OPERATIONS----------------"<<endl;
        cout<<"Choose any option from the following : "<<endl;
        cout<<"1. Creation"<<endl;
        cout<<"2. Transpose"<<endl;
        cout<<"3. Addition"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter the choice : "<<" ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                a.allocate();
                a.addEntries();
                a.display();
                break; 
            }
            case 2:
            {
                a.transpose();     
                break;
            }
            case 3:
            {
                cout<<"Enter one more matrix  "<<endl;
                Matrix b;
                b.allocate();
                b.addEntries();
                addMatrix(a, b);
                break;
            }
            case 4:
            {
                break;
                default:cout<<"Invalid choice ! Please choose another option"<<endl;
            }
        }
        if (choice != 4)
        {
            cout<<endl;
            cout<<"------------------------------------------------------------"<<endl;
            cout<<"\nDo you want to continue(y/n) ? : "<<" ";
            cin>>option;
            cout<<endl;
            if(option == 'n')
            {
                choice = 4;
            }
        }
    } while (choice!=4);
    cout<<"\n-------------------------END--------------------------------"<<endl; 
    return 0;
}
