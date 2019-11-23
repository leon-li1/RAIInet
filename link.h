#ifndef LINK_H
#define LINK_H
#include "piece.h"
#include <string>

enum class Direction;

class Link : public Piece
{
    int strength;
    std::string type;

public:
    void move(Direction direction);
    void setSpeed(int speed);
    std::string getType() override;
};

#endif
