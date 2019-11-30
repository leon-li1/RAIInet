#ifndef LINKBOOST_H
#define LINKBOOST_H
#include "ability.h"

class Player;

class Linkboost : public Ability
{
public:
    Linkboost(Player *owner, Player *other);
    void use(std::istream &in) override;
};

#endif
