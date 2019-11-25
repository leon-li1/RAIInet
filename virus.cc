#include "virus.h"

void Virus::Virus(int speed, Point pos, Player *owner, int strength) : Piece{speed, pos, owner}, strength{strength} {}

void Virus::notify(Subject &whoFrom) {
    if (whoFrom->getPos() == pos) {
        if (owner == whoFrom.getOwner()) { //Cannot move on top of your own piece
            throw InvalidMove{};
        } else {
            //Reveal info about each piece
            //Reveal this piece to other player
            whoFrom.getOwner()->addKnownPiece(owner->getPieceName(this), getInfo());
            //Reveal other player's piece to this player
            owner->addKnownPiece(whoFrom.getOwner()->getPieceName(&whoFrom), whoFrom.getInfo());

            //Winner downloads the other player's link
            if (strength > other.strength) {
                owner->download(&whoFrom);
            } else if (strength < other.strength) {
                whoFrom.getOwner()->download(*this);
            } else { //Tie, so player initiating wins
                whoFrom.getOwner()->download(*this);
            }
        }
    }
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