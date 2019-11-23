#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <vector>

class Player;

class Graphics
{
    std::vector<Player *> players;

    // is this right?
    friend class Player;

public:
    virtual void update(Player &player) = 0;
};

#endif
