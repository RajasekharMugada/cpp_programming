/*
@author: Rajasekhar Mugada
@brief : basic skeleton of a class
*/

#include <iostream>
using namespace std;


//Class example with rectangle
/*
Class with standard framework:
    private data members,
    constructors,
    mutators,
    accessors,
    facilitators,
    inspector methods,
    destructor
*/

//rectangle class
class rect
{
private:
    //private data members
    int length, breadth;

public:
    /* STEP 1 : constructors ****************************************************/
    //constructor method #1 :
    //default constructor / non-parameterized constructor
    /*
    rect()
    {
        length = 0;
        breadth = 0;
    }
    */
    //constructor method #2 :
    /*
    //parameterized constructor
    rect(int l, int b)
    {
        length = l;
        breadth = b;
    }
    */
    //constructor method #3 :
    //combined constructor //non-parameterized and parameterized
    rect(int l = 0, int b = 0)
    {
        /*
        length = l;
        breadth = b;
        */
        //"this pointer" can also be used for accessing member variables
        this -> length = l;
        this -> breadth = b;
    }
    //constructor method #4 :
    //copy constructor
    //deep copy constructor : copy all the data members (even which are pointer referenced)
    rect( rect & r)
    {
        length = r.length;
        breadth = r.breadth;
    }

    /* STEP 2 : mutators & accessors / write & read  ************************************/
    //mutators
    void set_length(int l);
    void set_breadth(int b);
    //accessors
    int get_length();
    int get_breadth();

    /* STEP 3 : facilitators / main functions *******************************************/
    //in-line function. very small code footprint is recommended
    //machine code will be generated inside caller function
    int perimeter()
    {
        return 2*(length + breadth);
    }
    //global function using scope resolution operator
    //machine code will be generated separately (outside main)
    int area();

    /* STEP 4 : Inspector methods / enquiry methods**************************************/
    int is_square();

    /* STEP 5 : Destructor **************************************************************/
    ~rect();
};

//Member functions - global definition
//machine code will be generated separately (out side caller function)
void rect :: set_length(int l)
{
    length = (l > 0) ? l : 0;
}
void rect :: set_breadth(int b)
{
    breadth = (b > 0) ? b : 0;
}
int rect :: get_length()
{
    return length;
}
int rect :: get_breadth()
{
    return breadth;
}
int rect :: area()
{
    return length*breadth;
}
int rect :: is_square()
{
    return (length == breadth) ? true : false;
}

rect :: ~rect()
{
    cout << "object destroyed" << endl;
}

int main()
{
    //Memory for object's data members gets created inside stack
    //Memory for class's member functions gets created in code section not in stack.

    rect r1;            //default/non-parameterized constructor used
    rect r2(10, 5);     //parameterized constructor used
    rect r3(r2);        //copy constructor used

    cout << r1.area() << endl;
    cout << r2.area() << endl;
    cout << r3.area() << endl;
    cout << r3.is_square() << endl;
    cout << r3.perimeter() << endl;

    return 0;
}
