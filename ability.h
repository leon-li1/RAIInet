#ifndef ABLITY_H
#define ABLITY_H
#include <iostream>

class Player;

class Ability
{
    protected:
    Player *owner;
    Player *other;
    
    public:
    Ability(Player*, Player*);
    virtual void use(std::istream &in) = 0;
};

#endif
