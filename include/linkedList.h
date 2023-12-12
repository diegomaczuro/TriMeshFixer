#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <algorithm>

template <typename var>
class Node
{
public:
      
    Node();
    Node(var new_data);
    Node(Node *p, var new_data, Node *n);
    ~Node();

    var get_data();
    Node *get_prev();
    Node *get_next();    

public:
    var data; 
    Node *prev_node; 
    Node *next_node;
};

template <typename var>
class LinkedList
{
public:
    Node<var> *head;
    Node<var> *tail;
    int length_of_list;
    std::list<var> list;

    // Constructor: head and tail is linked to NULL
    LinkedList();
    LinkedList(var data);

    ~LinkedList();
    //add_front: Adds a new node in the beginning of list
    Node<var> *get_head();
    Node<var> *get_tail();

    int lenList(){return length_of_list;}

    void addToHead(var new_node);
    void addToTail(var new_node);
    void insertAfter(Node<var> node, var data);
    int removeNode(int i);
    int removeNode(Node<var> *node);
    Node<var> *getNode();

    void appendHeadList(LinkedList *list);
    void appendTailList(LinkedList *list);
    void moveNodeToTail(Node<var> node, LinkedList *list);

    void popTail();
    void popHead();
    ////?????????????? freeNodes()
    Node<var> getNodeByValue(var value);
    void removeNodes();

    void printList();





    //add_after: Adds a new node after another node
    //void addAfterNode(Node<var> *node, int new_data);
    //add_before: Adds a new node before another node
    //add_end: Adds a new node in the end of list
    //delete: Removes the node
    //forward_traverse: Traverse the list in forward direction
    //backward_traverse: Traverse the list in backward direction

};

#endif