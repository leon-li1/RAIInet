#ifndef EDGE_H
#define EDGE_H

#include "point.h"
#include "player.h"


class Edge{
    Point p1;
    Point p2;
    Direction dir;

    Public:
        Edge(Point, Point, Point);
        ~Edge();
        bool isPassed(Point);
}

#endif