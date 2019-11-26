#ifndef SERVERPORT_H
#define SERVERPORT_H
#include <string>
#include "piece.h"


class Serverport : public Piece
{
public:
    Serverport(Point pos, Player *owner);
    void notify(Subject &whoFrom) override;
    std::string getInfo() override;
};

#endif
