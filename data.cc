#include <string>
#include "data.h"
#include "invalidMove.h"

Data::Data(int speed, Point pos, Player *owner, int strength) : Piece{speed, pos, owner}, strength{strength} {}

void Data::notify(Piece &whoFrom)
{
    if (whoFrom.getPos() == getPos())
    {
        if (getOwner() == whoFrom.getOwner())
        { //Cannot move on top of your own piece
            throw InvalidMove{};
        }
        else
        {
            //Reveal info about each piece
            //Reveal this piece to other player
            whoFrom.getOwner()->addKnownPiece(owner->getPieceName(this), getInfo());
            //Reveal other player's piece to this player
            getOwner()->addKnownPiece(whoFrom.getOwner()->getPieceName(&whoFrom), whoFrom.getInfo());

            //Winner downloads the other player's link
            if (strength > other.strength)
            {
                getOwner()->download(&whoFrom);
            }
            else if (strength < other.strength)
            {
                whoFrom.getOwner()->download(*this);
            }
            else
            { //Tie, so player initiating wins
                whoFrom.getOwner()->download(*this);
            }
        }
    }
}

void Data::setStrength(int strength)
{
    this->strength = strength;
}

int Data::getStrength()
{
    return strength;
}

std::string Data::getInfo()
{
    return "D" + std::to_string(strength);
}
