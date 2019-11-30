#include "firewall.h"
#include "invalidMove.h"

Firewall::Firewall(Point pos, Player *owner) : Piece(pos, owner) {}

void Firewall::notify(Subject &whoFrom)
{
    if (whoFrom.getPos() == this->pos)
    {
        if (whoFrom.getOwner() != this->owner)
        {
            throw InvalidMove{"Cannot move ontop of oponent's Firewall"};
        }
    }
}

std::string Firewall::getInfo()
{
    return "";
}
