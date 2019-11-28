#ifndef ABLITY_H
#define ABLITY_H
#include <iostream>

class Player;

class Ability
{
    Player *owner;
    Player *other;

public:
    virtual void use(istream &in) = 0;
};

#endif
