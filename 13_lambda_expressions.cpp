/*
@author: Rajasekhar Mugada
@brief : Examples explaining usage of lambda expressions
         Lambda functions are un-named in-line functions/expressions
*/

#include <iostream>
using namespace std;

/*
Different ways of defining lambda functions:
[<captures>](<parameters>)< -> return type >{<function body>}
captures :
[=] copy capture , capture all variables (copies) in the current scope
[&] reference capture,  capture all variables (references) in the current scope
[ ] empty capture, do not capture any variable
[i] capture the variable (copy) of the given name i
[&i] capture the variable (reference) of the given name i
Return type:
Can be left out if compiler can derive
Can implicitly specify
*/

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 3, 4, 5, 6};
    int c[5];

    /* Print array variables using lambda expression */
    auto lambda_print = [&](int arr[], int size)
    {
        for (int i = 0; i < size ; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    };

    cout << "printing array elements using lambda expression: " << endl;
    cout << "a: "; lambda_print(a, sizeof(a)/sizeof(a[0]));
    cout << "b: "; lambda_print(b, sizeof(b)/sizeof(b[0]));
    cout << "c: "; lambda_print(c, sizeof(c)/sizeof(c[0]));

    return 0;
}
