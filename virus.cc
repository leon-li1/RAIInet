#include "virus.h"

void Virus::Virus(int speed, Point pos, Player *owner, int strength) : Piece{speed, pos, owner}, strength{strength} {}

void Virus::notify(Subject &whoFrom) {
    
}

void Virus::setStrength(int strength) {
    this->strength = strength;
}

int Virus::getStrength() {
    return strength;
}

std::string Virus::getInfo() {
    return "V" + std::to_string(strength);
}