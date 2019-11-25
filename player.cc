#include "player.h"
#include "piece.h"
#include "ability.h"
#include "point.h"
#include "data.h"
#include "virus.h"
#include "invalidAbility.h"

void Player::move(std::string pieceName, Direction direction)
{

    Piece *thePiece = pieces[pieceName];
    Point newPos = thePiece->getPos();

    if (direction == Direction::Up)
        newPos.y -= thePiece->getSpeed();
    else if (direction == Direction::Down)
        newPos.y += thePiece->getSpeed();
    else if (direction == Direction::Left)
        newPos.x -= thePiece->getSpeed();
    else // direction is right
        newPos.x += thePiece->getSpeed();

    thePiece->setPos(newPos);

    // notify other pieces
}

bool Player::owns(Piece *piece)
{
    for (auto &p : pieces)
    {
        if (p.second == piece)
            return true;
    }

    return false;
}

void Player::addPiece(std::string pieceName, Piece *piece)
{
    pieces[pieceName] = piece;
}

std::string Player::getPieceName(Piece *piece)
{
    for (auto &p : pieces)
    {
        if (p.second == piece)
            return p.first;
    }
    return "";
}

void Player::removePiece(Piece *piece)
{
    for (auto &p : pieces)
    {
        if (p.second == piece)
            pieces.erase(p.first);
    }
}

void Player::download(Data *piece)
{
    ++dataCount;

    if (this == piece->getOwner())
    {
        removePiece(piece);
    }

    else
    {
        Player *otherPlayer = piece->getOwner;
        otherPlayer->removePiece(piece);
    }
}

void Player::download(Virus *piece)
{
    ++virusCount;

    if (this == piece->getOwner())
    {
        removePiece(piece);
    }

    else
    {
        Player *otherPlayer = piece->getOwner;
        otherPlayer->removePiece(piece);
    }
}

void Player::useAbility(int ability)
{

    if (!abilities[ability])
        throw InvalidAbility{};

    abilities[ability]->use();
    abilities[ability] = nullptr;
}

void Player::addKnownPiece(std::string pieceName, std::string info)
{
    knownPieces[pieceName] = info;
}
