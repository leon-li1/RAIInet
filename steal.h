#ifndef STEAL_H
#define STEAL_H
#include <iostream>
#include "ability.h"

class Player;

class Steal : public Ability
{
public:
    Steal(Player *owner, Player *other);
    void use(std::istream &in) override;
};

#endif
