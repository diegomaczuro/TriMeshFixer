#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <tuple>

#include <triangle.h>
#include <linkedList.h>

class Edge;
class DoubleLinkedList;

class Vertex
{
public:
    float x, y, z;
    Edge *e;
    //DoubleLinkedList *my_list;

    Vertex(float new_x, float new_y, float new_z);
    ~Vertex();
    void setVertexCoordinate(float new_x, float new_y, float new_z);
    std::tuple<float, float, float> getVertex();
    std::tuple<float, float, float>  getReverseVertex();
};

#endif