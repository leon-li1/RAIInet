#include <exception>
#include "piece.h"
#include "board.h"

Piece::Piece(int speed, Point pos, Player *owner) : speed{speed}, pos{pos}, owner{owner} {}

void Piece::setPos(Point newPos) {
    Point oldPos = pos;
    if (owner->adjacentEdge->isPassed(newPos)) {
            owner->download(*this);
            return;
    }
    if (!Board::isInside(newPos)) {
        throw InvalidMove{};
        return;
    }
    try {
        pos = newPos;
        this->notifyObservers();
    } catch (InvalidMove) {
        pos = oldPos;
        throw InvalidMove{};
    }
}

Point Piece::getPos() {
    return pos;
}

Player *Piece::getOwner() {
    return owner;
}

int Piece::getSpeed() {
    return speed;
}

void Piece::setSpeed(int speed) {
    this->speed = speed;
}