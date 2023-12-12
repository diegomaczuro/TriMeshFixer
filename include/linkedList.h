#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <algorithm>


class Node
{
public:
    
    void *node_data;
    // Empty constructor
    Node();
    // Isolated node
    Node(void *data);
    // Insert Node between nodes p and n
    Node(Node *p, void *data, Node *n);
    // Destroy a link to node
    ~Node();
    // Get data of node
    Node *get_prev(){return prev_node;}
    Node *get_next(){return next_node;}
    void *get_node_data(){return node_data;}

    Node *prev_node;
    Node *next_node;    
};

class DoubleLinkedList
{
public:
    Node *head;
    Node *tail;
    int length_of_list;

    // Constructor: head and tail is linked to NULL
    DoubleLinkedList();
    //add_front: Adds a new node in the beginning of list
    void addToFront(int new_node);
    //add_after: Adds a new node after another node
    void addAfterNode(Node *node, int new_data);
    //add_before: Adds a new node before another node
    //add_end: Adds a new node in the end of list
    //delete: Removes the node
    //forward_traverse: Traverse the list in forward direction
    //backward_traverse: Traverse the list in backward direction

};

#endif