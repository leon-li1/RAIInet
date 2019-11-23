#ifndef LINK_H
#define LINK_H
#include "piece.h"

enum class Direction;

class Link : public Piece
{
    int strength;
    int speed;

public:
    virtual void notify(Subject &whoFrom) = 0;
    virtual void move(Direction direction) = 0;
    virtual void setSpeed(int speed) = 0;
};

#endif
