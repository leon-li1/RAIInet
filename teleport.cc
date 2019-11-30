#include "teleport.h"
#include "player.h"
#include "point.h"
#include <string>

Teleport::Teleport(Player *owner, Player *other) : Ability{owner, other} {}

void Teleport::use(istream &in) {
    std::string pieceName;
    Point pos;
    in >> pieceName >> pos;    

    if (owner->owns(getPiece(pieceName))) {
        thePiece->setPos(newPos);
        thePiece->notify(*thePiece);
    }
}
