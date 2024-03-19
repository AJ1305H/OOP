#include <iostream>

using namespace std;

class Shape
{
public:
    virtual float area()=0;
    virtual float perimeter() = 0;
};
class Rectangle : public Shape
{
    float length,breadth;
public: 
    Rectangle(float l=1, float b=1)
    {
        length = l;
        breadth = b;
    }
    float getLength(){return length;}
    float getBreadth(){return breadth;}
    float area()
    {
        return length*breadth;
    }
    float perimeter()
    {
        return 2 * (length + breadth);
    }
};

class Circle : public Shape
{
    float radius;
public:
    Circle(float radius=1)
    {
        this->radius = radius;
    }
    float getRadius(){return radius;}
    float area(){
        return (float)22/7*radius*radius;
    }
    float perimeter()
    {
        return (float)2*22/7*radius;
    }
};

int main()
{
    
   int ch=2;
   cout<<"1.Rectangle \n2.Circle\n Enetr chooise : ";
   cin>>ch;
   switch(ch)
   {
        case 1:
            float len,b;
            cout<<"Enetr length of Rectangle : ";
            cin>>len;
            cout<<"Enter breadth of Rectangle : ";
            cin>>b;
            // Shape *p = new Rectangle(len,b);
            // //Rectangle r(len,b);
            // //cout<<"Rectangle's Length : "<<r.getLength()<<endl;
            // //cout<<"Rectngle's Breadth : "<<r.getBreadth()<<endl;
            // cout<<"Area of Rectangle : "<<p->area()<<endl;
            // cout<<"Perimeter of Rectangle : "<<p->perimeter()<<endl;
            break;

        case 2:
            float rd;
            cout<<"Enter Radius of Circle : ";
            cin>>rd;
            // //Circle c(rd);
            // Shape *ptr = new Circle(rd);
            // //cout<<"Radius of Circle : "<<c.getRadius()<<endl;
            // cout<<"Area of Circle : "<<ptr->area()<<endl;
            // cout<<"Perimeter of Circle : "<<ptr->perimeter()<<endl;
            break;

        default : 
            cout<<"Wrong chooise!";
            break;
   }
    return 0;
    
}