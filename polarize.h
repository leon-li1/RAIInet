#ifndef POLARIZE_H
#define POLARIZE_H
#include <iostream>
#include "ability.h"

class Player;

class Polarize : public Ability
{
public:
    Polarize(Player *owner, Player * other);
    void use(std::istream &in) override;
};

#endif
