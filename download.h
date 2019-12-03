#ifndef DOWNLOAD_H
#define DOWNLOAD_H
#include "ability.h"

class Player;

class Download : public Ability
{

public:
    Download(Player *owner, Player *other);
    void use(std::istream &in) override;
};

#endif
