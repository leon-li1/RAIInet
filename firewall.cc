#include "firewall.h"
#indluve "invalidMove.h"

Firewall::Firewall(Point pos, Player* owner) : Piece(pos, owner) {}

void Firewall::notify(Piece &whoFrom){
    if(whoFrom.getPos() == this->pos){
        if(whoFrom.getOwner() != this->owner){
            throw InvalidMove;
        }
    }
}