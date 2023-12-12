#ifndef EDGE_H
#define EDGE_H

//#include <vertex.h>
#include <triangle.h>

class Vertex;
class Triangle;

class Edge
{
public:
    Vertex *v1, *v2;
    Triangle *t1, *t2;

    Edge(Vertex *new_v1, Vertex *new_v2);

    ~Edge();
};

#endif