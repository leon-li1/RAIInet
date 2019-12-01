#ifndef EDGE_H
#define EDGE_H

#include "point.h"
#include "direction.h"

class Edge
{
    Direction dir;

    public:
    Edge(Direction);
    ~Edge();
    bool isPassed(Point);
    Direction getDir();
};

#endif
