#ifndef TELEPORT_H
#define TELEPORT_H
#include <iostream>
#include "ability.h"

class Player;

class Teleport: public Ability
{
    public:
    Teleport(Player *owner, Player *other);
    void use(std::istream &in) override;
};

#endif
