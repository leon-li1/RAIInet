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
    virtual void setPos(Point newPos) = 0;
    virtual Point getPos() = 0;
    virtual std::string getType() = 0;
    Player *getOwner();
};

#endif
