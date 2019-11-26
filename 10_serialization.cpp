/*
@author: Rajasekhar Mugada
@brief : Serialization : Writing and reading data into file using cpp stream.
    Example1:
    Serialize class data members for displaying on console

    Example2:
    -Create a log file if it was not existing and write some data and close the file
    -Open the existing log file and display the contents.

    Example 3:
    -Serialize class data members for displaying on console and writing on to file
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


/* Marks list class contains students marks for a subject */
class marks_list
{
private:
    int marks[100];
    int num_students;
public:
    marks_list()
    {
        for (int i = 0; i<100 ; i++)
        {
            marks[i] = 0;
        }
        num_students = 0;
    }
    ~marks_list(){};
    void add(int marks);
    int size() {return num_students;};
    int get_marks(int roll_num); //roll number can be 1 - 100
    friend ostream & operator << (ostream & out, marks_list list);
};

void marks_list :: add(int marks)
{
    if(num_students < 100 - 1)
    {
        this->marks[num_students] = marks;
        num_students++;
    }
}
int marks_list :: get_marks(int roll_num)
{
    if(roll_num <1 || roll_num > 100)
        return 0;

    return marks[roll_num - 1];
}

ostream & operator << (ostream & out, marks_list list)
{
    for (int i = 1; i < list.size() + 1; i++)
        out << list.get_marks(i) << ",";

    out << endl;
    return out;
}

/* File stream serialization */
class file_stream
{
public:
    void test_write(char * file_name);
    void test_write(char * file_name, marks_list list);
    void test_read(char * file_name);
};

void file_stream :: test_write(char * file_name)
{
    fstream my_file;
    my_file.open(file_name, ios::trunc | ios::out);
    if(my_file.is_open())
    {
        my_file << "hi" << endl;
        my_file << "1, 2, 4," << endl;
        my_file.close();
    }
}
/* write data to file from class object*/
void file_stream :: test_write(char * file_name, marks_list list)
{
    fstream my_file;
    my_file.open(file_name, ios::trunc | ios::out);
    if(my_file.is_open())
    {
        my_file << list;
        my_file.close();
    }
}

void file_stream :: test_read(char * file_name)
{
    string line;
    fstream my_file(file_name, ios::in);
    if(my_file.is_open())
    {
        while(getline(my_file, line))
        {
            cout << line << endl;
        }
        my_file.close();
    }
}


int main()
{
    /*
    Example1:
    Serialize class data members for displaying on console
    */
    cout << "Example 1: serialization of class members on console" << endl;
    marks_list maths_marks_list, eng_marks_list, *list;

    list = & maths_marks_list;
    list->add(10);
    list->add(88);
    list->add(100);
    list->add(35);
    cout << *list;

    list = & eng_marks_list;
    list->add(27);
    list->add(35);
    list->add(86);
    list->add(98);
    cout << *list;


    /*
    Example2:
    -Create a log file if it was not existing and write some data and close the file
    -Open the existing log file and display the contents.
    */
    cout << "Example 2: File stream example" << endl;
    file_stream fs;

    char * file_name = "fs_test.txt";
    fs.test_write(file_name);
    fs.test_read(file_name);


    /*
    Example 3:
    -Serialize class data members for displaying on console and writing on to file
    */
    cout << "Example 3: Serialization of class members on file and console " << endl;
    fs.test_write(file_name, maths_marks_list);
    fs.test_read(file_name);

    return 0;
}
