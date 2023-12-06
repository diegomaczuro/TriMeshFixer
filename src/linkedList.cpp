#include <linkedList.h>

Node::Node()
{
    prev_node = NULL;
    next_node = NULL;
};

Node::Node(int data)
{
    node_data = data;
    prev_node = NULL;
    next_node = NULL;
};

Node::Node(Node *p, int data, Node *n)
{
    node_data = data;

    if (p != NULL) 
    {
        p->next_node = this;
        std::cout << p->next_node << std::endl;
    }
    if (n != NULL) n->prev_node = this;    
};

DoubleLinkedList::DoubleLinkedList()
{
    head = NULL;
    tail = NULL;
    length_of_list = 0;
};

void DoubleLinkedList::addToFront(int new_data)
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


int main()
{   
    Node *node1 = new Node(0);
    Node *node2 = new Node(1);
    Node *node3 = new Node(NULL, 2, NULL);
    Node *node4 = new Node(node1, 2, NULL);
    Node *node5 = new Node(node4, 3, node2);
    /*DoubleLinkedList linked_list;
    linked_list.addToFront(10);
    linked_list.addToFront(100);

    linked_list.addAfterNode(50)*/
    std::cout << "Start Linked List: " << std::endl;


    return 0;
}