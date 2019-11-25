#ifndef DATA_H
#define DATA_H
#include <string>
#include "piece.h"

class InvalidMove;

class Data : public Piece
{
    int strength;

public:
    Data(int speed, Point pos, Player *owner, int strength);
    void notify(Piece &whoFrom) override;
    void setStrength(int strength);
    int getStrength();
    std::string getInfo() override;
};

#endif
