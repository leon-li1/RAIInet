#include "virus.h"
#include "point.h"
#include "invalidMove.h"
#include "player.h"

Virus::Virus(int speed, Point pos, Player *owner, int strength) : Piece{pos, owner}, strength{strength}, speed{speed} {}

void Virus::notify(Subject &whoFrom)
{
    if (&whoFrom == this)
        return;
    if (whoFrom.getPos() == getPos())
    {
        if (getOwner() == whoFrom.getOwner())
        { //Cannot move on top of your own piece
            //std::cout << whoFrom.getInfo() << " trying to move on " << getInfo() << std::endl;
            throw InvalidMove{"Your trying to move on your own virus"};
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
                throw InvalidMove{"Stop notifying"}; // We need to stop notifying now that the piece is gone
            }
            else if (strength < whoFrom.getStrength())
            {
                whoFrom.getOwner()->download(this);
            }
            else
            { //Tie, so player initiating wins
                whoFrom.getOwner()->download(this);
            }
            //std::cout << "download by virus battle" << std::endl;
        }
    }
}

void Virus::setStrength(int strength)
{
    this->strength = strength;
}

int Virus::getStrength()
{
    return strength;
}

void Virus::setSpeed(int speed)
{
    this->speed = speed;
}

int Virus::getSpeed()
{
    return speed;
}

std::string Virus::getInfo()
{
    return "V" + std::to_string(strength);
}
