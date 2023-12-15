#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <algorithm>

#include <vertex.h>
#include <edge.h>
#include <linkedList.h>
#include <memory>

#include <cassert>

Vertex::Vertex(float new_x, float new_y, float new_z)
{
    x = new_x;
    y = new_y;
    z = new_z;
};

 
void Vertex::setVertexCoordinate(float new_x, float new_y, float new_z)
{
    x = new_x;
    y = new_y;
    z = new_z;
};

std::tuple<float, float, float> Vertex::getVertex()
{
    return std::make_tuple(x, y, z);
};

std::tuple<float, float, float>  Vertex::getReverseVertex()
{
    return std::make_tuple(-x, -y, -z);
};


template <typename T>
void displayList(Node<T> *node)
{
    Node<T> *last;
    if (node->prev_node==NULL) std::cout<<"NULL====>";

    while (node != NULL)
    {
        std::cout << node->get_data() << "===>" ;//<< std::endl;
        last = node;
        node = node->next_node;
    }

    if (node==NULL) std::cout<<"NULL"<< std::endl;
};

template<typename T>
void my_finction_for_ptr(std::shared_ptr<T> my_ptr)
{
    auto value = *my_ptr;
    std::cout << "my_finction_for_ptr: " <<my_ptr<<", value: "<<value <<  std::endl;
};

template<typename var>
bool myfunction (std::shared_ptr<var> i,std::shared_ptr<var> j) { return (*i<*j); }

int main()
{   
        
    Node<int> *node0 = new Node<int> (6);
    Node<int> *node1 = new Node<int> (7);
    Node<int> *node2 = new Node<int> (node0, 5, node1);
    Node<int> *node3 = new Node<int> (node1, 10, NULL);
    Node<int> *node4 = new Node<int> (node3, 11, NULL);

    displayList(node1->get_prev());
    
    std::cout<<"PREV: "<<node0->get_prev()<< std::endl;
    std::cout<<"NEXT: "<<node0->get_next()<< std::endl;
    std::cout<<"DATA: "<<node0->get_data()<< std::endl;

    Node<int> *node5 = new Node<int> (4);
    Node<int> *node6 = new Node<int> (9);
    std::list<Node<int>*> my_list = {};
    my_list.push_front(NULL);
    my_list.push_front(node5);
    my_list.push_back(node6);
    auto l_front = my_list.begin();
    //std::advance(l_front, 1);
    auto nx = std::next(l_front, 2);

    //std::cout << "l_front: " <<(*l_front)->get_data() <<std::endl; ->get_data()
    std::cout << "nx: " <<(*nx) <<std::endl;

    for (int i=0; i < 5; i++)
    {
        int *node_ptr = new int (i);
        std::shared_ptr<int> my_ptr = std::make_shared<int> (i);
        //std::cout << "node_ptr: " <<node_ptr<<", value: "<<*node_ptr <<  std::endl;
        std::cout << "node_ptr: " <<my_ptr<<", value: "<<*my_ptr <<  std::endl;
        my_finction_for_ptr(my_ptr);
    }

    
    


    
    //int node_1 = 1;
    //int *node_1_ptr = &node_1;
    //std::cout << "node_1: " <<*node_1_ptr <<  std::endl;

    std::shared_ptr<int> node_ptr1 = std::make_shared<int> (1);
    std::shared_ptr<int> node_ptr2 = std::make_shared<int> (10);
    std::shared_ptr<int> node_ptr3 = std::make_shared<int> (9);
    std::shared_ptr<int> node_ptr4 = std::make_shared<int> (14);
    std::shared_ptr<int> node_ptr5 = std::make_shared<int> (5);
    // List1
    LinkedList<int> *list2 = new LinkedList<int> (node_ptr1);
    list2->addToHead(node_ptr2);
    list2->addToHead(node_ptr3);
    list2->addToHead(node_ptr3);
    list2->addToHead(node_ptr4);
    //list2->printList();
    list2->addToTail(node_ptr5);
    list2->insertAfter(node_ptr3, 2);
    list2->printList();
    // List2
    LinkedList<int> list1(node_ptr5);
    //list1.printList();
    list1.insertAfter(node_ptr5, 2);
    list1.addToHead(node_ptr4);
    list1.addToHead(node_ptr3);
    //list1.insertAfter(node_ptr5, 3);
    //list1.insertAfter(node_ptr5, 5);
    //list1.insertAfter(node_ptr5, 6);
    //list2.printList();
    std::shared_ptr<int> new_ptr = std::make_shared<int> (-12);
    list1.printList();
    list1.getNodeByValue(node_ptr3);
    list1.replaceNode(node_ptr5, new_ptr);
    list1.addToHead(new_ptr);
    list1.printList();
    //list1.removeNodes();
    //list1.printList();
    list1.sort();
    list1.printList();



    //list1.getNodeByIndex(12);
    //list1.appendTailList(list2);
    //list1.printList();

    //list1.moveNodeToTail(node_ptr5, list2);
    //list1.moveNodeToTail(node_ptr4, list2);
    //list1.printList();
    //list2->printList();
    /*auto head = list1.get_head();
    auto tail = list1.get_tail();
    std::cout << "head: " <<*head << ", tail: " <<*tail  << std::endl;

    auto head2 = list2.get_head();
    auto tail2 = list2.get_tail();
    std::cout << "head: " <<*head2 << ", tail: " <<*tail2  << std::endl;

    auto prev = list2.prev_node(node_ptr2);
    std::cout << "prev_node: " <<*prev << std::endl;
    auto next = list2.next_node(node_ptr4);
    std::cout << "next_node: " <<*next << std::endl;*/
    //list1.removeNode(node_ptr5);
    //list1.printList();


    /*int *my_var;
    int value = 100;
    my_var = &value;
    auto my_var2 = my_var;
    std::cout << "Start Linked List: " <<my_var << std::endl;
    std::cout << "Start Linked List: " <<my_var2 << value << std::endl;
    value = 5;
    std::cout << "Start Linked List: " <<my_var2 << value << std::endl;*/

    


    /*setData(&node2);
    setData(node3);

    delete node3;
    std::cout << "Start Linked List: " << std::endl;

    float contain = -9;
    int contain2 = 7;
    setData2(&contain);
    setData2(&contain2);

    Node<int> *node0 = new Node<int> ();
    Node<int> *node1 = new Node<int> (12);


    std::list<Node<int> *> linked_list = {};
    linked_list.push_front(node0);
    linked_list.push_front(node1);
    linked_list.push_front(node0);

    auto it1 = linked_list.begin();
    //auto pv0 = std::next(it1, 2);
    auto cc = *(*it1)->data;
    //std::cout << cc << std::endl;
    //std::cout << *(*pv0)->data << std::endl;


    std::list <int> example{3,1,4,6,8,9,11,20};
    auto it3 = example.begin();
    auto pv = std::prev(it3,5);
    auto pv2 = std::next(it3,8);

    std::cout << *it3 << std::endl;
    std::cout << *pv << std::endl;
    std::cout << *pv2 << std::endl;*/


    return 0;
} 