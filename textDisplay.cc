#include <iostream>
#include <string>
#include "textDisplay.h"
#include "player.h"
#include "piece.h"

TextDisplay::TextDisplay(std::vector<Player *> players, std::vector<std::string> p1Abilities, std::vector<std::string> p2Abilities)
    : Graphics{players, p1Abilities, p2Abilities} {}

void TextDisplay::update(Player &player)
{
    //Update pieces array
    for (auto &p : players[0]->pieces)
    {
        if (p.second->getInfo() != "")
        {
            p1Pieces[p.first] = p.second->getInfo();
        }
    }
    for (auto &p : players[1]->pieces)
    {
        if (p.second->getInfo() != "")
        {
            p2Pieces[p.first] = p.second->getInfo();
        }
    }
    //Print player name
    std::cout << "Player 1:" << std::endl;

    //Print links downloaded
    std::cout << "Downloaded: " << players[0]->dataCount << "D, " << players[0]->virusCount << "V" << std::endl;

    //Print abilities
    int abilityCount = 0;
    for (auto &a : players[0]->abilities)
    {
        if (a)
            ++abilityCount;
    }
    std::cout << "Abilities: " << abilityCount << std::endl;

    //Print p1's links
    if (&player == players[0])
    {

        int c = 0;

        for (auto &p : p1Pieces)
        {
            std::cout << p.first << ": " << p.second;

            if (c == 3 || c == 7)
                std::cout << std::endl;
            else
                std::cout << "\t";
            c++;
        }
    }
    else
    { //Print what p2 knows about p1

        int c = 0;

        for (auto &p : p1Pieces)
        {
            std::cout << p.first << ": ";
            bool unknown = true;

            for (auto &known : players[1]->knownPieces)
            {
                if (p.first == known.first)
                    unknown = false;
            }

            if (unknown)
                std::cout << "?";
            else
                std::cout << p.second;

            if (c == 3 || c == 7)
                std::cout << std::endl;
            else
                std::cout << "\t";
            c++;
        }
    }

    //Print actual board
    std::cout << "========" << std::endl;
    char board[8][8];

    // initialize board to '.'
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            board[i][j] = '.';
    }

    // overwrite '.' with pieces
    for (auto &pl : players)
    {
        for (auto &p : pl->pieces)
        {
            if (p.second)
                board[p.second->getPos().x][p.second->getPos().y] = p.first[0];
        }
    }

    // print the board array
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            std::cout << board[j][i];

        std::cout << std::endl;
    }

    std::cout << "========" << std::endl;

    //Print known information about player 2
    std::cout << "Player " << 2 << ":" << std::endl;

    //Print links downloaded
    std::cout << "Downloaded: " << players[1]->dataCount << "D, " << players[1]->virusCount << "V" << std::endl;

    //Print abilities
    abilityCount = 0;

    for (auto &a : players[1]->abilities)
    {
        if (a)
            ++abilityCount;
    }

    std::cout << "Abilities: " << abilityCount << std::endl;

    if (&player == players[1])
    {

        int c = 0;

        for (auto &p : p2Pieces)
        {
            std::cout << p.first << ": " << p.second;
            if (c == 3 || c == 7)
                std::cout << std::endl;
            else
                std::cout << "\t";
            c++;
        }
    }
    else
    { //Print what player 1 knows about player 2

        int c = 0;

        for (auto &p : p2Pieces)
        {
            std::cout << p.first << ": ";

            bool unknown = true;
            for (auto &known : players[0]->knownPieces)
            {
                if (p.first == known.first)
                    unknown = false;
            }
            if (unknown)
                std::cout << "?";
            else
                std::cout << p.second;

            if (c == 3 || c == 7)
                std::cout << std::endl;
            else
                std::cout << "\t";
            c++;
        }
    }
}

void TextDisplay::printAbilities(Player &player)
{
    if (&player == players[0])
    { //p1

        for (int i = 0; i < (int)p1Abilities.size(); i++)
        {

            std::string used = "unavailable";

            if (player.abilities[i])
                used = "available";

            std::cout << i + 1 << ":\t" << p1Abilities[i] << "\t";

            if (p1Abilities[i].length() < 8)
                std::cout << "\t";

            std::cout << used << std::endl;
        }
    }
    else
    { //p2

        for (int i = 0; i < (int)p2Abilities.size(); i++)
        {

            std::string used = "unavailable";

            if (player.abilities[i])
                used = "available";

            std::cout << i + 1 << ":\t" << p2Abilities[i] << ":\t";

            if (p2Abilities[i].length() < 8)
                std::cout << "\t";

            std::cout << used << std::endl;
        }
    }
}

void TextDisplay::gameOver(std::vector<Player *> players)
{
    if (players[1]->getVirusCount() > 3 || players[0]->getDataCount() > 3)
    { //Player 1 wins
        std::cout << "Player 1 wins" << std::endl;
    }
    else if (players[0]->getVirusCount() > 3 || players[1]->getDataCount() > 3)
    { //Player 2 wins
        std::cout << "Player 2 wins" << std::endl;
    }
    else
    {
        std::cout << "Player 1 wins" << std::endl;
    }

    std::cout << "Final score: " << std::endl;

    std::cout << "Player " << 1 << ":" << std::endl;
    std::cout << "Downloaded: " << players[0]->dataCount << "D, " << players[0]->virusCount << "V" << std::endl;

    std::cout << "Player " << 2 << ":" << std::endl;
    std::cout << "Downloaded: " << players[1]->dataCount << "D, " << players[1]->virusCount << "V" << std::endl;
}
