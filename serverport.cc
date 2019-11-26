#include "serverport.h"
#include "piece.h"
#include "invalidMove.h"
#include "player.h"

Serverport::Serverport(Point pos, Player *owner) : Piece{pos, owner} {}

void Serverport::notify(Subject &whoFrom)
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
