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

    public:
        GraphicsDisplay(std::vector<Player*>);
        ~GraphicsDisplay();
        void update(Player &player) override;
};

#endif
