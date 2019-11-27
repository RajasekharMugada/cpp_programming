/*
@author: Rajasekhar Mugada
@brief : Templates are used to optimize duplicate code section by generalizing data types
    Example 1: Function templates
    Example 2: Class templates
    Example 3: Template specialization
    Example 4: Non-type parameter for templates
*/

#include <iostream>
using namespace std;

//Example 1: Function templates

template <class T>       //template <typename T> or template <class T>
T fn_max(T a, T b)
{
    return (a > b? a : b);
}

template <class A, class B>
A fn_min(A a, B b)
{
    return (a < b? a: b);
}


//Example 2: Class Templates
template <class T>
class compare
{
private:
    T a, b;
public:
    compare(T a = 0, T b = 0)
    {
        this->a = a;
        this->b = b;
    }
    T max(){return (a > b? a : b);}
    T min(){return (a < b? a : b);}
};

//Example 3: Template specialization
//Data type specific implementation for a class.
//For other data types general class template shall be taken by-default.
template <>
class compare <char>
{
private:
    char a, b;
public:
    compare(char c1 = 0, char c2 = 0)
    {
        a = c1;
        b = c2;

        //not case sensitive: convert all to upper case
        a = (a >= 'a' && a <= 'z')? (a - 'a' + 'A') : a;
        b = (b >= 'a' && b <= 'z')? (b - 'a' + 'A') : b;
    }

    char max(){return (a > b? a : b);}
    char min(){return (a < b? a : b);}
};

//Example 4: Non-type parameter for templates

template <class T, int c>
int fn_min_ref(T a, T b)
{
    if(a < b && b < c)
        return a;
    else if( b < c)
        return b;
    else
        return c;
}

template <class T, int c>
int fn_max_ref(T a, T b)
{
    if(a > b && b > c)
        return a;
    else if( b > c)
        return b;
    else
        return c;
}


int main()
{
    //Example 1: Function templates
    cout << "Example 1: Function templates" << endl;
    cout << fn_max<int>(1, 2) << endl;
    cout << fn_max<float>(2.1, 10.1) << endl;
    cout << fn_min<float, int>(2.1, 10) << endl;
    cout << fn_min<float, double>(2.1, 10.1) << endl;

    //Example 2: Class Templates
    cout << "Example 2: Class Templates" << endl;
    compare <float> compare_obj(2.1, 10.1);
    cout << compare_obj.min() << endl;
    cout << compare_obj.max() << endl;

    compare <int> compare_obj2(2.1, 10.1);
    cout << compare_obj2.min() << endl;
    cout << compare_obj2.max() << endl;

    //Example 3: Template specialization
    cout << "Example 3: Template specialization" << endl;
    compare <char> compare_obj3('A', 'b');
    cout << compare_obj3.min() << endl;
    cout << compare_obj3.max() << endl;

    //Example 4: Non-type parameter for templates
    cout << "Example 4: Non-type parameter for templates" << endl;
    cout << fn_min_ref<float, 1>(2.1, 4.2) << endl;
    cout << fn_max_ref<float, 1>(2.1, 4.2) << endl;
    return 0;
}
