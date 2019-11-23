/*
@author: Rajasekhar Mugada
@brief : Inheritance example
    Circle class is taken as base/parent class and
    Cylinder class is derived from Circle class
*/

#include <iostream>
using namespace std;

/* Base class */
class Circle
{
private:
    float r = 0.0f;   //In class initializer - c++ 11 feature
protected:

public:
    Circle(float radius = 0)
    {
        r = radius;
        cout << "parent/circle object created" << endl;
    }
    ~Circle()
    {
        cout << "parent/circle class destroyed" << endl;
    }
    void set_radius(float r);
    float get_radius(void);
    float area(void);
    float perimeter(void);

};

/* Circle (base) class member function definition */
void Circle :: set_radius(float r)
{
    this->r = r;
}
float Circle :: get_radius(void)
{
    return r;
}
float Circle :: area(void)
{
    return 3.142f*r*r;
}
float Circle :: perimeter(void)
{
    return 2*3.142f*r;
}

/* Derived/ child class */
class Cylinder : public Circle
{
private:
    float h;
protected:

public:
    /* calling parameterized base class constructor */
    /*NOTE: Base class constructor is executed before derived class constructor */
    Cylinder(float radius = 0, float height = 0):Circle(radius)
    {
        h = height;
        cout << "child/cylinder object created" << endl;
    }
    /*NOTE: Derived class constructor is executed before base class destructor */
    ~Cylinder()
    {
        cout << "child/cylinder class destroyed" << endl;
    }

    void set_height(float h);
    float get_height(void);
    /* member function overriding */
    float area(void);
};

/* Cylinder (derived) class member function definition */

void Cylinder :: set_height(float h)
{
    this->h = h;
}
float Cylinder :: get_height(void)
{
    return h;
}
/* member function overriding */
float Cylinder :: area(void)
{
    return 2*Circle::area() + Circle::perimeter()*h;
}


int main()
{
    //base class
    Circle cir;
    cir.set_radius(10);
    //derived class
    Cylinder cyl(10, 20);

    cout << "circle area - " << cir.area()
         << " perimeter - " << cir.perimeter() << endl;
    cout << "cylinder area - " << cyl.area() << endl;

    return 0;
}
