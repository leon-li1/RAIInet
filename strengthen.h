#ifndef STRENGTHEN_H
#define STRENGTHEN_H
#include "ability.h"

class Player;

class Strengthen: public Ability
{
    public:
    Strengthen(Player *owner, Player *other);
    void use(istream &in) override;
};

#endif
