#include <vector>
#include "graphics.h"
#include "window.h"
#include "graphicsDisplay.h"
#include "player.h"
#include "piece.h"


GraphicsDisplay::GraphicsDisplay(std::vector<Player *> players, std::vector<std::string> p1Abilities, std::vector<std::string> p2Abilities) 
: Graphics{players, p1Abilities, p2Abilities}, xw{new Xwindow{}} {
    //Draw player names
    xw->drawBigString(10, 10, "Player 1:", 1);
    xw->drawBigString(10, 430, "Player 2:", 1);
    
    //Draw ability counts
    p1Ability();
    p2Ability();

    //Draw downloaded link count 
    p1LinkCount();
    p2LinkCount();

    // initialize board to nullptr
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            board[i][j] = std::pair<std::string, std::string>{".", ""};
    }

    // overwrite nullptr with pieces
    for (auto &pl : players)
    {
        for (auto &p : pl->pieces)
        {
            if (p.second)
                board[p.second->getPos().x][p.second->getPos().y] = std::pair<std::string, std::string>{std::string(1, p.first[0]), p.second->getInfo()};
        }
    }

    //Here we need to add the pieces being drawn on the board. 
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (j > 3) drawCell(false, i, j, board[i][j]);
            else drawCell(true, i, j, board[i][j]);
        }
    }
}

GraphicsDisplay::~GraphicsDisplay(){ delete xw; }

void GraphicsDisplay::drawCell(bool turn, int x, int y, std::pair<std::string, std::string> info) {
    int colour;
    if (turn) {
        if (info.second[0] == 'D') {
            colour = 3;
        } else if (info.second[0] == 'V') {
            colour = 2;
        } else {
            if ((x + y) % 2 == 0) {
                colour = Xwindow::Magenta;
            }
            else {
                colour = Xwindow::Cyan;
            }
        }
    } else {
        if ((x + y) % 2 == 0) {
                colour = Xwindow::Magenta;
            }
            else {
                colour = Xwindow::Cyan;
            }
    }
    xw->fillRectangle(25+x*40, 60+y*40, 40, 40, colour); //Draw cell background
    if (info.first != ".") {
        xw->drawBigString(40+40*x, 80+40*y, info.first, 1);
    }
}

void GraphicsDisplay::update(Player &player) {
    //Update pieces array
    for (auto &p : players[0]->pieces) {
        if (p.second->getInfo() != "") {
            p1Pieces[p.first] = p.second->getInfo();
        }
    }
    for (auto &p : players[1]->pieces) {
        if (p.second->getInfo() != "") {
            p2Pieces[p.first] = p.second->getInfo();
        }
    }

    //Check if player 1's abilities need to be refreshed
    int abilityCount = 0;
    for (auto &a : players[0]->abilities)
    {
        if (a)
            ++abilityCount;
    }
    if (abilityCount != p1AbCount) {
        p1AbCount = abilityCount;
        p1Ability();
    }

    //Check if player 2's abilities need to be refreshed
    abilityCount = 0;
    for (auto &a : players[1]->abilities)
    {
        if (a)
            ++abilityCount;
    }
    if (abilityCount != p2AbCount) {
        p2AbCount = abilityCount;
        p2Ability();
    }

    //Print each player's link
    p1Links(player);
    p2Links(player);

    //Redraw pieces
    for (auto &pl : players)
    {
        for (auto &p : pl->pieces)
        {
            bool turn = false;
            if (pl == &player) turn = true;
            board[p.second->getPos().x][p.second->getPos().y] = std::pair<std::string, std::string>{std::string(1,p.first[0]), p.second->getInfo()};
            drawCell(turn, p.second->getPos().x, p.second->getPos().y, board[p.second->getPos().x][p.second->getPos().y]);
        }
    }

    //Redraw squares pieces moved from
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            bool pieceAt = false;
            for (auto &pl : players) {
                for (auto &p : pl->pieces) {
                    if (p.second->getPos().x == i && p.second->getPos().y == j) pieceAt = true;
                }
            }
            if (pieceAt == false && board[i][j].second != ".") {
                board[i][j] = std::pair<std::string, std::string>{".", ""};
                drawCell(false, i, j, board[i][j]);
            }
        }
    }


}

void GraphicsDisplay::printAbilities(Player &player) {

}

void GraphicsDisplay::gameOver(std::vector<Player *> players) {
    
}

void GraphicsDisplay::p1Ability() {
    xw->fillRectangle(100, 0, 120, 15, 0);
    xw->drawBigString(100, 10, "Abilities: " + std::to_string(p1AbCount), 1);
}

void GraphicsDisplay::p2Ability() {
    xw->fillRectangle(100, 420, 120, 15, 0);
    xw->drawBigString(100, 430, "Abilities: " + std::to_string(p2AbCount), 1);
}

void GraphicsDisplay::p1LinkCount() {
    xw->fillRectangle(250, 00, 200, 15, 0);
    xw->drawBigString(250, 10, "Downloaded: " + std::to_string(p1DCount) + "D, " + std::to_string(p1VCount) + "V", 1);
}

void GraphicsDisplay::p2LinkCount() {
    xw->fillRectangle(250, 420, 100, 15, 0);
    xw->drawBigString(250, 430, "Downloaded: " + std::to_string(p2DCount) + "D, " + std::to_string(p2VCount) + "V", 1);
}

void GraphicsDisplay::p1Links(Player &player) {
    xw->fillRectangle(0, 16, 400, 20, 0);
    //Print p1's links
    if (&player == players[0]) {
        int c = 0;
        for (auto &p : p1Pieces)
        {
            xw->drawBigString(10+c*40, 25, p.first + ": " + p.second, 1);
            c++;
        }
    } else { //Print what p2 knows about p1
        int c = 0;
        for (auto &p : p1Pieces)
        {
            std::string out = p.first + ": ";

            bool unknown = true;
            for (auto &known : players[1]->knownPieces) 
            {
                if (p.first == known.first) 
                    unknown = false;
            }

            if (unknown) 
                out = out + "?";
            else
                out = out + p.second;
            
            xw->drawBigString(10+c*40, 25, out, 1);
            c++;
        }
    }
}

void GraphicsDisplay::p2Links(Player &player) {
    xw->fillRectangle(0, 435, 400, 20, 0);
    if (&player == players[1]) {
        int c = 0;
        for (auto &p : p2Pieces)
        {
            xw->drawBigString(10+c*40, 450, p.first + ": " + p.second, 1);
            c++;
        }
    } else { //Print what p2 knows about p1
        int c = 0;
        for (auto &p : p2Pieces)
        {
            std::string out = p.first + ": ";

            bool unknown = true;
            for (auto &known : players[0]->knownPieces) 
            {
                if (p.first == known.first) 
                    unknown = false;
            }

            if (unknown) 
                out = out + "?";
            else
                out = out + p.second;
            
            xw->drawBigString(10+c*40, 450, out, 1);
            c++;
        }
    }
}