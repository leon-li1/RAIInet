#ifndef VIRUS_H
#define VIRUS_H
#include <string>
#include "piece.h"

class InvalidMove;

class Virus : public Piece
{
    int strength;
    int speed;

public:
    Virus(int speed, Point pos, Player *owner, int strength);
    void notify(Subject &whoFrom) override;
    void setStrength(int strength) override;
    int getStrength() override;
    void setSpeed(int speed) override;
    int getSpeed() override;
    std::string getInfo() override;
};

#endif
