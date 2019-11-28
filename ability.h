#ifndef ABLITY_H
#define ABLITY_H

class Player;

class Ability
{
    Player *owner;
    Player *other;
    
    Ability(Player*, Player*);
    

public:
    virtual void use() = 0;
};

#endif
