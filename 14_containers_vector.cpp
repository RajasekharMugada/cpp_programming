/*
@author: Rajasekhar Mugada
@brief : Vector container examples:
    Iterators: begin, end, rbegin, rend, cbegin, cend, crbegin, crend
    Capacity: size, max_size, resize, capacity, empty, reserve, shrink_to_fir
    Element access: operator[], at, front, back, data
    Modifiers: assign, push_back, pop_back, insert, erase, swap, clear, emplace, emplace_back
*/

#include <iostream>
#include <vector>
using namespace std;


int main()
{
    //lambda function for printing the int type vectors
    auto print_vec = [&](vector<int> &v)
    {
        for (vector <int>::iterator it = v.begin(); it != v.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    };

    //vector constructor
    cout << endl;
    cout << "***********************************************************" << endl;
    cout << "vector constructor - default constructor: "<<endl;
    vector<int> u1;
    cout << "vector : "; print_vec(u1);
    cout << "vector constructor - 4 elements with value 8: " << endl;
    vector<int> u2(4, 8);
    cout << "vector : "; print_vec(u2);
    cout << "vector constructor - create vector with 4 values, not initialized: "<<endl;
    vector<int> u3(4);
    cout << "vector : "; print_vec(u3);


    //Operators:
    cout << endl;
    cout << "***********************************************************" << endl;
    cout << "Operator =  "<< endl;
    cout << "create new vector from existing vector: ";
    vector<int> u4;
    u4 = u2;
    cout << "vector : "; print_vec(u4);
    cout << "clear vector: ";
    u4 = vector<int>();
    cout << "vector : "; print_vec(u4);

    //Relational operators
    cout << endl;
    cout << "***********************************************************" << endl;
    cout << "Relational operators: " << endl;

    {
        vector<int> a = {1, 2, 3, 4};
        vector<int> b = {1, 2, 3, 0};

        cout << "a = "; print_vec(a);
        cout << "b = "; print_vec(b);

        if(a == b)
            cout << "a, b are equal" << endl;
        if(a != b)
            cout << "a, b are not equal" << endl;
        if(a > b)
            cout << "a is greater than b" << endl;
        if(a < b)
            cout << "a is less than b" << endl;
        if(a >= b)
            cout << "a is greater than or equal to b" << endl;
        if(a <= b)
            cout << "a is less than or equal to b" << endl;
    }
    {
        vector<int> a = {1, 2, 3, 4};
        vector<int> b = {1, 2, 5, 4};

        cout << "a = "; print_vec(a);
        cout << "b = "; print_vec(b);

        if(a == b)
            cout << "a, b are equal" << endl;
        if(a != b)
            cout << "a, b are not equal" << endl;
        if(a > b)
            cout << "a is greater than b" << endl;
        if(a < b)
            cout << "a is less than b" << endl;
        if(a >= b)
            cout << "a is greater than or equal to b" << endl;
        if(a <= b)
            cout << "a is less than or equal to b" << endl;
    }

    //Iterators
    cout << endl;
    cout << "***********************************************************" << endl;
    cout << "Iterators : "<< endl;
    vector <int> v1 = {1, 2, 3, 4, 5};
    cout << " v1: " ;
    for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //reverse order
    cout << " v1: in reverse order : " ;
    for(vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //Capacity
    cout << endl;
    cout << "***********************************************************" << endl;
    cout << "Capacity : "<< endl;
    //Capacity: size, max_size, resize, capacity, empty, reserve, shrink_to_fir
    /*
    size()      – Returns the number of elements in the vector.
    max_size()  – Returns the maximum number of elements that the vector can hold.
    capacity()  – Returns the size of the storage space currently allocated to
                    the vector expressed as number of elements.
                    This capacity is not necessarily equal to the vector size.
                    It can be equal or greater, with the extra space allowing
                    to accommodate for growth without the need to reallocate on each insertion.
    resize(n)   – Resizes the container so that it contains ‘n’ elements.
    empty()     – Returns whether the container is empty.
    shrink_to_fit() – Reduces the capacity of the container to fit its size and
                    destroys all elements beyond the capacity.
    reserve()   – Requests that the vector capacity be at least enough to contain n elements.
    */

    cout << "v1: size : "<<v1.size()<<endl;
    cout << "v1: capacity : "<<v1.capacity()<<endl;
    cout << "Is v1: empty ? : " << v1.empty() << endl;
    cout << "v1: max size : "<<v1.max_size()<<endl;

    v1.reserve(10);
    cout << "v1: after reserve to 10 : ";
    print_vec(v1);
    cout << "v1: size : "<<v1.size()<<endl;
    cout << "v1: capacity : "<<v1.capacity()<<endl;

    v1.resize(4);
    cout << "v1: after resize to 4 : ";
    print_vec(v1);
    cout << "v1: size : "<<v1.size()<<endl;
    cout << "v1: capacity : "<<v1.capacity()<<endl;

    v1.shrink_to_fit();
    cout << "v1: after shrink to fit call: ";
    print_vec(v1);
    cout << "v1: size : "<<v1.size()<<endl;
    cout << "v1: capacity : "<<v1.capacity()<<endl;


    //Element access
    /*
    reference operator [g] – Returns a reference to the element at position ‘g’ in the vector
    at(g) – Returns a reference to the element at position ‘g’ in the vector
    front() – Returns a reference to the first element in the vector
    back() – Returns a reference to the last element in the vector
    data() – Returns a direct pointer to the memory array used internally
                by the vector to store its owned elements.
    */
    cout << endl;
    cout << "***********************************************************" << endl;
    cout << "Element access : "<< endl;

    cout << "v1: increment using operator [] : ";
    for (int i = 0; i<v1.size(); i++)
    {
        cout << ++v1[i] << " ";
    }
    cout << endl;
    cout << "v1: increment using at() : ";
    for (int i = 0; i<v1.size(); i++)
    {
        cout << ++v1.at(i) << " ";
    }
    cout << endl;

    cout << "v1: increment first element using front(): "<<++v1.front() << endl;
    cout << "v1: increment last element using back(): "<<++v1.back() << endl;
    cout << "v1: print elements from the data() pointer : ";
    int * data_ptr = v1.data();
    for (int i = 0; i<v1.size(); i++)
    {
        cout << *data_ptr << " ";
        ++data_ptr;
    }
    cout << endl;

    //Modifiers:
    /*
    assign()    – It assigns new value to the vector elements by replacing old ones
    push_back() – It push the elements into a vector from the back
    pop_back()  – It is used to pop or remove elements from a vector from the back.
    insert()    – It inserts new elements before the element at the specified position
    erase()     – It is used to remove elements from a container from the
                    specified position or range.
    swap()      – It is used to swap the contents of one vector with another vector
                    of same type. Sizes may differ.
    clear()     – It is used to remove all the elements of the vector container
    emplace()   – It extends the container by inserting new element at position
    emplace_back() – It is used to insert a new element into the vector container,
                    the new element is added to the end of the vector
    */

    cout << endl;
    cout << "***********************************************************" << endl;
    cout << "Modifiers : "<< endl;

    cout << "v2: assign() usages: "<<endl;
    //vector<int> v2(4, 10); print_vec(v2);
    //v2 = vector<int>(); print_vec(v2);
    //decltype(v2) v2; print_vec(v2);
    vector<int> v2;
    v2.assign(6, 20); print_vec(v2);
    v2.assign(v1.begin(), v1.end()); print_vec(v2);
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    v2.assign(arr, arr+3); print_vec(v2);

    decltype(v1) v3;
    cout << "v3: using push_back() : ";
    for(vector <int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        v3.push_back(*it);
    }
    print_vec(v3);

    v3.pop_back();
    cout << "v3: pop_back() : "; print_vec(v3);

    cout << "v3: insert() 50 at position 2: ";
    v3.insert(v3.begin()+2, 50); print_vec(v3);
    cout << "v3: insert() 2 times value 10 at position 3: ";
    v3.insert(v3.begin()+3, 2, 10); print_vec(v3);
    cout << "v3: insert() append all elements of v2: ";
    v3.insert(v3.end(), v2.begin(), v2.end()); print_vec(v3);

    cout << "v3: erase() element at position 2: ";
    v3.erase(v3.begin()+2); print_vec(v3);
    cout << "v3: erase() element from position 2 to end: ";
    v3.erase(v3.begin()+2, v3.end()); print_vec(v3);

    cout << "v1, v2: before swap()" << endl;
    print_vec(v1); print_vec(v2);
    cout << "v1, v2: after swap()" << endl;
    v1.swap(v2);
    print_vec(v1); print_vec(v2);

    cout << "v3: before clear() : ";
    print_vec(v3);
    cout << "v3: after clear() : ";
    v3.clear();
    print_vec(v3);

    cout <<"v3: emplace() add element at beginning: ";
    auto it = v3.emplace(v3.begin(), 8); print_vec(v3);
    cout <<"v3: emplace() add element before the previous allocation: ";
    v3.emplace(it, 7); print_vec(v3);
    cout <<"v3: emplace() add element before the previous allocation: ";
    v3.emplace(it, 6); print_vec(v3);
    cout<<"v3: emplace_back() add element at the end: ";
    v3.emplace_back(9); print_vec(v3);

    return 0;
}

