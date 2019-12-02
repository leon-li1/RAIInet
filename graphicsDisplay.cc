#include <vector>
#include "graphics.h"
#include "window.h"
#include "graphicsDisplay.h"


GraphicsDisplay::GraphicsDisplay(std::vector<Player *> players): Graphics{players} {
    xw = new Xwindow{};
    xw->drawBigString(0, 50, "RAIINET");
        //draw grid
    for(int i = 0; i < 8; i++){

        for(int j = 0; j < 8; j++){

            if( (i + j) % 2 == 0){
                xw->fillRectangle(i*50, j*50, 50, 50, Xwindow::Magenta);
            }

            else{
                xw->fillRectangle(i*50, j*50, 50, 50, Xwindow::Cyan);
            }

        }
    }
}

GraphicsDisplay::~GraphicsDisplay(){ delete xw; }

void GraphicsDisplay::update(Player &player) {

}