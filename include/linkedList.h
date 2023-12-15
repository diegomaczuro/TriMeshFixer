#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <algorithm>
#include <memory>
#include <cstdlib>

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
    std::shared_ptr<var> *head;
    std::shared_ptr<var> *tail;
    int length_of_list;
    std::list<std::shared_ptr<var>> list;

    // Constructor: head and tail is linked to NULL
    LinkedList();
    LinkedList(std::shared_ptr<var> data);

    ~LinkedList();
    //add_front: Adds a new node in the beginning of list
    std::shared_ptr<var> get_head(); // Works like O(1)
    std::shared_ptr<var> get_tail(); // Works like O(1)
    // Works not correct if list = {NULL, 14, 9, 2, 9, 10 NULL}, prev_node(9) -> 14    
    std::shared_ptr<var> prev_node(std::shared_ptr<var> node); // Works like O(length_of_list+1), rewrite like O(1)
    std::shared_ptr<var> next_node(std::shared_ptr<var> node);
   
    int lenList(){return length_of_list;}  // Works like O(1)
    void addToHead(std::shared_ptr<var> new_node);  // Works like O(1)
    void addToTail(std::shared_ptr<var> new_node);  // Works like O(1)
    void insertAfter(std::shared_ptr<var> node, var new_data);  // Works like O(length_of_list)

    int removeNode(int node_index); // Works like O(length_of_list) Try to use  list1.erase(it);
    int removeNode(std::shared_ptr<var> node); // Works like O(length_of_list)
    void appendHeadList(LinkedList *inserted_list); // Works like O(len(inserted_list))
    void appendTailList(LinkedList *inserted_list); // Works like O(len(inserted_list))
    void moveNodeToTail(std::shared_ptr<var> node, LinkedList *external_list); // Works like O(length_of_list)

    void popHead(); // Works like O(3)
    void popTail(); // Works like O(3)
    void printList();
    
    ////?????????????? freeNodes()
    std::shared_ptr<var> getNodeByValue(std::shared_ptr<var> value); // Works like O(length_of_list)
    std::shared_ptr<var> getNodeByIndex(int node_index); // Works like O(length_of_list)
    std::shared_ptr<var> replaceNode(std::shared_ptr<var> old_node, // Works like O(length_of_list)
                                     std::shared_ptr<var> new_node);
    void removeNodes(); // Works like O(length_of_list)
    int sort(); // Works like O(NlogN+2) 

    //forward_traverse: Traverse the list in forward direction
    //backward_traverse: Traverse the list in backward direction
//private:
    
};

#endif