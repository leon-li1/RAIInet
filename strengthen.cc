#include "strengthen.h"
#include "player.h"
#include "piece.h"
#include "invalidMove.h"
#include <string>

Strengthen::Strengthen(Player *owner, Player *other) : Ability{owner, other} {}

void Strengthen::use(istream &in) {
    std::string pieceName;
    in >> pieceName;
    
    //if you don't own the piece
    if (owner->getPiece(pieceName) == nullptr)
        throw InvalidMove{"Can't strengthen someone else piece"};

    Piece *thePiece = owner->getPiece(pieceName);
    thePiece->setStrength(thePiece->getStrength() * 2);
}
