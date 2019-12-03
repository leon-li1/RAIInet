#include <vector>
#include <string>
#include "firewallAbility.h"
#include "point.h"
#include "player.h"
#include "firewall.h"
#include "direction.h"

FirewallAbility::FirewallAbility(Player *owner, Player *other) : Ability{owner, other} {}

void FirewallAbility::use(std::istream &in)
{
    Point p;
    in >> p;
    std::vector<Player *> players{owner, other};

    if (owner->getEdge().getDir() == Direction::Down)
    { //owner is p1
        if (owner->getPiece("M1"))
            owner->addPiece("M2", new Firewall{p, owner}, players);
        else
            owner->addPiece("M1", new Firewall{p, owner}, players);
    }
    else //owner is p2
    {
        if (owner->getPiece("W1"))
            owner->addPiece("W2", new Firewall{p, owner}, players);
        else
            owner->addPiece("W1", new Firewall{p, owner}, players);
    }
}
