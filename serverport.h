#ifndef SERVERPORT_H
#define SERVERPORT_H
#include "piece.h"

class Serverport : public Piece
{
public:
    Serverport(Point pos, Player *owner, int speed);
    void notify(Piece &whoFrom) override;
};

#endif
