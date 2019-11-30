#include <exception>
#include "piece.h"
#include "player.h"
#include "invalidMove.h"

Piece::Piece(Point pos, Player *owner) : pos{pos}, owner{owner} {}

bool isInside(Point p) {
    if (p.x >= 0 && p.x < 8) {
        if (p.y >= 0 && p.y < 8) {
            return true;
        }
    }
    return false;
}

void Piece::setPos(Point newPos) {
    Point oldPos = pos;
    if (owner->getEdge().isPassed(newPos)) { 
            owner->download(this);
            //std::cout << "download by passing edge" << std::endl;
            return;
    }
    if (!isInside(newPos)) {
        throw InvalidMove{"The new position is off the grid"};
        return;
    }
    try {
        pos = newPos;
        this->notifyObservers(); //this function is failing
    } catch (InvalidMove im) {
        pos = oldPos;
        throw im;
    }
}

Point Piece::getPos() {
    return pos;
}

Player *Piece::getOwner() {
    return owner;
}

void Piece::setSpeed(int speed) {}

int Piece::getSpeed() {
    return 0;
}

void Piece::setStrength(int strength) {}

int Piece::getStrength() {
    return 0;
}
