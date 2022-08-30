

//Quick Sort
#include<iostream>
using namespace std;
int Partition(int *A,int LB,int UB)
{
    int pivot = A[LB];
    int START = LB;
    int END = UB;
    while(START < END)
    {
        while(A[START] <= pivot)
        {
            START++;
        }
        while(A[END] > pivot)
        {
            END--;
        }
        if(START < END)
        {
            int temp = A[START];
            A[START] = A[END];
            A[END] = temp;
        }
    }
    int t1 = A[LB];
    A[LB] = A[END];
    A[END] = t1;
    return END;
}
void QuickSort(int *A,int LB,int UB)
{
    if (LB < UB)
    {
        int LOC = Partition(A,LB,UB);
        QuickSort(A,LB,LOC-1);
        QuickSort(A,LOC+1,UB);
    }
    
    
}
void display(int *A, int n)
{
    cout<<"The sorted list is : "<<"  ";
    for(int i = 0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }
    
}
int main()
{
    int n;
    cout<<"Enter the number of elements : "<<" ";
    cin>>n;
    int A[n];
    cout<<"Enter the elements : "<<" ";
    for(int i = 0; i<n; i++)
    {
        cin>>A[i];
    }
    cout<<"The array is : "<<"  ";
    for(int i = 0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    int LB = 0;
    int UB = n;
    QuickSort(A,LB,UB);
    display(A,n);
    

}
