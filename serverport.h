#ifndef SERVERPORT_H
#define SERVERPORT_H
#include  "piece.h"

class Serverport: public Piece{
    public:
    void notify(Subject &whoFrom);
};

#endif
