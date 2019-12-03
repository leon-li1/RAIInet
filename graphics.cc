#include "graphics.h"
#include "player.h"
#include "piece.h"

Graphics::Graphics(std::vector<Player *> players, std::vector<std::string> p1Abilities, std::vector<std::string> p2Abilities) : players{players}, p1Abilities{p1Abilities}, p2Abilities{p2Abilities}
{
    for (auto &p : players[0]->pieces)
    {
        p1Pieces[p.first] = p.second->getInfo();
    }
    for (auto &p : players[1]->pieces)
    {
        p2Pieces[p.first] = p.second->getInfo();
    }
}

Graphics::~Graphics(){};
