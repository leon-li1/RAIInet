#include "edge.h"

Edge::Edge(Direction dir) : dir{dir} {}
Edge::~Edge() {}

bool Edge::isPassed(Point p){
    if (dir == Direction::Up){
        if(p.y < 0) return true;
    }
    else if(dir == Direction::Down){
        if(p.y > 8) return true;
    }

    return false;
}

