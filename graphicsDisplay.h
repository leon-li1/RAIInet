#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <vector>
#include "window.h"
#include "graphics.h"


class Xwindow;
class Player;

class GraphicsDisplay : public Graphics
{
    Xwindow *xw;
    int p1AbCount = 5;
    int p2AbCount = 5;
    int p1VCount = 0;
    int p1DCount = 0;
    int p2VCount = 0;
    int p2DCount = 0;
    char board[8][8];

    void p1Ability();
    void p2Ability();
    void p1LinkCount();
    void p2LinkCount();
    void p1Links(Player &player);
    void p2Links(Player &player);

    public:
        GraphicsDisplay(std::vector<Player *> players, std::vector<std::string> p1Abilities, std::vector<std::string> p2Abilities);
        ~GraphicsDisplay();
        void update(Player &player) override;
        void printAbilities(Player &player) override;
        void gameOver(std::vector<Player *> players) override;
};

#endif
