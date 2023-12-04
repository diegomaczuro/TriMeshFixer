#include <linkedList.h>

DoubleLinkedList::DoubleLinkedList()
{
    head = NULL;
    tail = NULL;
};

void DoubleLinkedList::addAtFront(int new_data)
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


int main()
{   
   
    DoubleLinkedList linked_list;
    linked_list.addAtFront(10);
    std::cout << "Start Linked List: " << std::endl;


    return 0;
}