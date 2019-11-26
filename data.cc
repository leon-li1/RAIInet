#include <string>
#include "data.h"
#include "invalidMove.h"
#include "player.h"

Data::Data(int speed, Point pos, Player *owner, int strength) : Piece{pos, owner}, strength{strength}, speed{speed} {}

void Data::notify(Subject &whoFrom)
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
            whoFrom.getOwner()->addKnownPiece(getOwner()->getPieceName(this), getInfo());
            //Reveal other player's piece to this player
            getOwner()->addKnownPiece(whoFrom.getOwner()->getPieceName((Piece *)&whoFrom), whoFrom.getInfo());

            //Winner downloads the other player's link
            if (strength > whoFrom.getStrength())
            {
                getOwner()->download((Piece *)&whoFrom);
            }
            else if (strength < whoFrom.getStrength())
            {
                whoFrom.getOwner()->download(this);
            }
            else
            { //Tie, so player initiating wins
                whoFrom.getOwner()->download(this);
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

void Data::setSpeed(int speed)
{
    this->speed = speed;
}

int Data::getSpeed()
{
    return speed;
}

std::string Data::getInfo()
{
    return "D" + std::to_string(strength);
}
