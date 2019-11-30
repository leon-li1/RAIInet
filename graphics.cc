#include "graphics.h"
#include "player.h"
#include "piece.h"

Graphics::Graphics(std::vector<Player *> players) : players{players} {
    for (auto &p : players[0]->pieces) {
        p1Pieces[p.first] = p.second->getInfo();
    }
    for (auto &p : players[1]->pieces) {
        p2Pieces[p.first] = p.second->getInfo();
    }
}