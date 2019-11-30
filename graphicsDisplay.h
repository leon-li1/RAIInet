#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <vector>
#include "graphics.h"

class XWindow;
class Player;

class GraphicsDisplay : public Graphics
{
    XWindow *xw;

    public:
        GraphicsDisplay(std::vector<Player*>);
        void update(Player &player) override;
};

#endif
