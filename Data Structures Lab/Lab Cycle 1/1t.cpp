#include<iostream>
using namespace std;

void INSERT(int DATA[],int N,int POS,int ITEM)
{
  cout<<"\n\tElement Inserted"<<endl;
  while (N >= POS)
  {
    DATA[N] = DATA[N -1];
    N = N - 1;
  }
  DATA[POS] = ITEM;
}

int DELETE(int DATA[],int N,int ITEM)
{
  cout<<"\n\tDELETION OF ELEMENTS"<<endl;
  for (int index = 0 ; index<N ; index++)
  {
    if(ITEM == DATA[index])
    {
      for (int Number = index; Number< N;Number++)
      {
        DATA[Number] = DATA[Number+1];
      }
      return 1;
    }
  }
  return 0;
}

int main()
{
  int num,element,position,choice,no_of_terms;
  char option;
  cout<<endl;
  cout<<"-----INSERTING AND DELETING ELEMENT FROM ARRAY-----"<<endl;
  cout<<endl;
  cout<<"Enter the number of elements  : ";
  cin>>num;
  int Arr[num];
  for (int i=0;i<num;i++)
  {
    cout<<"Enter the element : ";
    cin>>Arr[i];
  }
  cout<<endl;
  cout<<"\n Array = "<<" ";
  for (int i=0;i<num;i++)
  {
    cout<<Arr[i]<<"  ";
  }
  do
  {
    cout<<"\n\n--------------------------------------------------"<<endl;
    cout<<" Choose any of the following option : "<<endl;
    cout<<" 1. Insert "<<endl;
    cout<<" 2. Delete "<<endl;
    cout<<" 3. Exit "<<endl;
    cout<<endl;
    cout<<" Enter the choice : "<<" ";
    cin>>choice;
    cout<<endl;
    cout<<"--------------------------------------------------"<<endl;
    switch(choice)
    {
      case 1: 
      { 
        cout<<"Enter the number of elements to insert : ";
        cin>>no_of_terms;
        Arr[num+no_of_terms];
        for(int i=0;i<no_of_terms;i++)
        {
          cout<<endl;
          cout<<"Enter the element to insert            : ";
          cin>>element;
          cout<<"Enter position to insert               : ";
          num = num+1;
          cin>>position;
          position = position-1;
          INSERT(Arr,num,position,element);
        }
        cout<<"\n\tAfter Insertion "<<endl<<endl;
        cout<<"\n\tArray = "<<" ";
        for (int i=0;i<num;i++)
        {
          cout<<Arr[i]<<"  ";
        }
        break; 
      }
      case 2:
      {
        if(num != 0)
        {
          cout<<endl;
          cout<<"Enter the element to be deleted :  : ";
          cin>>element;
          if (DELETE(Arr,num,element) == 0)
	        {
	          cout<<"\nElement not found"<<endl;
	        }
          else
          {     
 	          cout<<"\n\t   After Deletion "<<endl<<endl;
            cout<<"\n\tArray = "<<" ";
	          for ( int i=0;i<num-1;i++)
	          {
  		        cout<<Arr[i]<<"  ";
            }
 	          cout<<endl;
 	          num = num-1;
 	        } 
 	      }
 	      else
 	      {
 	        cout<<"\nUNDERFLOW"<<endl;
          cout<<"No elements in the array to delete"<<endl;
 	      }  
 	      break; 
 	    }
      case 3: 
      cout<<"\n\t\t\t END   "<<endl;
      cout<<"\n--------------------------------------------------";
      break;
      default: cout<<"Wrong Choice"<<endl;
    }
    if (choice != 3)
    {
      cout<<"\n--------------------------------------------------";
      cout<<"\nDo you want to continue (y/n) ? : "<<" ";
      cin>>option;
      if(option == 'n')
      {
        choice = 3;
      }
    }
  }while(choice != 3); 
  return 0;
}