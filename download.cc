#include "download.h"
#include "player.h"
#include "invalidMove.h"
#include "piece.h"
#include <string>

Download::Download(Player *owner, Player *other) : Ability{owner, other} {}

void Download::use(std::istream &in) {
    std::string pieceName;
    in >> pieceName;

    Piece *thePiece = (owner->getPiece(pieceName)? owner->getPiece(pieceName): other->getPiece(pieceName)); 

    if (owner->owns(thePiece)) 
        throw InvalidMove{"You can't download your own piece"};
    else {
        if (thePiece) {
            owner->addKnownPiece(thePiece->getOwner()->getPieceName(thePiece), thePiece->getInfo());
            owner->download(thePiece);
        }
        else
            throw InvalidMove{"the piece has already been downloaded"};
    }
}
