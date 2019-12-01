#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "graphics.h"

class TextDisplay : public Graphics
{
public:
    TextDisplay(std::vector<Player *> players, std::vector<std::string> p1Abilities, std::vector<std::string> p2Abilities);
    void update(Player &player) override;
    void printAbilities(Player &player) override;
};

#endif
