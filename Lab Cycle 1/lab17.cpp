

#include<iostream>                        //lc 2 q5              //change pls
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
class test : public student
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
    cout<<"Marks secured by the student in Subject 1 : "<<sub1<<endl;
    cout<<"Marks secured by the student in Subject 2 : "<<sub2<<endl;
}
class sports
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
    cout<<"Marks secured by the student in sports : "<<score<<endl;
    
}
void result::display(void)
{
    total=sub1+sub2+score;
    put_number();
    put_marks();
    put_score();
    cout<<"Total marks secured by the student : "<<total<<endl;
}

int main()
{
    result student1;
    int rno;
    cout<<"Enter the rollno of the student : "<<" ";
    cin>>rno;
    student1.get_number(rno);
    int mark1,mark2;
    cout<<"Enter the marks secured by the student for subject1 : "<<" ";
    cin>>mark1;
    cout<<"Enter the marks secured by the student for subject2 : "<<" ";
    cin>>mark2;
    student1.get_marks(mark1,mark2);
    int score;
    cout<<"Enter the marks secured by the student for sports : "<<" ";
    cin>>score;
    cout<<"--------------------STUDENT PROFILE--------------------"<<endl;
    student1.get_score(score);
    student1.display();
    return(0);
}


