#ifndef DATA_H
#define DATA_H
#include <string>
#include "piece.h"

class InvalidMove;

class Data : public Piece
{
    int strength;
    int speed;

public:
    Data(int speed, Point pos, Player *owner, int strength);
    void notify(Subject &whoFrom) override;
    void setStrength(int strength) override;
    int getStrength() override;
    void setSpeed(int speed) override;
    int getSpeed() override;
    std::string getInfo() override;
};

#endif
