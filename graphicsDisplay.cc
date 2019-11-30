#include <vector>
#include "graphics.h"
#include "graphicsDisplay.h"


GraphicsDisplay::GraphicsDisplay(std::vector<Player *> players): Graphics{players} {

    drawBigString(0, 50, "RAIINET");
        //draw grid
    for(int i = 0; i < 8; i++){

        for(int j = 0; j < 8; j++){

            if( (i + j) % 2 == 0){
                fillRectangle(i*50, j*50, 50, 50, Magenta);
            }

            else{
                fillRectangle(i*50, j*50, 50, 50, Cyan);
            }

        }
    }
}

void GraphicsDisplay::update(Player &player) override{

}