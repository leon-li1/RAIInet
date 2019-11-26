#ifndef PIECE_H
#define PIECE_H
#include "observer.h"
#include "subject .h"
#include "point.h"
#include <utility>

class Player;
class InvalidMove;

class Piece : public Observer, public Subject
{
    Point pos;
    Player *owner;

public:
    Piece(Point pos, Player *owner);
    void setPos(Point newPos);
    Point getPos();
    Player *getOwner();
    virtual int getSpeed();
    virtual int getStrength();
    virtual void setSpeed(int speed);
    virtual void setStrength(int strength);
};

#endif
