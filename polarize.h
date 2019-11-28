#ifndef POLARIZE_H
#define POLARIZE_H
#include "ability.h"

class Player;

class Polarize : public Ability
{
public:
    Polarize(Player *owner, player * other);
    void use(istream &in) override;
};

#endif
