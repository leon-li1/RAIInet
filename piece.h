#ifndef PIECE_H
#define PIECE_H
#include "observer.h"
#include "subject .h"
#include <utility>

class Player;

class Piece : public Observer, public Subject
{
    std::pair<int, int> pos;
    Player *owner;

public:
    virtual void setPos(std::pair<int, int> newPos) = 0;
    virtual std::pair<int, int> getPos() = 0;
};

#endif
