

#include<iostream>
using namespace std;
class search
{ 
    //int A[5]={10,15,30,48,59};
   public:
     int iterative_linear_search(int A[],int N ,int key);
     int recursive_linear_search(int A[],int N ,int key);
     
};
int search :: iterative_linear_search(int A[],int N,int key)
{
  for(int pos=0;pos<N;pos++)
  {
    if (A[pos]==key)
    {
       cout<<"The element is found at index no "<<pos<<endl;
       //return pos;
    }
  }
  return -1;
}
int search :: recursive_linear_search(int A[],int N,int key)
{
  if (N>0)
  {
    if (A[N]==key)
    {
        cout<<"The element is found at index no "<<N<<endl;
     // return N;
    }
    else
    {
      return recursive_linear_search( A,N-1,key);
    }
  }
  else
  {
      cout<<"Element not found"<<endl;
      return -1;
  }
}

int main()
{
   search s;
   int A[5]={1,2,3,4,5};
   //int key=3;
   int N=5;
   int p,q;
   cout<<"ITERATIVE LINEAR SEARCH"<<endl;
   s.iterative_linear_search(A,N,10);
   //cout<<"The element is found at index no "<<p<<endl;
   cout<<"RECURSIVE LINEAR SEARCH"<<endl;
   s.recursive_linear_search(A,N,48);
   cout<<"The element is found at index no "<<q<<endl;
   return(0);
}
    

     


