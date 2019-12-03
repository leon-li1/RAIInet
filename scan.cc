#include <iostream>
#include <string>
#include "scan.h"
#include "player.h"

Scan::Scan(Player *owner, Player *other) : Ability{owner, other} {}

void Scan::use(std::istream &in)
{

    std::string pieceName;
    in >> pieceName;

    if (owner->getPiece(pieceName) == nullptr)
    { //other owns piece
        owner->addKnownPiece(pieceName, other->getPieceInfo(pieceName));
    }
    else
    { //owner owns piece
        other->addKnownPiece(pieceName, owner->getPieceInfo(pieceName));
    }
}
