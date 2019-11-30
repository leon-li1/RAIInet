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
    Player *other;

public:
    Player(Direction dir);
    void move(std::string pieceName, Direction direction);
    bool owns(Piece *piece);
    void addPiece(std::string pieceName, Piece *piece, std::vector<Player *> &players);
    void addAbility(Ability *ability);
    std::string getPieceName(Piece *piece);
    void removePiece(Piece *piece, std::vector<Player *> players);
    void download(Piece *piece);
    void useAbility(int ability, std::istream &in);
    void addKnownPiece(std::string pieceName, std::string info);
    Edge getEdge();
    int pieceCount();
    std::string getPieceInfo(std::string pieceName);
    int getVirusCount();
    int getDataCount();
    void setVirusCount(int newCount);
    void setDataCount(int newCount);
    Piece *getPiece(std::string pieceName);
    void setOther(Player *other);


    friend class Graphics;
    friend class TextDisplay;
    friend class GraphicsDisplay;
};

#endif
