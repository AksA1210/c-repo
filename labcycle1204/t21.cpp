#include <iostream>                         //q21 cont
using namespace std;

class Shape 
{
   protected:
    float dimension;

   public:
    void get_dimension() 
    {
        cin >> dimension;
    }

    virtual void calculate_area() = 0;
};

class Square : public Shape 
{
   protected:
    float areaSquare;

   public:
    void calculate_area() 
    {
        areaSquare=dimension * dimension;
        cout<<"Area of square = " << areaSquare <<endl;
    }
};

class Circle : public Shape 
{
   protected:
    float areaCircle;
   public:
    void calculate_area() 
    {
        areaCircle = 3.14 * dimension * dimension;
        cout<<"Area of circle = " << areaCircle <<endl;
    }
};
char p;
int main() 

{
    int x;
    Shape *shapeptr;
    do
    {
        cout<<"Choose any option from the following : "<<endl;
        cout<<"1 : AREA OF A CIRCLE "<<endl;
        cout<<"2 : AREA OF A SQUARE "<<endl;
        cout<<"3 : EXIT "<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>x;  
        switch(x)
        {
            case 1 :
            {
                shapeptr = new Circle;
                cout << "Enter radius of the circle: "<<endl;
                shapeptr ->get_dimension();
                shapeptr ->calculate_area();
                break;
            }
            case 2 :
            {
                shapeptr = new Square;
                cout << "Enter the length of the square: "<<endl;
                shapeptr ->get_dimension();
                shapeptr ->calculate_area();
                break;
            }
            case 3 :
            {
                break;
                default:cout<<"\nError ! Please try again\n"<<endl;
            }
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
  
        
        
