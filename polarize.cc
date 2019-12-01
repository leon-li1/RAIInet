#include <string>
#include <iostream>
#include "polarize.h"
#include "player.h"
#include "point.h"
#include "piece.h"
#include "data.h"
#include "virus.h"

Polarize::Polarize(Player *owner, Player *other) : Ability{owner, other} {}

void Polarize::use(std::istream &in)
{
    std::string pieceName;
    in >> pieceName;
    Piece *thePiece;
    if (owner->getPiece(pieceName)) {
        thePiece = owner->getPiece(pieceName);
    } else {
        thePiece = other->getPiece(pieceName);
    }
    
    int speed = thePiece->getSpeed();
    Point pos = thePiece->getPos();
    Player *playerOwner = thePiece->getOwner();
    int strength = thePiece->getStrength();
    std::string type = thePiece->getInfo();

    std::vector<Player *> ps{owner, other};


    playerOwner->removePiece(thePiece, ps);
    if (type[0] == 'V')
        playerOwner->addPiece(pieceName, new Data{speed, pos, playerOwner, strength}, ps);
    else //piece is data
        playerOwner->addPiece(pieceName, new Virus{speed, pos, playerOwner, strength}, ps);

}
