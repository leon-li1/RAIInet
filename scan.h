#ifndef SCAN_H
#define SCAN_H
#include "ability.h"

class Player;

class Scan: public Ability
{
    public:
    Scan(Player *owner, Player *other);
    void use(istream &in) override;
};

#endif
