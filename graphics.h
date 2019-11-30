#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <vector>
#include <map>

class Player;

class Graphics
{
protected:
    std::vector<Player *> players;
    std::map<std::string, std::string> p1Pieces;
    std::map<std::string, std::string> p2Pieces;

public:
    Graphics(std::vector<Player *> players);
    virtual void update(Player &player) = 0;
};

#endif
