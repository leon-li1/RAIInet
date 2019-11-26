#ifndef POINT_H
#define POINT_H

struct Point {
    int x;
    int y;
    bool operator==(const Point other) const;
};

#endif
