#ifndef VIRUS_H
#define VIRUS_H
#include "piece.h"

class Virus: public Piece {
    int strength;
public:
    void notify(Subject &whoFrom);
    void setStrength(int strength);
    int getStrength();
};

#endif
