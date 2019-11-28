#ifndef REVIVE_H
#define REVIVE_H
#include "ability.h"

class Player;

class Revive: public Ability
{
    public:
    Revive(Player *owner, Player *other);
    void use(istream &in) override;
};

#endif
