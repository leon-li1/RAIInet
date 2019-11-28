#ifndef POINT_H
#define POINT_H

#include <iostream>

struct Point {
    int x;
    int y;
    
    bool operator==(const Point other) const;
    bool operator!=(const Point other) const;

    istream& operator>>(istream &in, Point &p);
    
};

#endif
