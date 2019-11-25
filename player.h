#ifndef PLAYER_H
#define PLAYER_H
#include "edge.h"
#include <map>
#include <vector>
#include <string>

enum class Direction
{
    Up,
    Down,
    Left,
    Right
};

class Piece;
class Ability;
class InvalidAbility;

class Player
{
    std::map<std::string, Piece *> pieces;
    std::vector<Ability *> abilities;
    int dataCount;
    int virusCount;
    std::map<std::string, std::string> knownPieces;
    Edge adjacentEdge;

public:
    void move(std::string pieceName, Direction direction);
    bool owns(Piece *piece);
    void addPiece(std::string pieceName, Piece *piece);
    Piece *gePiece(std::string pieceName);
    void removePiece(Piece *piece);
    void download(Piece *piece);
    void useAbility(int ability);
    void addKnownPiece(std::string pieceName, std::string info);
};

#endif
