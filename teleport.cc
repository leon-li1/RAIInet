#include <iostream>
#include <string>
#include "teleport.h"
#include "player.h"
#include "point.h"
#include "invalidMove.h"
#include "piece.h"

Teleport::Teleport(Player *owner, Player *other) : Ability{owner, other} {}

void Teleport::use(std::istream &in)
{
    std::string pieceName;
    Point pos;
    in >> pieceName >> pos;

    if (owner->getPiece(pieceName) && pieceName[0] != 'S' && pieceName[0] != 'M' && pieceName[0] != 'W')
    {
        owner->getPiece(pieceName)->setPos(pos);
    }
    else
    {
        throw InvalidMove{"You must teleport a link you own."};
    }
}
