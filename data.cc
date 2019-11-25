#include "data.h"

void Data::notify(Subject &whoFrom) {
    if (whoFrom->getPos() == pos) {
        if (owner == whoFrom.getOwner()) {
            throw InvalidMove{};
        }
    }
}

void Data::setStrength(int strength) {
    this->strength = strength;
}

int Data::getStrength() {
    return strength;
}