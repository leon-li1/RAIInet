#include "strengthen.h"
#include "player.h"

Strengthen::Strengthen(Player *owner, Player *other) : Ability{owner, other} {}

void Strengthen::use(istream &in) {
    std::string name;
    int stren;
    in >> name >> stren;
    
    Piece* p = owner->getPiece(name);
    piece->setStrength(stren);

}
