/*
@author: Rajasekhar Mugada
@brief : bitset usage
*/

#include <iostream>
#include <string>
#include <bitset>
using namespace std;




int main()
{
    cout << "************ bitset usage *************" << endl;
    cout << endl << "***************************************"<<endl;
    cout << "constructor : " << endl;

    bitset<10> b1;
    bitset<10> b2(16);
    bitset<10> b3(string("10101010"));
    cout << "bitset<10> b1: " << b1<<endl;
    cout << "bitset<10> b2(16): " << b2<<endl;
    cout << "bitset<10> b3(string(value)): " << b3<<endl;

    cout << endl;
    cout << "***************************************"<<endl;
    cout << "Bit operations : " << endl;
    cout <<
    "                                               \n\
    set     Set bits (public member function )      \n\
    reset   Reset bits (public member function )    \n\
    flip    Flip bits (public member function )     \n\
    " << endl;

    cout << "b1 : " << b1 << endl;
    cout << endl;
    cout << "b1.set(0, 1): " << b1.set(0, 1) << endl;
    cout << "b1.set(2): " << b1.set(2) << endl;
    cout << "b1.set(): " << b1.set() << endl;
    cout << endl;
    cout << "b1.reset(0): " << b1.reset(0) << endl;
    cout << "b1.reset(): " << b1.reset() << endl;
    cout << endl;
    cout << "b1.flip(0): " << b1.flip(0) << endl;
    cout << "b1.flip(): " << b1.flip() << endl;

    cout << endl;
    cout << "***************************************"<<endl;
    cout << "Access : " << endl;
    cout <<
    "                                                               \n\
    operator[]  Access bit (public member function )                \n\
    count       Count bits set (public member function )            \n\
    size        Return size (public member function )               \n\
    test        Return bit value (public member function )          \n\
    any         Test if any bit is set (public member function )    \n\
    none        Test if no bit is set (public member function )     \n\
    all         Test if all bits are set (public member function )  \n\
    " << endl;

    b1[3] = 0;
    cout << "b1[3] = 0" << endl;
    cout << "b1: " <<  b1 << endl;
    cout << "b1.count():  " << b1.count() << endl;
    cout << "b1.size(): " << b1.size() << endl;
    cout << "b1.test(0): " << b1.test(0) << endl;
    cout << "b1.any(): " << b1.any() << endl;
    cout << "b1.none(): " << b1.none() << endl;
    cout << "b1.all(): " << b1.all() << endl;

    cout << endl;
    cout << "***************************************"<<endl;
    cout << "Operations : " << endl;
    cout <<
    "                                                                       \n\
    to_string   Convert to string (public member function )                 \n\
    to_ulong    Convert to unsigned long integer (public member function )  \n\
    to_ullong   Convert to unsigned long long (public member function )     \n\
    " << endl;

    cout << "b1.to_string(): " << b1.to_string() << endl;
    cout << "b1.to_ulong(): " << b1.to_ulong() << endl;
    cout << "b1.to_ullong(): " << b1.to_ullong() << endl;

    cout << endl;
    cout << "***************************************"<<endl;
    cout << "operators : " << endl << endl;
    cout << " &, |, ^, <<, >>, ==, !=, ~" << endl << endl;

    bitset<8> a(string("10100010"));
    bitset<8> b(string("10001000"));

    cout << "a : " << a << "   " << "b : " << b << endl;

    b = ~b;
    cout << "b = ~b: " << b << endl;

    cout << "a : " << a << "   " << "b : " << b << endl;
    cout << "a & b: " << (a&b) << endl;

    cout << "a : " << a << "   " << "b : " << b << endl;
    cout << "a | b: " << (a|b) << endl;

    cout << "a : " << a << "   " << "b : " << b << endl;
    cout << "a ^ b: " << (a^b) << endl;

    cout << "a : " << a << "   " << "b : " << b << endl;
    cout << "a << 2: " << (a << 2) << endl;

    cout << "a : " << a << "   " << "b : " << b << endl;
    cout << "a >> 2: " << (a >> 2) << endl;

    cout << "a : " << a << "   " << "b : " << b << endl;
    cout << "a == b: " << (a == b) << endl;

    cout << "a : " << a << "   " << "b : " << b << endl;
    cout << "a != b: " << (a != b) << endl;

    return 0;
}
