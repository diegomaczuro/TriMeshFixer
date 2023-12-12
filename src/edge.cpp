#include <edge.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <tuple>
#include <vertex.h>

Edge::Edge(Vertex *new_v1, Vertex *new_v2)
{
    v1 = new_v1;
    v2 = new_v2;
    t1 = NULL;
    t2 = NULL;
    //std::cout << "v1: (" << v1->x<<","<< v1->y<<","<< v1->z<<") ";
    //std::cout << "v2: (" << v2->x<<","<< v2->y<<","<< v2->z<<")"<<std::endl;
};

Edge::~Edge()
{
    //delete this->v1;
    //delete v2;
    //delete t1;
    //delete t2;
};