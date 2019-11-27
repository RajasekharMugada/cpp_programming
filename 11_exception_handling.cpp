/*
@author: Rajasekhar Mugada
@brief : Execption handling
    Example 1: Throw and catch exceptions from the same function stack
    Example 2: Throw and catch exceptions from different function stacks
*/

#include <iostream>
using namespace std;


//Example 1: Throw and catch exceptions from the same function stack

void fn_test_throw_catch_exception(int a, int b, int c)
{
    try
    {
        if(a == 0 && b != 0 && c != 0)
        {
            throw 101;  //here error code - 101
        }
        else if (a == 0 && b == 0 && c != 0)
        {
            throw  string("a, b are zeros");
        }
        else if (a == 0 && b == 0 && c == 0)
        {
            throw 1.0f;
            throw 2.0;
        }

        c = b/a;
        cout << "c = b/a = " << c  << endl;
    }

    //Catch integer type exception
    catch(int e)
    {
        if(e == 101)
            cout << "a is zero" << endl;
    }
    //catch string type exception
    catch(string s)
    {
        cout << s << endl;
    }
    //catch all / all other remaining exception
    catch(...)
    {
        cout << "a, b, c are zeros" << endl;
    }
}

//Example 2: Throw and catch exceptions from different function stacks

void fn_test_throw_exception(int a, int b, int c)
{
    if(a == 0)
        throw string("a is zero");

    c = b/a;
    cout << "c = b/a = " << c  << endl;
}
void fn_test_catch_exception(int a, int b, int c)
{
    try
    {
        fn_test_throw_exception(a, b, c);
    }
    catch(string s)
    {
        cout << s << endl;
    }
}

int main()
{
    //Example 1: Throw and catch exceptions from the same function stack
    cout  << "Example 1 :" << endl;
    fn_test_throw_catch_exception(0, 1, 1);
    fn_test_throw_catch_exception(0, 0, 1);
    fn_test_throw_catch_exception(0, 0, 0);
    fn_test_throw_catch_exception(2, 8, 0);

    //Example 2: Throw and catch exceptions from different function stacks
    cout  << "Example 2 :" << endl;
    fn_test_catch_exception(0, 1, 0);

    return 0;
}
