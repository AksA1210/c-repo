#include<iostream>                               //lc 2 q6
using namespace std;
class student
{
    protected:
       int roll_no;
    public:
       void get_number(int);
       void put_number(void);
};
void student::get_number(int a)
{
    roll_no=a;
}
void student::put_number()
{
    cout<<"Roll no : "<<roll_no<<endl;
}
class test:virtual public student
{
    protected:
      float sub1;
      float sub2;
    public:
      void get_marks(float,float);
      void put_marks(void);
};
void test::get_marks(float x,float y)
{
    sub1=x;
    sub2=y;
}
void test::put_marks()
{
    cout<<"Marks secured in subject1 : "<<sub1<<endl;
    cout<<"Marks secured in subject2 : "<<sub2<<endl;
}
class sports: virtual public student
{
    protected:
      int score;
    public:
      void get_score(float);
      void put_score(void);
      
}; 
class result:public test,public sports
{
    float total;
    public:
      void display(void);
};

void sports::get_score(float s)
{
   score=s;
    
}
void sports::put_score()
{
    cout<<"Marks secured in sport1 : "<<score<<endl;
    
}
void result::display(void)
{
    total=sub1+sub2+score;
    put_number();
    put_marks();
    put_score();
    cout<<"Total marks secured : "<<total<<endl;
}
char p;
int main()
{
    do{
    result student1;
    int rno;
    cout<<"Enter the rollno of the student : "<<" ";
    cin>>rno;
    student1.get_number(rno);
    int mark1,mark2;
    cout<<"Enter the marks secured by the student for subject1(out of 100) : "<<" ";
    cin>>mark1;
    cout<<"Enter the marks secured by the student for subject2(out of 100) : "<<" ";
    cin>>mark2;
    student1.get_marks(mark1,mark2);
    int score;
    cout<<"Enter the marks secured by the student for sports(out of 10) : "<<" ";
    cin>>score;
    cout<<"--------------------STUDENT PROFILE--------------------"<<endl;
    student1.get_score(score);
    student1.display();
    cout<<"Do you want to continue(y/n)? "<<endl;
    cin>>p;
    }
    while (p!='n');
    return(0);
}
      
