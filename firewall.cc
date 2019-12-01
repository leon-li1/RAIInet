#include <string>
#include "firewall.h"
#include "invalidMove.h"
#include "player.h"

Firewall::Firewall(Point pos, Player *owner) : Piece(pos, owner) {}

void Firewall::notify(Subject &whoFrom)
{
    if (whoFrom.getPos() == getPos())
    {
        if (whoFrom.getOwner() != getOwner())
        {
            std::string info = whoFrom.getInfo();
            getOwner()->addKnownPiece(whoFrom.getOwner()->getPieceName((Piece *) &whoFrom), info);

            if (info.length() > 0 && info[0] == 'V') {
                whoFrom.getOwner()->download((Piece *)&whoFrom);
                throw InvalidMove{"Stop notifying"}; // We need to stop notifying now that the piece is gone
            }
        }
    }
}

std::string Firewall::getInfo()
{
    return "";
}
