#include <iostream>
#include <string>
#include "teleport.h"
#include "player.h"
#include "point.h"
#include "invalidMove.h"
#include "piece.h"

Teleport::Teleport(Player *owner, Player *other) : Ability{owner, other} {}

void Teleport::use(std::istream &in) {
    std::string pieceName;
    Point pos;
    in >> pieceName >> pos;    

    if (owner->getPiece(pieceName)) {
        owner->getPiece(pieceName)->setPos(pos);
    } else {
        throw InvalidMove{"You must teleport a piece you own."};
    }
}
