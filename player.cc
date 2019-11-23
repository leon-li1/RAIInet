#include "player.h"
#include "piece.h"
#include "ability.h"
#include "point.h"

void Player::move(std::string pieceName, Direction direction)
{

    Piece *thePiece = pieces[pieceName];
    Point newPos = thePiece->getPos();

    if (direction == Direction::Up)
        newPos.y -= thePiece->speed;
    else if (direction == Direction::Down)
        newPos.y += thePiece->speed;
    else if (direction == Direction::Left)
        newPos.x -= thePiece->speed;
    else // direction is right
        newPos.x += thePiece->speed;

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

Piece *Player::gePiece(std::string pieceName)
{
    return pieces[pieceName];
}

void Player::removePiece(Piece *piece)
{
    for (auto &p : pieces)
    {
        if (p.second == piece)
            pieces.erase(p.first);
    }
}

void Player::download(Piece *piece)
{
    if (piece->getType == "virus")
        ++virusCount;
    else // type is "data"
        ++dataCount;

    if (this == piece->getOwner())
    {
        for (auto &p : pieces)
        {
            if (p.second == piece)
                pieces.erase(p.first);
        }
    }
    else
    {
        Player *otherPlayer = piece->getOwner;
        otherPlayer->removePiece(piece);
    }

    // do I need to do anything else?
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
