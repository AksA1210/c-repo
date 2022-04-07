#include <iostream>

using namespace std;

class student
{
    char name[20];
    int rollno;
    int marks1,marks2,marks3;
    char grade[1];
  public:
    void input();
    void calcgrade();
    void display();
};
void student::input()
{
    cout<<"Enter name of the student : "<<" ";
    cin>>name;
    cout<<"Enter rollno of the student : "<<" ";
    cin>>rollno;
    cout<<"Enter marks of the student secured for subject 1 : "<<" ";
    cin>>marks1;
    cout<<"Enter marks of the student secured for subject 2 : "<<" ";
    cin>>marks2;
    cout<<"Enter marks of the student secured for subject 3 : "<<" ";
    cin>>marks3;
}
void student::calcgrade()
{
    char grade;
    int avg;
    cout<<"Student name : "<<name<<endl;
    avg=(marks1+marks2+marks3)/3;
    cout<<"The average marks secured by the student is : "<<avg<<endl;
    if (avg>=90)
    {
        grade='A';
    }
    if (avg<90 and avg>=80)
    {
        grade='B';
    }
    if (avg<80 and avg>=70)
    {
        grade='C';
    }
    if (avg<70 and avg>=60)
    {
        grade='D';
    }
    if (avg<60)
    {
        grade='E';
    }
    if (avg<50)
    {
        grade='F';
    }
    cout<<"The grade of the student is : "<< grade<<endl;
    cout<<endl;
}
void student::display()
{
    cout<<"----------STUDENT REPORT----------"<<endl;
    cout<<"The name of the student is : "<< name<<endl;
    cout<<"The rollno of the student is: "<< rollno<<endl;
    cout<<"The marks of the student secured in subject1 is : "<< marks1<<endl;
    cout<<"The marks of the student secured in subject2 is : "<< marks2<<endl;
    cout<<"The marks of the student secured in subject3 is : "<< marks3<<endl;
    cout<<endl;
}
int main()
{
    
    int n;
    cout<<"Enter number of students :"<<" ";
    cin>>n;
    student a[n];
    int x;
    do
    {
        cout<<"Choose any option from the following : "<<endl;
        cout<<"1 : Input the details of the student "<<endl;
        cout<<"2 : Calculate the grade secured by the student "<<endl;
        cout<<"3 : Display the details of the student "<<endl;
        cout<<"4 : Exit "<<endl;
        cout<<endl;
        cout<<"\n\nEnter your choice : "<<" ";
        cin>>x;
        switch(x)
        {
            case 1: 
            for(int i=0; i<n;i++)
                a[i].input();
            break;
            case 2:
            {
                for(int i=0; i<n;i++)
                {
                    a[i].calcgrade();
                }
            }
            break;
            case 3: 
            {
                for(int i=0; i<n;i++)
                {
                    a[i].display();
                }
            }
            break;
            case 4: break;
            default:cout<<"Error ! Please try again "<<endl;
        }
        char a;
        if (x!=4)
        {
        cout<<"Do you want to continue(y/n)?"<<" ";
        cin>>a;
        if (a=='n')
        {
            x=4;
        }
        }
    } while (x!=4);
    
    return(0);
    
}    


