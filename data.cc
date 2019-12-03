#include <string>
#include "data.h"
#include "invalidMove.h"
#include "stopNotifying.h"
#include "player.h"
#include "point.h"

Data::Data(int speed, Point pos, Player *owner, int strength) : Piece{pos, owner}, strength{strength}, speed{speed} {}

void Data::notify(Subject &whoFrom)
{
    if (&whoFrom == this)
        return;
    //std::cout << getInfo() << " notified in data" << std::endl;
    if (whoFrom.getPos() == getPos())
    {
        if (getOwner() == whoFrom.getOwner())
        { //Cannot move on top of your own piece
            throw InvalidMove{"Your trying to move on your own link"};
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
                throw StopNotifying{}; // We need to stop notifying now that the piece is gone
            }
            else if (strength < whoFrom.getStrength())
            {
                whoFrom.getOwner()->download(this);
            }
            else
            { //Tie, so player initiating wins
                whoFrom.getOwner()->download(this);
            }
            //std::cout << "download by data battle" << std::endl;
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
