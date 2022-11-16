
#include<iostream>
#include <ctime>
#include <iomanip>
#include<cstdlib>
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
    char choice;
    do
    {
        cout<<"Enter the number of elements : "<<" ";
        cin>>n;
        int A[n];
        int endpt;
        cout<<"Enter the end point : "<<" ";
        cin>>endpt;
        for(int i = 0; i<n; i++)
        {
            A[i] = 1+rand()%endpt;
        }
        cout<<"The array is : "<<"  ";
        for(int i = 0; i<n; i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
        int LB = 0;
        int UB = n;
        clock_t start = clock(); 
        QuickSort(A,LB,UB);
        clock_t finish = clock();
	    double doneTime = double(finish-start)/double(CLOCKS_PER_SEC/1000);
	    cout<< " You took " << fixed << doneTime << setprecision(8) << " milliseconds\n";
        display(A,n);
        cout<<endl;
        cout<<"Do you want to continue(y/n)? : "<<" ";
        cin>>choice;
    } while (choice!='n');    
}