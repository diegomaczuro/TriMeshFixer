#include <linkedList.h>

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
LinkedList<var>::LinkedList() : head(NULL), tail(NULL), length_of_list(0)
{    
    this->list.push_front(nullptr);
    this->list.push_front(nullptr);
    //std::cout << "Make empty list, length_of_list=" <<length_of_list <<std::endl;
};

template<typename var>
LinkedList<var>::LinkedList(std::shared_ptr<var> data) : length_of_list(1)//, list({&-1, &data,&-1})
{    
    this->list.push_front(nullptr);
    this->list.push_front(data);
    this->list.push_front(nullptr);
    //std::cout << "Make one-element list, length_of_list=" <<length_of_list<<std::endl;
};

template<typename var>
void LinkedList<var>::addToHead(std::shared_ptr<var> new_node)
{
    auto it = list.begin();
    it++;
    list.insert(it, new_node); 
    length_of_list++;   
};

template<typename var>
void LinkedList<var>::addToTail(std::shared_ptr<var> new_node)
{
    auto it = list.end();
    it--;
    list.insert(it, new_node); 
    length_of_list++; 
};

template<typename var>
void LinkedList<var>::insertAfter(std::shared_ptr<var> node, var new_data)
{
    auto it = std::find(list.begin(), list.end(), node);    
    std::shared_ptr<var> temp_ptr = std::make_shared<var> (new_data);
    
    if (it != list.end()) 
    {
        it++;
        list.insert(it, temp_ptr);
        length_of_list++;
    }
    else LinkedList<var>::addToHead(temp_ptr);    
};

template<typename var>
void LinkedList<var>::printList()
{
    std::cout << "len=" <<length_of_list<<std::endl;
    std::cout << "mylist contains:";

    for (auto it=list.begin(); it!=list.end(); ++it)
        if (*it!= nullptr) std::cout << ' ' << **it;
    else std::cout << " NULL " ;
    std::cout << '\n';
};

template<typename var>
std::shared_ptr<var> LinkedList<var>::get_head()
{
    auto it = list.begin();
    
    if (length_of_list == 0) return nullptr;
    else
    {
        std::advance(it, 1);        
        return *it;
    }
};

template<typename var>
std::shared_ptr<var> LinkedList<var>::get_tail()
{
    auto it = list.end();
    if (length_of_list == 0) return nullptr;
    else
    {
        std::advance(it, -2);        
        return *it;
    }
};

template<typename var>
std::shared_ptr<var> LinkedList<var>::prev_node(std::shared_ptr<var> node)
{
    auto it = std::find(list.begin(), list.end(), node);  
    if (node != nullptr) 
    {
        std::advance(it, -1);        
        return *it;
    }      
    else return nullptr;
};

template<typename var>
std::shared_ptr<var> LinkedList<var>::next_node(std::shared_ptr<var> node)
{
    auto it = std::find(list.begin(), list.end(), node); 

    if (node != nullptr && it != list.end())
    {
        std::advance(it, 1);        
        return *it;
    }
    else return nullptr;  
};

template<typename var>
int LinkedList<var>::removeNode(int node_index)
{       
    int node_i = node_index;

    if (node_index < 0) 
        if (abs(node_index) > length_of_list) node_i = abs(node_index);
        else node_i = node_index+length_of_list;
     
    if (node_i + 1 <= length_of_list)
    {   
        auto it = list.begin();         
        int index_i = 0;        

        while(index_i < node_i)
        {            
            index_i++;
        }

        std::advance(it, index_i+1); 
        auto element_for_delete = *it;
        list.remove(element_for_delete); 
        length_of_list--;
        std::cout << "node_index it: " <<**it <<", index_i=" <<index_i<< std::endl;
        return index_i;
    }
    else return 0;
};

template<typename var>
int LinkedList<var>::removeNode(std::shared_ptr<var> node)
{
    auto it = list.begin(); 
    it++;
    int node_i = 0;

    while (*it != NULL && *it != node)
    {        
        node_i++;        
        it++;
    }
    
    if (*it != nullptr)
    {
        list.remove(node);
        length_of_list--;         
        return node_i;
    }
    return 0;
};

