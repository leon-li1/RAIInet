#ifndef PLAYER_H
#define PLAYER_H
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

class Player
{
    std::map<std::string, Piece *> pieces;
    std::vector<Ability *> abilities;
    int dataCount;
    int virusCount;
    std::map<std::string, std::string> knownPieces;

public:
    void move(std::string pieceName, Direction direction);
    bool owns(std::string pieceName);
    void addPiece(Piece *piece);
    Piece *gePiece(std::string pieceName);
    void download(Piece *piece);
    void remove(Piece *piece);
    void useAbility(int ability);
    void addKnownPiece(std::string pieceName, std::string info);
};

#endif
