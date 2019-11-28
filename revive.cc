#include "revive.h"
#include "player.h"

Revive::Revive(Player *owner, Player *other) : Ability{owner, other} {}

void Revive::use(istream &in) {}
