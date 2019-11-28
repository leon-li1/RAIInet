#include "steal.h"
#include "player.h"

Steal::Steal(Player *owner, Player *other) : Ability{owner, other} {}

void Steal::use(istream &in) {}
