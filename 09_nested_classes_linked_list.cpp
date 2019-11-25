/*
@author: Rajasekhar Mugada
@brief : Nested class explanation using linked list example.
    Linked list contains chain of nodes, with data and next node address.
*/

#include <iostream>
using namespace std;


/* Forward linked list */
/* Enclosing class : linked list */
class linked_list
{
private:
    /* nested class: Node */
    class node_class
    {
        public:

        int data;
        node_class * next;

        node_class(int val = 0)
        {
            data = val;
        }
        ~node_class(){} ;
    };

private:
    /* head node, last node pointer */
    node_class * head_node, * node;
    int num_nodes;

public:
    linked_list();
    ~linked_list();

    /* Append an element from the back */
    void push_back(int val);
    /* Remove an element from the back */
    void pop_back();
    /* Insert the given element at the given location */
    void insert(int val, int node_index);    //node_index : 0 to (total no. of nodes -1)
    /* Query list size */
    int size() {return num_nodes;}
    /* Query list empty status */
    bool empty(){return (num_nodes == 0) ? true : false;}
    /* Get the element from the given position in the list */
    int get_value(int node_index)  //node_index : 0 to (total no. of nodes -1)
    {
        node_class * node_ptr = get_node(node_index);
        return node_ptr->data;
    }

    /* Insertion operator overloading to display list elements */
friend ostream & operator << (ostream & out, linked_list & list);

private:
    /* Get node address from the given index */
    node_class * get_node(int node_index)  //node_index : 0 to (total no. of nodes -1)
    {
        node_class * node_ptr = head_node;
        int node_id = 0;
        //Traverse through all the nodes starting from base node
        while(node_id != node_index)
        {
            node_ptr = node_ptr->next;
            node_id++;
        }
        return node_ptr;
    }
};
/* Class constructor */
linked_list :: linked_list()
{
    num_nodes = 0;
    head_node = node = NULL;
}
/* Class destructor */
linked_list :: ~linked_list()
{
    // deallocate memory of all the members of linked list
    while(num_nodes > 0)
    {
        pop_back();
    }
}

void linked_list :: push_back(int val)
{
    //create new node with the given info.
    node_class * new_node = new node_class(val);
    num_nodes++;

    if(num_nodes == 1)
    {
        //update head / anchor node
        head_node = node = new_node;
    }
    else
    {
        //link to previous node
        node->next = new_node;
        //point to new node
        node = new_node;
    }
}
void linked_list :: pop_back()
{
    if(num_nodes > 0)
    {
        num_nodes --;
        //delete allotted memory for that node //heap memory
        delete node;
        //update last node
        if(num_nodes == 0)
        {
            head_node = node = NULL;
        }
        else
        {
            node = get_node(num_nodes -1);  //node_index : 0 to (total no. of nodes -1)
        }
    }
}

void linked_list :: insert(int val, int node_index)
{
    //boundary conditions
    if(node_index > num_nodes)
    {
        node_index = num_nodes;
    }
    if(node_index < 0)
    {
       node_index = 0;
    }

    //insert after all the elements or insert in a empty list
    if(node_index == num_nodes || num_nodes == 0)
    {
        push_back(val);
    }
    //insert at the beginning
    else if(node_index == 0)
    {
        //update next node
        node_class * new_node = new node_class(val);
        new_node->next = get_node(node_index);
        //update previous node
        head_node = new_node;

        num_nodes++;
    }
    else
    {
        //update next node
        node_class * new_node = new node_class(val);
        new_node->next = get_node(node_index);
        //update previous node
        node_class * node_ptr;
        node_ptr = get_node(node_index -1);
        node_ptr->next = new_node;

        num_nodes++;
    }
}

ostream & operator << (ostream & out, linked_list & list)
{
    if (list.size() == 0)
        return out << "empty list";

    for (int i = 0; i < list.size(); i++)
    {
        out << list.get_value(i) << endl;
    }

    return out;
}


int main()
{
    linked_list list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.insert(0, 0);
    list.pop_back();

    cout << list;

    return 0;
}
