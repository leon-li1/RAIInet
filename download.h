#ifndef DOWNLOAD_H
#define DOWNLOAD_H
#include "ability.h"

class Download : public Ability
{
public:
    void use() override;
};

#endif
