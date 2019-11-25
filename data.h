#ifndef DATA_H
#define DATA_H
#include "piece.h"

class Data : public Piece
{
    int strength;
public:
    void notify(Subject &whoFrom);
    void setStrength(int strength);
    int getStrength();
};

#endif
