#ifndef EDGE_H
#define EDGE_H

#include "point.h"
#include "player.h"

class Edge
{
    Direction dir;

    public:
    Edge(Direction);
    ~Edge();
    bool isPassed(Point);
};

#endif
