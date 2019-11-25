#ifndef VIRUS_H
#define VIRUS_H
#include <string>
#include "piece.h"

class InvalidMove;

class Virus : public Piece
{
    int strength;

public:
    Virus(int speed, Point pos, Player *owner, int strength);
    void notify(Piece &whoFrom) override;
    void setStrength(int strength);
    int getStrength();
    std::string getInfo() override;
};

#endif
