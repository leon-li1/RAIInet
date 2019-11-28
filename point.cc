#include "point.h"

bool Point::operator==(const Point other) const
{
    if (x == other.x && y == other.y)
        return true;
        
    return false;
}

bool Point::operator != (const Point other) const
{
    return !(this == other);
}

istream& operator>>(istream &in, Point &p){
    in >> p.x;
    in >> p.y;
    return in;
}
