#ifndef PLAYER_H
#define PLAYER_H
#include <map>
#include <vector>
#include <string>
#include "edge.h"

class Piece;
class Ability;
class InvalidAbility;
class Virus;
class Data;

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
    std::string getPieceName(Piece *piece);
    void removePiece(Piece *piece);
    void download(Virus *virus);
    void download(Data *data);
    void useAbility(int ability);
    void addKnownPiece(std::string pieceName, std::string info);

    friend class Graphics;
    friend class TextDisplay;
    friend class GraphicsDisplay;
};

#endif
