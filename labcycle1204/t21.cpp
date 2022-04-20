#include <iostream>                        
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

class Cube : public Shape 
{
   protected:
    float cube_volume;

   public:
    void calculate_volume() 
    {
        cube_volume=dimension*dimension*dimension;
        cout<<"Volume of cube = " << cube_volume <<endl;
    }
};

class Sphere : public Shape 
{
   protected:
    float sphere_volume;
   public:
    void calculate_volume() 
    {
        sphere_volume =(4/3)* 3.14 * dimension * dimension * dimension;
        cout<<"Volume of sphere = " << sphere_volume <<endl;
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
        cout<<"1 : VOLUME OF A CUBE  "<<endl;
        cout<<"2 : VOLUME OF A SPHERE"<<endl;
        cout<<"3 : EXIT "<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>x;  
        switch(x)
        {
            case 1 :
            {
                shapeptr = new Cube;
                cout << "Enter the edge length of the cube: "<<endl;
                shapeptr ->get_dimension();
                shapeptr ->calculate_volume();
                break;
            }
            case 2 :
            {
                shapeptr = new Sphere;
                cout << "Enter radius of the circle: "<<endl;
                shapeptr ->get_dimension();
                shapeptr ->calculate_volume();
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
  
        
        
