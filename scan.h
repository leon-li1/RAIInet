#ifndef SCAN_H
#define SCAN_H
#include <iostream>
#include "ability.h"

class Player;

class Scan : public Ability
{
public:
    Scan(Player *owner, Player *other);
    void use(std::istream &in) override;
};

#endif