template<typename var>
void LinkedList<var>::popHead()
{   
    if (length_of_list != 0)
    {        
        list.pop_front();
        list.pop_front();
        list.push_front(nullptr);   
        length_of_list--;      
    }
};

template<typename var>
void LinkedList<var>::popTail()
{
    if (length_of_list != 0)
    {
        list.pop_back();
        list.pop_back();
        list.push_back(nullptr);   
        length_of_list--; 
    }
};

template<typename var>
void LinkedList<var>::appendHeadList(LinkedList *inserted_list)
{   
    auto it = inserted_list->list.begin();
    int len_of_inserted = inserted_list->length_of_list;
    auto current_it = list.begin();
    current_it++;

    if (len_of_inserted > 0)
    {   
        for (int i=0; i < len_of_inserted; i++)
        {
            it++;            
            list.insert(current_it, *it);
            length_of_list++; 
        }        
    }       
};

template<typename var>
void LinkedList<var>::appendTailList(LinkedList *inserted_list)
{
    auto it = inserted_list->list.begin();
    int len_of_inserted = inserted_list->length_of_list;
    auto current_it = list.end();
    current_it--;

    if (len_of_inserted > 0)
    {   
        for (int i=0; i < len_of_inserted; i++)
        {
            it++;            
            list.insert(current_it, *it);
            length_of_list++; 
        }        
    }     
};

template<typename var>
void LinkedList<var>::moveNodeToTail(std::shared_ptr<var> node, LinkedList *external_list)
{
    LinkedList<var>::removeNode(node);
    external_list->addToTail(node);
};

template<typename var>
std::shared_ptr<var> LinkedList<var>::getNodeByValue(std::shared_ptr<var> value)
{    
    auto it = list.begin();
    it++;
    int counter = 0;

    if (*it != NULL) 
    {   
        while ((counter < length_of_list) && (**it != *value))    
        {            
            it++;
            counter++;
        }        
        return *it;        
    }
    else 
        return NULL;
};

template<typename var>
std::shared_ptr<var> LinkedList<var>::getNodeByIndex(int node_index)
{
    if (length_of_list == 0 || node_index+1 > length_of_list) 
        return nullptr;
    else 
    {
        auto it = list.begin();
        it++;
        int counter = 0;
        int node_i = node_index;

        if (node_index < 0) 
            if (abs(node_index) > length_of_list) node_i = abs(node_index);
            else node_i = node_index+length_of_list;        

        if (node_i < length_of_list)
        {
            while (counter < node_i)
            {                   
                counter++;
                it++;
            }
            
            return *it;
        }
        else
            return nullptr;
    }
};

template<typename var>
std::shared_ptr<var> LinkedList<var>::replaceNode(std::shared_ptr<var> old_node, 
                                                  std::shared_ptr<var> new_node)
{    
    if (old_node != nullptr && new_node != nullptr)
    {
        std::replace(list.begin(), list.end(), old_node, new_node);
    }
    return new_node;
};

template<typename var>
void LinkedList<var>::removeNodes()
{
    if (length_of_list != 0)
    {
        length_of_list = 0;
        list.clear();
        list.push_front(nullptr);
        list.push_front(nullptr);
    }
};


template<typename var>
bool sort_function (std::shared_ptr<var> i,std::shared_ptr<var> j) { return (*i<*j); }

template<typename var>
int LinkedList<var>::sort()
{      
    if (length_of_list == 0) return 1;
    else
        list.pop_front();
        list.pop_back();
        list.sort(sort_function<var>);
        list.push_front(nullptr);
        list.push_back(nullptr);      
        return 0; 
};
//Destructor
template<typename var>
LinkedList<var>::~LinkedList(){};

template class Node<int>;
template class Node<float>;
template class LinkedList<int>;
template class LinkedList<float>;
template class LinkedList<std::shared_ptr<int>>;
template class LinkedList<std::shared_ptr<float>>;