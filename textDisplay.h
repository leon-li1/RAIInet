#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "graphics.h"

class TextDisplay : public Graphics
{
public:
    void update(Player &player) override;
};

#endif
