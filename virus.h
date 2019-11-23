#ifndef VIRUS_H
#define VIRUS_H
#include "link.h"

class Virus: public Link{
    public:
    void notify(Subject &whoFrom);
};

#endif
