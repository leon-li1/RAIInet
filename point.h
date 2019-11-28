#ifndef POINT_H
#define POINT_H

#include <iostream>

struct Point {
    int x;
    int y;
    
    bool operator==(const Point other) const;
    bool operator!=(const Point other) const;
    friend std::istream &operator>>(std::istream &in, Point &p);
};

std::istream &operator>>(std::istream &in, Point &p);
#endif
