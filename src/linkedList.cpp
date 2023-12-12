#include <linkedList.h>

/*Node::Node()
{
    prev_node = NULL;
    next_node = NULL;
};

Node::Node(void *data)
{
    node_data = (void *)data;
    prev_node = NULL;
    next_node = NULL;
};

Node::Node(Node *p, void *data, Node *n)
{
    node_data = data;

    if (p != NULL) 
    {
        p->next_node = this;
        std::cout << p->next_node << std::endl;
    }
    if (n != NULL) n->prev_node = this;    
};*/

/*DoubleLinkedList::DoubleLinkedList()
{
    head = NULL;
    tail = NULL;
    length_of_list = 0;
};

void DoubleLinkedList::addToFront(void new_data)
{
    Node *temp_node = new Node();
    temp_node->node_data = new_data;
    temp_node->prev_node = NULL;
    temp_node->next_node = head;

    if (head == NULL)
        tail = temp_node;
    else
        head->prev_node = temp_node;

    head = temp_node;
};

void DoubleLinkedList::addAfterNode(Node *current_node, int new_data)
{
    Node *temp_node = new Node();
    temp_node->node_data = new_data;
    temp_node->prev_node = current_node;
    temp_node->next_node = current_node->next_node;
    //my addition
    if (current_node->next_node != NULL)
        current_node->next_node->prev_node = temp_node;

    current_node->next_node = temp_node;

    if (current_node->next_node == NULL)
        tail = temp_node;
};




/*

int main()
{   
    Node *node1 = new Node(0);
    Node *node2 = new Node(1);
    Node *node3 = new Node(NULL, 2, NULL);
    Node *node4 = new Node(node1, 2, NULL);
    Node *node5 = new Node(node4, 3, node2);
    

    std::list<Node *> linked_list = {node1};
    //addToFront
    linked_list.push_front(node2);
    linked_list.push_back(node3);
    //void addAfterNode(Node *node, int new_data);
    auto it = std::find(linked_list.begin(), linked_list.end(), node1);
    
    if (it != linked_list.end())
        linked_list.insert(it, node5);

    displayList(node1);

    std::list <int> example{3,1,4,6,8,9,11,20};
    auto it3 = example.begin();
    auto pv = std::prev(it3,5);

    std::cout << *it3 << std::endl;
    std::cout << *pv << std::endl;

    Vertex *v = new Vertex(0, 1, 0.5);
    auto [a,b,c] = v->getVertex();
    auto reverse = v->getReverseVertex();
    std::cout << a<<" "<<b<<" "<<c<< std::endl;
    std::cout << std::get<0>(reverse)<<" "<<std::get<1>(reverse)<<" "<<std::get<2>(reverse) << std::endl;
    
    std::cout << v->z << std::endl;

    Vertex *v1 = new Vertex(1,1,0);
    Vertex *v2 = new Vertex(0,1,1);
    Vertex *v3 = new Vertex(1,0,1);

    Edge *e1 = new Edge(v1, v2);
    Edge *e2 = new Edge(v2, v3);
    Edge *e3 = new Edge(v3, v1);

    /*DoubleLinkedList linked_list;
    linked_list.addToFront(10);
    linked_list.addToFront(100);

    linked_list.addAfterNode(50)*/
    //std::cout << "Start Linked List: " << std::endl;
/*

    return 0;
}*/

template<typename var>
Node<var>::Node() : data(-1), prev_node(NULL), next_node(NULL)
{
    
};

template <typename var>
Node<var>::Node(var new_data) : data(new_data), prev_node(NULL), next_node(NULL)
{       

};

template<typename var>
Node<var>::Node(Node *p, var new_data, Node *n) : data(new_data), prev_node(p), next_node(n)
{    
    if (prev_node != NULL) prev_node->next_node = this;   
    if (next_node != NULL) next_node->prev_node = this;
};

template<typename var>
Node<var>::~Node()
{
    if (prev_node != NULL) prev_node->next_node = next_node;
    if (next_node != NULL) next_node->prev_node = prev_node;
};

template<typename var>
var Node<var>::get_data()
{   
    return data;
};

template<typename var>
Node<var> * Node<var>::get_prev()
{
    return prev_node;
};

template<typename var>
Node<var> * Node<var>::get_next()
{
    return next_node;
};

template<typename var>
LinkedList<var>::LinkedList() : head(NULL), tail(NULL), length_of_list(0), list({})
{
    std::cout << "Make empty list, length_of_list=" <<length_of_list <<std::endl;
};

template<typename var>
LinkedList<var>::LinkedList(var data) : length_of_list(1), list({-1, data,-1})
{
    head = tail = new Node<var> (data);
    std::cout << "Make one-element list, length_of_list=" <<length_of_list<<std::endl;
};

template<typename var>
void LinkedList<var>::addToHead(var new_node)
{
    auto it = list.begin();
    ++it;
    list.insert(it, new_node); 
    ++length_of_list;   
};

template<typename var>
void LinkedList<var>::addToTail(var new_node)
{
    auto it = list.end();
    --it;
    list.insert(it, new_node); 
    ++length_of_list; 
};

template<typename var>
void LinkedList<var>::printList()
{
    std::cout << "len=" <<length_of_list<<std::endl;
    std::cout << "mylist contains:";
    for (auto it=list.begin(); it!=list.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
};


//Destructor
template<typename var>
LinkedList<var>::~LinkedList(){};

template class Node<int>;
template class Node<float>;
template class LinkedList<int>;
template class LinkedList<float>;