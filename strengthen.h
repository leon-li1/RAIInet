#ifndef STRENGTHEN_H
#define STRENGTHEN_H
#include <iostream>
#include "ability.h"

class Player;

class Strengthen: public Ability
{
    public:
    Strengthen(Player *owner, Player *other);
    void use(std::istream &in) override;
};

#endif
