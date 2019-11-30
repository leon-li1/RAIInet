#include <string>
#include <vector>
#include "player.h"
#include "piece.h"
#include "ability.h"
#include "point.h"
#include "data.h"
#include "virus.h"
#include "invalidAbility.h"
#include "invalidMove.h"

Player::Player(Direction dir) : dataCount{0}, virusCount{0}, adjacentEdge{Edge{dir}} {}

void Player::move(std::string pieceName, Direction direction)
{
    bool inArray = false;
    for (auto &p : pieces) {
        if (p.first == pieceName) inArray = true;
    }
    if (!inArray) throw InvalidMove{"You must move a link you own."};

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

void Player::addPiece(std::string pieceName, Piece *piece, std::vector<Player *> &players)
{
    //add observers
    for (auto &pl : players) {
        for (auto &p : pl->pieces) {
            (p.second)->attach(piece);
            piece->attach(p.second);
        }
    }

    //add the piece to the map
    pieces[pieceName] = piece;
}

void Player::addAbility(Ability *ability) {
    abilities.emplace_back(ability);
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

void Player::removePiece(Piece *piece, std::vector<Player *> players)
{
    //Remove observers
    for (auto &pl : players) {
        for (auto &p : pl->pieces) {
            p.second->detach(piece);
        }
    }
    
    //erase it from the map
    for (auto &p : pieces)
    {
        if (p.second == piece) {
            delete piece;
            p.second = nullptr;
            pieces.erase(p.first);
            return;
        }
    }
}

void Player::download(Piece *piece)
{
    if (piece->getInfo()[0] == 'D') dataCount++;
    else if (piece->getInfo()[0] == 'V') virusCount++;

    std::vector<Player *> ps;
    ps.emplace_back(this);
    ps.emplace_back(other);
    piece->getOwner()->removePiece(piece, ps);
}

void Player::useAbility(int ability, std::istream &in)
{

    if (!abilities[ability])
        throw InvalidAbility{};

    abilities[ability]->use(in);
    abilities[ability] = nullptr;
}

void Player::addKnownPiece(std::string pieceName, std::string info)
{
    knownPieces[pieceName] = info;
}

Edge Player::getEdge() {
    return adjacentEdge;
}

int Player::pieceCount() {
    return (int)pieces.size();
}

std::string Player::getPieceInfo(std::string pieceName) {
    return pieces[pieceName]->getInfo();
}

int Player::getVirusCount() {
    return virusCount;
}

int Player::getDataCount() {
    return dataCount;
}

void Player::setVirusCount(int newCount) {
    virusCount = newCount;
}

void Player::setDataCount(int newCount) {
    dataCount = newCount;
}

Piece *Player::getPiece(std::string pieceName) {
    if (pieces.count(pieceName) > 0) 
        return pieces[pieceName];
    else
        return nullptr;
}

void Player::setOther(Player *other) {
    this->other = other;
}