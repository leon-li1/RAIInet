#ifndef TELEPORT_H
#define TELEPORT_H
#include "ability.h"

class Player;

class Teleport: public Ability
{
    public:
    Teleport(Player *owner, Player *other);
    void use(istream &in) override;
};

#endif
