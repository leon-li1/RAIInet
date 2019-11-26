#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <vector>

class Player;

class Graphics
{
    std::vector<Player *> players;

public:
    Graphics(std::vector<Player *> players);
    virtual void update(Player &player) = 0;
};

#endif
