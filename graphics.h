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
    std::vector<std::string> p1Abilities;
    std::vector<std::string> p2Abilities;

public:
    Graphics(std::vector<Player *> players, std::vector<std::string> p1Abilities, std::vector<std::string> p2Abilities);
    virtual void update(Player &player) = 0;
    virtual void printAbilities(Player &player) = 0;
    virtual void gameOver(std::vector<Player *> players) = 0;
};

#endif
