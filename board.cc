#include "board.h"

static bool Board::isInside(Point p){
    if(p.x >= 0 && p.x <= 8){
        if(p.y >= 0 && p.x <= 8){
            return true;
        }
    }
    return false;
}