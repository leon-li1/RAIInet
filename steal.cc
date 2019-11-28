#include "steal.h"
#include "player.h"

Steal::Steal(Player *owner, Player *other) : Ability{owner, other} {}

void Steal::use(istream &in) {

    int myViruses = owner->getVirusCount();
    int otherData = other->getDataCount();
    
    if (otherData > 0 &&  myViruses > 0) {
        owner->setVirusCount(myViruses - 1);
        other->setDataCount(otherData - 1);
        other->setVirusCount(other->getvirusCount() + 1);
        owner->setDataCount(owner->getDataCount() + 1);
    }
}
