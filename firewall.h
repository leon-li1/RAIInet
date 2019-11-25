#ifndef FIREWALL_H
#define FIREWALL_H
#include "piece.h"

class Firewall : public Piece
{
public:
    void notify(Piece &whoFrom) override;
};

#endif
