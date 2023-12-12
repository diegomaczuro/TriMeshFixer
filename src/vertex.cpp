#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <algorithm>

#include <vertex.h>
#include <edge.h>
#include <linkedList.h>

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

    std::list<int> my_list2 = {-1};
    auto l_front2 = my_list2.begin();
    std::cout << "l_front2: " <<*l_front2 <<std::endl;
    std::cout << "size: " <<my_list2.size() <<std::endl;
    //my_list2.

    LinkedList<int> list1;
    LinkedList<int> list2(3);
    list2.addToHead(1);
    list2.addToHead(10);
    list2.addToHead(9);
    list2.addToTail(14);
    list2.printList();

    


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