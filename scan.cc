#include "scan.h"
#include "player.h"
#include <string>

Scan::Scan(Player *owner, Player *other) : Ability{owner, other} {}

void Scan::use(istream &in) {

    int playerThatIsScanned = 2;
    std::string pieceName;
    in >> pieceName;

    if (pieceName[0] > 'a')
        playerThatIsScanned = 1;
    
    if (owner->getEdge().dir == Direction::Down) { //owner is p1
        if (playerThatIsScanned == 2) 
            owner->addKnownPiece(pieceName, other->getPieceInfo(pieceName));
    }    else { //owner is p2
        if (playerThatIsScanned == 2) 
            owner->addKnownPiece(pieceName, other->getPieceInfo(pieceName));
    }
}
