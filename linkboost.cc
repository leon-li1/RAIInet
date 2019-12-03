#include "linkboost.h"
#include "player.h"
#include "piece.h"
#include "invalidMove.h"
#include <string>

Linkboost::Linkboost(Player *owner, Player *other) : Ability{owner, other} {}

void Linkboost::use(std::istream &in)
{
    std::string pieceName;
    in >> pieceName;

    //if you don't own the piece
    if (owner->getPiece(pieceName) == nullptr)
        throw InvalidMove{"Can't boost someone else piece stooooooooooooopid"};

    Piece *thePiece = owner->getPiece(pieceName);
    thePiece->setSpeed(thePiece->getSpeed() + 1);
}
