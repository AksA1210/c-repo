#include<iostream>                        //q17 cont
using namespace std;
class car
{
    protected:
       int model_no;
    public:
       void get_no(int);
       void put_no(void);
};
void car::get_no(int a)
{
    model_no=a;
}
void car::put_no()
{
    cout<<"Model no : "<<model_no<<endl;
}
class test:public car
{
    protected:
      float speed1;
      float speed2;
    public:
      void get_speed(float,float);
      void put_speed(void);
};
void test::get_speed(float x,float y)
{
    speed1=x;
    speed2=y;
}
void test::put_speed()
{
    cout<<"Speed testing in  : "<<speed1<<endl;
    cout<<"Speed testing in the highway : "<<speed2<<endl;
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
    float avg;
    public:
      void display(void);
};

void sports::get_score(float s)
{
   score=s;
    
}
void sports::put_score()
{
    cout<<"Rating : "<<score<<endl;
    
}
void result::display(void)
{
    avg=(speed1+speed2)/2;
    put_no();
    put_speed();
    put_score();
    cout<<"Average speed : "<<avg<<endl;
    //cout<<"Overall performance : "<<score<<endl;
}
char p;
int main()
{
    int n;
    cout<<"Enter no: of cars : ";
    cin>>n;
    int x;
    int score;
    result car1[n];
    do{
    cout<<"Choose any option from the following : "<<endl;
    cout<<"1 : Input the details of the car "<<endl;
    cout<<"2 : Display the details of the car "<<endl;
    cout<<"3 : Exit "<<endl;
    cout<<"Enter your choice : "<<endl;
    cin>>x;  
    switch(x)
    {
        case 1:
        {
            for(int i=0; i<n;i++)
            {
                cout<<"CAR "<<i+1<<endl;
                int mno;
                cout<<"Enter the model number of the car : "<<" ";
                cin>>mno;
                car1[i].get_no(mno);
                int sp1,sp2;
                cout<<"Enter the maximum speed attained by the car on track1 : "<<" ";
                cin>>sp1;
                cout<<"Enter the maximum speed attained by the car on track2 : "<<" ";
                cin>>sp2;
                car1[i].get_speed(sp1,sp2);
                //int score;
                cout<<"Enter the points secured(out of 10) : "<<" ";
                cin>>score;
                car1[i].get_score(score);
                //car1[i].display();
            }
        }
        break;
        case 2:
        {
                for(int i=0; i<n;i++)
                {
                    cout<<"--------------------DETAILS OF THE CAR--------------------"<<endl;
                    car1[i].get_score(score);
                    car1[i].display();
                }
        }
        break;
        case 3 : break;
        default:cout<<"\nError ! Please try again\n"<<endl;
        }
        cout<<"Do you want to continue(y/n)? : ";
        cin>>p;
        if (p=='n')
        {
            x=3;
        }
        }
        while (x!=3);
        return(0);
}
  


