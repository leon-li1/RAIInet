#include "serverport.h"
#include "piece.h"
#include "invalidMove.h"

Serverport::Serverport(Point pos, Player *owner, int speed) : Piece{speed, pos, owner} {}

void Serverport::notify(Piece &whoFrom)
{

    // if its your piece, invalid move
    if (getOwner() == whoFrom.getOwner())
    {
        throw InvalidMove{};
    }
    else // if not, download it to the piece's owner
    {
        whoFrom.getOwner()->download(this);
    }
}

std::string Serverport::getInfo()
{
    return "";
}
