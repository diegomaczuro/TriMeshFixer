#include <iostream>
#include <string.h>
#include <vector>


class Node
{
public:
    
    int node_data;

    ~Node();
    Node *prev_node;
    Node *next_node;    
};

class DoubleLinkedList
{
public:
    Node *head;
    Node *tail;

    // Constructor: head and tail is linked to NULL
    DoubleLinkedList();
    //add_front: Adds a new node in the beginning of list
    void addAtFront(int new_node);
    //add_after: Adds a new node after another node
    //add_before: Adds a new node before another node
    //add_end: Adds a new node in the end of list
    //delete: Removes the node
    //forward_traverse: Traverse the list in forward direction
    //backward_traverse: Traverse the list in backward direction

};