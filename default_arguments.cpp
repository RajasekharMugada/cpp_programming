
/*
@author: Rajasekhar Mugada
@brief : Default arguments
*/

#include <iostream>
using namespace std;

int sum(int a, int b, int c = 0)
{
    return a+b+c;
}


/*
//Note: default arguments should be declared from right to left
//without skipping any
int sum(int a, int b = 0, int c = 0) //valid
int sum(int a, int b = 0, int c)     //not-valid
*/

int main()
{
    cout << sum(1, 2) << endl;
    cout << sum(1, 2, 3) << endl;

    return 0;
}

