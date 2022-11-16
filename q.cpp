#include<iostream>
using namespace std;
void quick_sort(int A[],int lb,int ub)
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
	
	
}
int main()
{
	//int n;
	/*cout<<"Enter the no: of elements : "<<" ";
	cin>>n;
	for(int i = 0; i<n; i++)
	{
		cout<<"Enter the element : "<<" ";

	}
	
*/
	int A[5] = {12,43,5,22,8};
	cout<<"The array is : "<<" ";
	for(int i = 0;i<5;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	quick_sort(A,0,5);
	cout<<"Sorted array : "<<" ";
	for(int i = 0; i<5; i++)
	{
	    cout<<A[i]<<" ";
	}
	cout<<endl;
	return(0);
}	

	 		