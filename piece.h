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
    int speed;
    Point pos;
    Player *owner;

public:
    void setPos(Point newPos);
    Point getPos();
    Player *getOwner();
    int getSpeed();
    void setSpeed(int speed);
};

#endif
