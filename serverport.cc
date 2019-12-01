#include "serverport.h"
#include "piece.h"
#include "invalidMove.h"
#include "player.h"

Serverport::Serverport(Point pos, Player *owner) : Piece{pos, owner} {}

void Serverport::notify(Subject &whoFrom)
{
    // if its your piece, invalid move
    if (getPos() == whoFrom.getPos()) {
        if (getOwner() == whoFrom.getOwner())
        {
            throw InvalidMove{"You can't download your own piece on your serverport"};
        }
        else // if not, download it to the piece's owner
        {
            getOwner()->download((Piece *)&whoFrom);
            throw InvalidMove{"Stop notifying"}; // We need to stop notifying now that the piece is gone
            //std::cout << "download by server port" << std::endl;
        }
    }
}

std::string Serverport::getInfo()
{
    return "";
}
