#ifndef BOARD_H
#define BOARD_H

#include "point.h"

class Board
{
public:
    //usage: Board::isInside({0, 3})
    static bool isInside(Point);
};

#endif
