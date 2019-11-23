
/*
@author: Rajasekhar Mugada
@brief : How recursion works with function stack calls
*/

#include <iostream>
using namespace std;

//Print values at function stack begin
//Whenever function gets entered in to function stack print the value
void recursive_print_first(int n)
{
    if(n > 0)
    {
        cout << n << endl;
        recursive_print_first(n-1);
    }
}

//Print values just before function stack exit
//After entering all (n+1) function stacks,
//at the time of function exit (one by one) print values
void recursive_print_last(int n)
{
    if(n > 0)
    {
        recursive_print_last(n-1);
        cout << n << endl;
    }
}

int main()
{
    int n = 4;
    cout << "Expected out put : 4, 3, 2, 1" << endl;
    recursive_print_first(n);

    cout << "Expected out put : 1, 2, 3, 4" << endl;
    recursive_print_last(n);

    return 0;
}
