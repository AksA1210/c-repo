
//Sort
#include<iostream>
using namespace std;
void bubble_sort(int DATA[],int N)
{
    for(int k=0;k<N-1;k++)
    {
        for(int j=0;j<N-k;j++)
        {
            if (DATA[j]>DATA[j+1])
            {
                int TEMP=DATA[j+1];
                DATA[j+1]=DATA[j];
                DATA[j]=TEMP;
            }
        }
    }
    cout<<"After Bubble Sort : "<<" ";
    for(int i=0;i<N;i++)
    {
        cout<<DATA[i]<<" ";
    }
}
void selection_sort(int DATA[],int N)
{
    for(int k=1;k<N-1;k++)
    {
        for(int j=1;j<N-k;j++)
        {
            if (DATA[j-1]>DATA[j])
            {
                int TEMP=DATA[j];
                DATA[j]=DATA[j-1];
                DATA[j-1]=TEMP;
            }
        }
    }
    cout<<"After Selection Sort : "<<" ";
    for(int i=0;i<N;i++)
    {
        cout<<DATA[i]<<" ";
    }
}
void insertion_sort(int A[],int N)
{
    for(int k=2;k<N+1;k++)
    {
        int TEMP=A[k];
        int PTR=k-1;
        while (TEMP<A[PTR])
        {
            A[PTR+1]=A[PTR];
            PTR--;
        }
        A[PTR+1]=TEMP;
    }
    cout<<"After Insertion Sort : "<<" ";
    for(int i=0;i<N;i++)
    {
        cout<<A[i]<<" ";
    }
}
void merge_sort()
{

}

int main()
{
    int choice;
    int N;
    cout<<"Enter the number of elements : "<<" ";
    cin>>N;
    int DATA[N];
    for(int i=0;i<N;i++)
    {
        cin>>DATA[i];
    }
    for(int i=0;i<N;i++)
    {
        cout<<DATA[i]<<" ";
    }
    do
    {
         cout<<"\n----------------------SORTING TECHNIQUES--------------------------"<<endl;
         //cout<<"\n1.Create new set";
    cout<<"\n1.Bubble Sort";
    cout<<"\n2.Selection Sort";
    cout<<"\n3.Insertion Sort";
    cout<<"\n4.Merge Sort";
    //cout<<"\n5.Display";
    cout<<"\n6.Exit";
    cout<<"\nEnter your choice : "<<" ";
    cin>>choice;
    cout<<"Before Sorting : "<<" ";
    for(int i=0;i<N;i++)
    {
        cout<<DATA[i]<<"  ";
    }
    cout<<endl;
    switch(choice)
    {
        case 1:
        {

            bubble_sort(DATA,N);

        }
        break;
        case 2:
        {

            selection_sort(DATA,N);

        }
        break;
        case 3:
        {

            insertion_sort(DATA,N);

        }
        break;
        case 4:
        {

            merge_sort();

        }
        break;
        case 5:
        {
            //display();

        }
        break;
        case 6:
        {
             break;
        }
        default:cout<<("Wrong choice\n");
    }
    char p;
    if(choice!=6)
    {
        cout<<"\nDo you want to continue(y/n) ? "<<" ";
        cin>>p;
        if (p=='n')
        {
            choice=6;
        }
    }
    }while(choice!=6);
    return(0);
}
