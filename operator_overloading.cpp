/*
@author: Rajasekhar Mugada
@brief : Explaining operator overloading using
         member and friend functions for complex numbers class
*/

#include <iostream>
using namespace std;

//complex number class
class complex
{
private:
    int real;   //real part
    int img;    //imaginary part
public:
    //default constructor is must for operator overloading
    complex(int r, int i);
    complex(complex & c);
    ~complex();

    //facilitator methods
    //Operator + overloading using member function
    complex operator + (complex c);
    //operator - overloading using friend function
friend complex operator - (complex c1, complex c2);
    //operator << overloading using friend function
friend ostream & operator << (ostream & out,  complex & c);

};

//class member function definition using scope resolution operator{
complex :: complex(int r = 0, int i = 0)
{
    this->real = r;
    this->img = i;
}
complex :: complex(complex & c)
{
    this->real = c.real;
    this->img = c.img;
}
complex :: ~complex()
{
    cout << "Object destroyed" << endl;
}

//Operator overloading using member function
complex complex :: operator + (complex c)
{
    complex t;
    t.real = this -> real + c.real;
    t.img = this -> img + c.img;
    return t;
}
//Operator overloading using friend method
//Note: Friend method is a global method and scope resolution operator
//can not be used in this case. Default constructor is must.
complex operator - (complex c1, complex c2)
{
    complex t;
    t.real = c1.real - c2.real;
    t.img = c1.img - c2.img;
    return t;
}
ostream & operator << (ostream & out,  complex & c)
{
     return out << c.real << "+i" << c.img << endl;
}

int main()
{
    //Object initialization
    complex c1;
    complex c2(5, 10);
    complex c3(c2);
    complex c4(1, 2);
    complex c5;

    //insertion operator overloading
    cout << c1;
    cout << c2;
    cout << c3;
    cout << c4;

    //+ operator overloading
    c5 = c3 + c4;
    cout << c5;
    //cout << c3 + c4 << endl; //will not work

    //- operator overloading
    c5 = c3 - c4;
    cout << c5;
    //cout << c3 - c4 << endl; //will not work

    return 0;
}

