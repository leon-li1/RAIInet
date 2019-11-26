#include "point.h"

bool Point::operator==(const Point other) const
{
    if (x == other.x && y == other.y)
        return true;
        
    return false;
}
