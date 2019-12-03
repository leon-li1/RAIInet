#include <iostream>
#include <string>
#include "strengthen.h"
#include "player.h"
#include "piece.h"
#include "invalidMove.h"

Strengthen::Strengthen(Player *owner, Player *other) : Ability{owner, other} {}

void Strengthen::use(std::istream &in)
{
    std::string pieceName;
    in >> pieceName;

    //if you don't own the piece
    if (owner->getPiece(pieceName) == nullptr)
        throw InvalidMove{"Can't strengthen someone else piece"};

    Piece *thePiece = owner->getPiece(pieceName);
    thePiece->setStrength(thePiece->getStrength() * 2);
}
