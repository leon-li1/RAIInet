#ifndef STEAL_H
#define STEAL_H
#include "ability.h"

class Player;

class Steal: public Ability
{
    public:
    Steal(Player *owner, Player *other);
    void use() override;
};

#endif
