/*
@author: Rajasekhar Mugada
@brief : Polymorphism example
    Polymorphism is generalized inheritance -
    where base class is abstract and child classes are specialized.
*/

#include <iostream>
using namespace std;

/* Abstract parent class */
class Shape
{
public:
    Shape()
    {
        ;
    }
    ~Shape()
    {
        ;
    }

    virtual float area() = 0;
    virtual float perimeter() = 0;
};

/* Child class 1 : rectangle shape */
class Rectangle : public Shape
{
private:
    float length;
    float breadth;
public:
    Rectangle(float l = 0, float b = 0)
    {
        length = l;
        breadth = b;
    }
    ~Rectangle()
    {
        ;
    }
    float area();
    float perimeter();
};

float Rectangle :: area()
{
    return length*breadth;
}
float Rectangle :: perimeter()
{
    return 2*(length + breadth);
}

/* Child class 2 : circle shape */
class Circle : public Shape
{
private:
    float radius;
public:
    Circle(float r = 0)
    {
        radius = r;
    }
    ~Circle()
    {
        ;
    }
    float area();
    float perimeter();
};
float Circle :: area()
{
    return 3.142*radius*radius;
}
float Circle :: perimeter()
{
    return 2*3.142*radius;
}

int main()
{
    /* base class pointer */
    Shape *shape_ptr;
    /* derived class objects */
    Rectangle rect(5, 10);
    Circle circle(10);

    float area, perimeter;
    /* polymorphism */
    shape_ptr = &rect;
    area = shape_ptr->area();
    perimeter = shape_ptr->perimeter();
    cout << "rectangle shape - area , perimeters : "
         << area << ", " << perimeter<< endl;

    shape_ptr = &circle;
    area = shape_ptr->area();
    perimeter = shape_ptr->perimeter();
    cout << "circle shape - area , perimeters : "
         << area << ", " << perimeter<< endl;

    return 0;
}
