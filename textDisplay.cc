#include <iostream>
#include <string>
#include "textDisplay.h"
#include "player.h"
#include "piece.h"


TextDisplay::TextDisplay(std::vector<Player *> players) : Graphics{players} {}

void TextDisplay::update(Player &player) {
    //Supports more than one player
    for (int i = 0; i < (int)players.size(); i++) {
        if (players[i] == &player) std::cout << "Player " << i+1 << ":" << std::endl;
    }
    //Print links downloaded
    std::cout << "Downloaded: " << player.dataCount << "D, " << player.virusCount << "V" << std::endl;

    //Print abilities
    int abilityCount = 0;
    for (auto &a : player.abilities) {
        if (a != nullptr) abilityCount++;
    }
    std::cout << "Abilities: " << abilityCount << std::endl;

    //Print links
    int c = 0;
    for (auto &p : player.pieces) {
        if (p.second->getInfo() != "") {
            std::cout << p.first << ": " << p.second->getInfo();
            if (c == 3 || c == 7) {
                std::cout << std::endl;
            } else {
                std::cout << "\t";
            }
            c++;
        }
    }

    //Print actual board
    std::cout << "========" << std::endl;
    char board[8][8];
    
    // initialize board to '.'
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = '.';
        }
    }
    
    // overwrite '.' with pieces
    for (auto &pl : players) {
        for (auto &p: pl->pieces) {
            //std::cout << p.first << " is at position " << p.second->getPos().x << ", " << p.second->getPos().y << std::endl;
            board[p.second->getPos().x][p.second->getPos().y] = p.first[0];
            //std::cout << p.first[0] << std::endl;
        }
    }

    // print the board array
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << board[j][i];
        }
        std::cout << std::endl;
    }
    std::cout << "========" << std::endl;
        

    //Print known information about the other player(s)
    for (int i = 0; i < (int)players.size(); i++) {
        if (players[i] != &player) {
            //Print player
            std::cout << "Player " << i+1 << ":" << std::endl;

            //Print links downloaded
            std::cout << "Downloaded: " << players[i]->dataCount << "D, " << players[i]->virusCount << "V" << std::endl;

            //Print abilities
            int abilityC = 0;
            for (auto &a : players[i]->abilities) {
                if (a != nullptr) abilityC++;
            }
            std::cout << "Abilities: " << abilityC << std::endl;

            //Print known pieces of other player(s)
            c = 0;
            for (auto &p : players[i]->pieces) {
                if (p.second->getInfo() != "") {
                    bool in = false;
                    for (auto &known : player.knownPieces) {
                        if (known.first == p.first) {
                            in = true;
                            break;
                        }
                    }
                    if (in) {
                        std::cout << p.first << ": " << player.knownPieces[p.first];
                    } else {
                        std::cout << p.first << ": ?";
                    }
                    if ((c + 1) % 4 == 0) {
                        std::cout << std::endl;
                    } else {
                        std::cout << "\t";
                    }
                    c++;
                }
            }
        }
    }
}
