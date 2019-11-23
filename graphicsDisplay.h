#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include "graphics.h"

class XWindow;

class GraphicsDisplay : public Graphics
{
    XWindow *xw;

public:
    void update(Player &player) override;
};

#endif
