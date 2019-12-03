#ifndef FIREWALLABILITY_H
#define FIREWALLABILITY_H

#include <vector>

#include "ability.h"
#include "point.h"

class FirewallAbility : public Ability
{
public:
    FirewallAbility(Player *, Player *);
    void use(std::istream &in) override;
};

#endif
