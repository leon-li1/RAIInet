#ifndef FIREWALL_H
#define FIREWALL_H
#include <string>
#include "piece.h"

class Subject;
struct point;

class Firewall : public Piece
{
public:
    Firewall(Point pos, Player *owner);
    void notify(Subject &whoFrom) override;
    std::string getInfo() override;
};

#endif
