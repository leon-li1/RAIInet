#include "polarize.h"
#include "player.h"
#include "point.h"
#include <string>

Polarize::Polarize(Player *owner, Player *other) : Ability{owner, other} {}

void Polarize::use(istream &in)
{
    std::string pieceName;
    in >> pieceName;

    Piece *thePiece = gePiece(pieceName);
    int speed = thePiece->getSpeed();
    Point pos = thePiece->getPos();
    Player *playerOwner = thePiece->getOwner();
    int strength = thePiece.getStrength();
    string info type = thePiece.getInfo();

    if (owner->owns(thePiece)) {
        owner->removePiece(thePiece);
        if (type[0] == 'V')
            owner->addPiece(new Data{speed, pos, playerOwner, strength});
        else //piece is data
            owner->addPiece(new Virus{speed, pos, playerOwner, strength})
    }
}
