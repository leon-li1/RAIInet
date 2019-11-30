#include <vector>
#include <string>
#include "firewallAbility.h"
#include "point.h"
#include "player.h"
#include "firewall.h"

FirewallAbility::FirewallAbility(Player *owner, Player *other) : Ability{owner, other} {}

void FirewallAbility::use(std::istream &in)
{
    Point p;
    in >> p;
    std::vector<Player *> players{owner, other};
    owner->addPiece("firewall", new Firewall{p, owner}, players);
}
