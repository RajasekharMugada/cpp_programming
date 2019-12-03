/*
@author: Rajasekhar Mugada
@brief : string class usage
*/

#include <iostream>
#include <string>
using namespace std;


int main()
{
    cout << "************ string class usage *************" << endl;
    cout << "template instantiations: string, wstring, u16string, u32string" << endl;
    cout << endl;
    cout << "*********************************************" << endl;
    cout << "constructor : " << endl;

    string s = string("my test string");
    string s1;
    string s2(s);
    string s3(s, 3, 4);
    string s4("new string", 6);
    string s5("new string");
    string s6(10, 'a');
    string s7(10, 43);  //ascii code 43
    string s8(s.begin(), s.begin()+6);

    cout << "s : " << s << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    cout << "s5: " << s5 << endl;
    cout << "s6: " << s6 << endl;
    cout << "s7: " << s7 << endl;
    cout << "s8: " << s8 << endl;

    cout << endl;
    cout << "*********************************************" << endl;
    cout << "Operator = :" << endl;
    s1 = "new "; cout << "s1 = new " << endl;
    s2 = "text"; cout << "s2 = text" << endl;
    s3 = s1+s2; cout << "s3 = s1 + s2 = " << s3 << endl;

    cout << endl;
    cout << "*********************************************" << endl;
    cout << "Iterators:" << endl;
    cout << "begin, end, rbegin, rend, cbegin, cend, crbegin, crend " << endl;

    cout << "display elements using iterator - s3: ";
    for(string::iterator it = s3.begin(); it != s3.end(); it++)
    {
        cout << *it;
    }
    cout << endl;

    cout << endl;
    cout << "*********************************************" << endl;
    cout << "Capacity:" << endl;
    cout << "size, length, max_size. resize, capacity, reserve, clear, empty, shrink_to_fit" << endl;
    cout << endl;

    cout << "s1: " << (s1 = "my test string") <<endl;
    cout << "s1.size(): " <<s1.size() << endl;
    cout << "s1.length(): " <<s1.length() << endl;
    cout << "s1.max_size(): " <<s1.max_size() << endl;
    cout << "s1.capacity(): " << s1.capacity() << endl;
    cout << endl;

    s1.resize(10); cout << "s1.resize(10): " << endl;
    cout << "s1: " << s1 <<endl;
    cout << "s1.size(): " <<s1.size() << endl;
    cout << "s1.length(): " <<s1.length() << endl;
    cout << "s1.max_size(): " <<s1.max_size() << endl;
    cout << "s1.capacity(): " << s1.capacity() << endl;
    cout << endl;

    s1.resize(16, '-'); cout << "s1.resize(16, '-'): " << endl;
    cout << "s1: " << s1 <<endl;
    cout << "s1.size(): " <<s1.size() << endl;
    cout << "s1.length(): " <<s1.length() << endl;
    cout << "s1.max_size(): " <<s1.max_size() << endl;
    cout << "s1.capacity(): " << s1.capacity() << endl;
    cout << endl;

    s1.reserve(20); cout << "s1.reserve(20): " << endl;
    cout << "s1: " << s1 <<endl;
    cout << "s1.size(): " <<s1.size() << endl;
    cout << "s1.length(): " <<s1.length() << endl;
    cout << "s1.max_size(): " <<s1.max_size() << endl;
    cout << "s1.capacity(): " << s1.capacity() << endl;
    cout << endl;

    s1.shrink_to_fit(); cout << "s1.shrink_to_fit(): " << endl;
    cout << "s1: " << s1 <<endl;
    cout << "s1.size(): " <<s1.size() << endl;
    cout << "s1.length(): " <<s1.length() << endl;
    cout << "s1.max_size(): " <<s1.max_size() << endl;
    cout << "s1.capacity(): " << s1.capacity() << endl;
    cout << endl;

    s1.clear(); cout << "s1.clear(): " << s1<< endl;
    cout << "s1: " << s1 <<endl;
    cout << "s1.size(): " <<s1.size() << endl;
    cout << "s1.length(): " <<s1.length() << endl;
    cout << "s1.max_size(): " <<s1.max_size() << endl;
    cout << "s1.capacity(): " << s1.capacity() << endl;
    cout << endl;

    cout << "s1.empty(): " << s1.empty() << endl;
    cout << "s1: " << s1 <<endl;

    cout << endl;
    cout << "*********************************************" << endl;
    cout << "Element access:" << endl;
    cout << "[], at, back, front" << endl;

    s1 = "my string";
    cout << "s1: " << s1 <<endl;
    cout << "s1[3] : " << s1[3] << endl;
    cout << "s1.at(4) : " << s1.at(4) << endl;
    cout << "s1.front() : " << s1.front() << endl;
    cout << "s1.back() : " << s1.back() << endl;

    cout << endl;
    cout << "*********************************************" << endl;
    cout << "Modifiers :" << endl;
    cout << "+, append, push_back, assign, insert, erase, replace, swap, pop_back" << endl;

    s1 = "string using";
    s1 = s1 + " + operator";
    cout << "s1: " << s1 <<endl;

    //append() :usage : there are multiple ways
    s1 = "string";
    s2 = " using";
    s1.append(s2);
    s1.append(" append method");
    s1.append(2, 0x2E);
    s1.append(2, '!');
    cout << "s1: " << s1 <<endl;

    //assign() : usage : there are multiple ways
    s1.assign("string using assign operator");
    cout << "s1: " << s1 <<endl;

    //insert() : usage : there are multiple ways
    s1 = "string using";
    s1.insert(s1.end(), ' ');
    s1.insert(s1.size(), "insert");
    cout << "s1: " << s1 <<endl;

    //erase() : usage : there are multiple ways
    s1 = "full length string";
    cout << "s1 before erase: " << s1 <<endl;
    s1.erase(0, 5);
    cout << "s1 after erasing first 5 elements: " << s1 <<endl;

    //replace(): usage : there are multiple ways
    s1 = "initial string";
    s1.replace(0, 7, "replaced");
    cout << "s1: " << s1 <<endl;

    //swap(): usage : there are multiple ways
    s1 = "good afternoon !!";
    s2 = "good morning !!";
    cout << "Before swap()" << endl;
    cout << "s1: " << s1 <<endl;
    cout << "s2: " << s2 <<endl;
    s1.swap(s2);
    cout << "After swap()" << endl;
    cout << "s1: " << s1 <<endl;
    cout << "s2: " << s2 <<endl;

    //push_back()
    s1 = "123";
    cout << "s1: " << s1 <<endl;
    s1.pop_back();
    cout << "s1.pop_back() : " << s1 << endl;
    s1.push_back('8');
    cout << "s1.push_back('8') : "<< s1 << endl;

    cout << endl;
    cout << "*********************************************" << endl;
    cout << "String operations :" << endl;
    cout << "c_str, data, get_allocator, copy, find, rfind, find_first_of, find_last_of, find_first_not_of, find_last_not_of, substr, compare" << endl;
    cout << endl;

    s1 = "cpp string";
    //c_str() : c style string. Guaranteed string terminating character
    const char *char_ptr =  s1.c_str();
    cout << "s1: " << s1 <<endl;
    cout << "s1.c_str(): "<<char_ptr << endl;

    //data() : data buffer. No guarantee of string terminating character
    const char *char_buff =  s1.data();
    cout << "s1.data(): ";
    for(int i =0; i < s1.size(); i++)
        cout << char_buff[i];
    cout << endl;

    //copy() : Does not append a null character at the end of the copied content
    char dest_buff[20];
    s1 = "string to copy";
    s1.copy(dest_buff, s1.size(), 0);
    dest_buff[s1.size()] = '\0';
    cout << "s1.copy(): String copy suing s1.copy(): "<< dest_buff << endl;

    //find() : find first match of given word
    s1 = "There are two red balls and two white balls";
    cout << "s1: " << s1 <<endl;
    size_t pos = s1.find("two");
    cout << "s1.find(\"two\") : first key match at position : "<< pos << endl;

    //rfind() : find first match of given word
    pos = s1.rfind("two");
    cout << "s1.rfind(\"two\") : first key match in reverse search at position : "<< pos << endl;

    //find_first_of() : find any one of the character in the given key
    s1 = "string with some words";
    cout << "s1: " << s1 <<endl;
    cout << "s1.find_first_of(\"aeious\") : positions of alphabets in the given string: ";
    pos = s1.find_first_of("aeiou");
    while(pos != string :: npos)
    {
        cout << pos << " ";
        pos = s1.find_first_of("aeiou", pos + 1);
    }
    cout << endl;

    //substr()
    cout << "s1.substr(12, 10) : " << s1.substr(12, 10) << endl;

    //compare()
    s1 = "string"; s2 = "string";
    cout << "s1: " << s1 << "   s2: " << s2 <<endl;
    cout << "s1.compare(s2): zero => match, non-zero => mis-match : "<< s1.compare(s2) << endl;

    cout << endl;
    cout << "*********************************************" << endl;
    cout << "Non member functions :" << endl;

    cout << endl;
    cout <<  "Convert from strings : " << endl;
    cout << endl;

    cout << "stoi(\"2019\"): " << stoi("2019") << endl;
    cout << "stoi(\"FF\", nullptr, 16) : hex number string to int value: " << stoi("0xFF", nullptr, 16) << endl;
    cout << "stoi(\"1011\", nullptr, 2) : binary number string to int value: " << stoi("1011", nullptr, 2) << endl;
    cout << "stof(\"12.34\"): " << stof("12.34") << endl;

    cout << endl;
    cout <<  "Convert to strings: " << endl;
    cout << endl;

    cout << "to_string(1240u) : " << to_string(1240u) << endl;
    cout << "to_string(12.40f) : " << to_string(12.40f) << endl;

    cout << endl;
    cout << "*********************************************" << endl;
    cout << "Non member functions :" << endl;
    cout <<  "operator +, swap, <<, >>, getline " << endl;
    cout << endl;

    cout << "getline() usage : " << endl;
    cout << "Please enter your full name : ";
    getline(cin, s1);
    cout << "Hello : " << s1 << " !!"<<  endl;

    return 0;
}
