#include<iostream>
using namespace std;
int partition(int *A,int lb,int ub)
{
	int pivot = lb;
	int start = lb;
	int end = ub;
	while(start < end)
	{
		do
		{
			start++;
		} while(A[start] <= A[pivot]);
		do
	    {
			end--;
	    }while(A[end] >= A[pivot]);
	    if (start < end)
	    {
			int temp = A[start];
			A[start] = A[end];
			A[end] = temp;
	    }
	}
	int var = A[pivot];
	A[pivot] = A[end];
	A[end] = var;
	return end;
	
}
void quick_sort(int *A,int l,int h)
{
	if (l < h)
    {
        int LOC = partition(A,l,h);
        quick_sort(A,l,LOC-1);
        quick_sort(A,LOC+1,h);
    }

}
void display(int *A,int n)
{
	cout<<"Sorted array : "<<" ";
	for(int i = 0; i<n; i++)
	{
	    cout<<A[i]<<" ";
	}
}
int main()
{
	int n;
	cout<<"Enter the no: of elements : "<<" ";
	cin>>n;
	int l,h;
	l=0;
	h=n;
	int A[n];
	for(int i = 0; i<n; i++)
	{
		cout<<"Enter the element : "<<" ";
		cin>>A[i];

	}
	cout<<"Elements are : "<<" ";
	for(int i = 0; i<n; i++)
	{
		cout<<A[i]<<" ";
	}
	//int A[5] = {12,43,5,22,8};
	
	quick_sort(A,l+1,h);
	cout<<endl;
	display(A,n);
	cout<<endl;
	return(0);
}	

	 		