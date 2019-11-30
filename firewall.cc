#include "firewall.h"
#include "invalidMove.h"

Firewall::Firewall(Point pos, Player *owner) : Piece(pos, owner) {}

void Firewall::notify(Subject &whoFrom)
{
    if (whoFrom.getPos() == this->pos)
    {
        if (whoFrom.getOwner() != this->owner)
        {
            std::string info = whoFrom.getInfo();
            owner->addKnownPiece(whoFrom.getOwner->getPieceName((Piece *) &whoFrom), info);

            if (info.length() > 0 && info[0] == 'V'){
                owner->download((Piece *)&whoFrom);
            }
        }
    }
}

std::string Firewall::getInfo()
{
    return "";
}
