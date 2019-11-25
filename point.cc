#include "point.h"

bool Point::operator==(Point &other)
{
    if (x == other.x && y == other.y)
        return true;
        
    return false;
}
