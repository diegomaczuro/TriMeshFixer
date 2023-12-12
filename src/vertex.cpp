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


/*void displayList(Node *node)
{
    Node *last;
    if (node->prev_node==NULL) std::cout<<"NULL====>";

    while (node != NULL)
    {
        std::cout <<(void *) node->get_node_data() << "===>" ;//<< std::endl;
        last = node;
        node = node->next_node;
    }

    if (node==NULL) std::cout<<"NULL"<< std::endl;;
};*/

template <typename var>
class ListNode
{
public:
    var *data;

    ListNode()
    {        
        data = NULL;
        prev = NULL;
        next = NULL;
    };

    ListNode(var new_data)
    {
        data = &new_data;
        std::cout << "data: "<< *data << std::endl;
        prev = NULL;
        next = NULL;
    };

    ListNode *prev, *next;
};

template <typename T>
void setData(ListNode<T> *value)
{   
    std::cout << "Value: "<< *value->data << std::endl;
   
};

template <typename T>
void setData2(T *value)
{   
    auto result = value;
    std::cout << "Value: "<< *result<< std::endl;
   
};

int main()
{   
    int data = 2;
    int *data2 = &data;

    std::cout << "data: " <<data<< std::endl;
    std::cout << "data: " <<data2<< std::endl;
    std::cout << "data2: " <<*data2<< std::endl;
    
    float a = 10;
    ListNode<float> node2(10);
    ListNode<int> *node3 = new ListNode<int> (5);

    setData(&node2);
    setData(node3);

    delete node3;
    std::cout << "Start Linked List: " << std::endl;

    float contain = -9;
    int contain2 = 7;
    setData2(&contain);
    setData2(&contain2);

    ListNode<int> *node0 = new ListNode<int> ();
    ListNode<int> *node1 = new ListNode<int> (12);


    std::list<ListNode<int> *> linked_list = {};
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
    std::cout << *pv2 << std::endl;


    return 0;
} 