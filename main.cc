#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <sstream>
#include <vector>
#include "player.h"
#include "direction.h"
#include "invalidMove.h"
#include "data.h"
#include "virus.h"
#include "firewall.h"
#include "point.h"
#include "serverport.h"
#include "graphics.h"
#include "textDisplay.h"
#include "linkboost.h"
#include "download.h"
#include "steal.h"
#include "teleport.h"
#include "strengthen.h"
#include "firewallAbility.h"
#include "polarize.h"
#include "scan.h"
#include "graphicsDisplay.h"
using namespace std;

int main(int argc, char *argv[])
{

    // Create the players
    Player p1{Direction::Down};
    Player p2{Direction::Up};
    p1.setOther(&p2);
    p2.setOther(&p1);

    //Make players vector
    vector<Player *> players;
    players.emplace_back(&p1);
    players.emplace_back(&p2);

    //List of abilities for display
    vector<string> p1Abilities;
    vector<string> p2Abilities;

    //Whether to use text graphics or not
    bool textgraphics = true;

    int i = 0;
    // Loop through arguments
    while (i < argc)
    {
        string command = argv[i];

        if (command == "-ability1" || command == "-ability2")
        {
            //This is to keep track of how many of each ability has been taken
            //When we load abilites in, if any player tries to take more than 2, game will throw an error
            map<char, int> abilityCount;
            abilityCount['L'] = 0; //Linkboost
            abilityCount['F'] = 0; //Firewall
            abilityCount['D'] = 0; //Download
            abilityCount['S'] = 0; //Scan
            abilityCount['P'] = 0; //Polarize
            abilityCount['T'] = 0; //Teleport
            abilityCount['R'] = 0; //Steal
            abilityCount['G'] = 0; //Strengthen

            string a = argv[i + 1];
            if ((int)a.length() != 5)
            {
                cerr << "Error: You must take 5 abilities" << endl;
                return 1;
            }

            for (int j = 0; j < 5; ++j)
            {
                if (a[j] == 'L')
                {
                    abilityCount['L']++;
                    if (abilityCount['L'] >= 3)
                    {
                        cerr << "Invalid Ability setup, you cannot have more than 2 of the same ability" << endl;
                        return 1;
                    }

                    if (command == "-ability1")
                    {
                        p1.addAbility(new Linkboost{&p1, &p2});
                        p1Abilities.emplace_back("Link boost");
                    }
                    else if (command == "-ability2")
                    {
                        p2.addAbility(new Linkboost{&p2, &p1});
                        p2Abilities.emplace_back("Link boost");
                    }
                }
                else if (a[j] == 'F')
                {
                    abilityCount['F']++;
                    if (abilityCount['F'] >= 3)
                    {
                        cerr << "Invalid Ability setup, you cannot have more than 2 of the same ability" << endl;
                        return 1;
                    }

                    if (command == "-ability1")
                    {
                        p1.addAbility(new FirewallAbility{&p1, &p2});
                        p1Abilities.emplace_back("Firewall");
                    }
                    else if (command == "-ability2")
                    {
                        p2.addAbility(new FirewallAbility{&p2, &p1});
                        p2Abilities.emplace_back("Firewall");
                    }
                }
                else if (a[j] == 'D')
                {
                    abilityCount['D']++;
                    if (abilityCount['D'] >= 3)
                    {
                        cerr << "Invalid Ability setup, you cannot have more than 2 of the same ability" << endl;
                        return 1;
                    }

                    if (command == "-ability1")
                    {
                        p1.addAbility(new Download{&p1, &p2});
                        p1Abilities.emplace_back("Download");
                    }
                    else if (command == "-ability2")
                    {
                        p2.addAbility(new Download{&p2, &p1});
                        p2Abilities.emplace_back("Download");
                    }
                }
                else if (a[j] == 'S')
                {
                    abilityCount['S']++;
                    if (abilityCount['S'] >= 3)
                    {
                        cerr << "Invalid Ability setup, you cannot have more than 2 of the same ability" << endl;
                        return 1;
                    }

                    if (command == "-ability1")
                    {
                        p1.addAbility(new Scan{&p1, &p2});
                        p1Abilities.emplace_back("Scan");
                    }
                    else if (command == "-ability2")
                    {
                        p2.addAbility(new Scan{&p2, &p1});
                        p2Abilities.emplace_back("Scan");
                    }
                }
                else if (a[j] == 'P')
                {
                    abilityCount['P']++;
                    if (abilityCount['P'] >= 3)
                    {
                        cerr << "Invalid Ability setup, you cannot have more than 2 of the same ability" << endl;
                        return 1;
                    }

                    if (command == "-ability1")
                    {
                        p1.addAbility(new Polarize{&p1, &p2});
                        p1Abilities.emplace_back("Polarize");
                    }
                    else if (command == "-ability2")
                    {
                        p2.addAbility(new Polarize{&p2, &p1});
                        p2Abilities.emplace_back("Polarize");
                    }
                }
                else if (a[j] == 'T')
                {
                    abilityCount['T']++;
                    if (abilityCount['T'] >= 3)
                    {
                        cerr << "Invalid Ability setup, you cannot have more than 2 of the same ability" << endl;
                        return 1;
                    }
                    if (command == "-ability1")
                    {
                        p1.addAbility(new Teleport{&p1, &p2});
                        p1Abilities.emplace_back("Teleport");
                    }
                    else if (command == "-ability2")
                    {
                        p2.addAbility(new Teleport{&p2, &p1});
                        p2Abilities.emplace_back("Teleport");
                    }
                }
                else if (a[j] == 'R')
                {
                    abilityCount['R']++;
                    if (abilityCount['R'] >= 3)
                    {
                        cerr << "Invalid Ability setup, you cannot have more than 2 of the same ability" << endl;
                        return 1;
                    }

                    if (command == "-ability1")
                    {
                        p1.addAbility(new Steal{&p1, &p2});
                        p1Abilities.emplace_back("Steal");
                    }
                    else if (command == "-ability2")
                    {
                        p2.addAbility(new Steal{&p2, &p1});
                        p2Abilities.emplace_back("Steal");
                    }
                }
                else if (a[j] == 'G')
                {
                    abilityCount['G']++;
                    if (abilityCount['G'] >= 3)
                    {
                        cerr << "Invalid Ability setup, you cannot have more than 2 of the same ability" << endl;
                        return 1;
                    }

                    if (command == "-ability1")
                    {
                        p1.addAbility(new Strengthen{&p1, &p2});
                        p1Abilities.emplace_back("Strengthen");
                    }
                    else if (command == "-ability2")
                    {
                        p2.addAbility(new Strengthen{&p2, &p1});
                        p2Abilities.emplace_back("Strengthen");
                    }
                }
                else
                {
                    cerr << "Invalid ability taken" << endl;
                    return 1;
                }
                //If more abilities are added, they will be checked for here
            }
            ++i;
        }
        else if (command == "-link1" || command == "-link2")
        {
            string l = argv[i + 1];
            char which;
            if (command == "-link1")
                which = 'a';
            else if (command == "-link2")
                which = 'A';

            //We need to keep track of which links user has selected to make sure they don't take
            //  too many links or two of the same link
            map<string, int> linkCount;
            linkCount["D1"] = 0;
            linkCount["D2"] = 0;
            linkCount["D3"] = 0;
            linkCount["D4"] = 0;
            linkCount["V1"] = 0;
            linkCount["V2"] = 0;
            linkCount["V3"] = 0;
            linkCount["V4"] = 0;

            for (int j = 0; j < (int)l.length(); ++j)
            {
                if (l[j] == 'D')
                {
                    // Scale strength to 1-4
                    int strength = l[j + 1] - '0';

                    ++linkCount["D" + to_string(strength)];

                    if (command == "-link1")
                    {
                        p1.addPiece(string(1, which), new Data{1, Point{j / 2, (j == 6 || j == 8 ? 1 : 0)}, &p1, strength}, players);
                    }
                    else if (command == "-link2")
                    {
                        p2.addPiece(string(1, which), new Data{1, Point{j / 2, (j == 6 || j == 8 ? 6 : 7)}, &p2, strength}, players);
                    }
                    ++which;
                    ++j;
                }
                else if (l[j] == 'V')
                {
                    // Scale strength to 1-4
                    int strength = l[j + 1] - '0';

                    ++linkCount["V" + to_string(strength)];

                    if (command == "-link1")
                    {
                        p1.addPiece(string(1, which), new Virus{1, Point{j / 2, (j == 6 || j == 8 ? 1 : 0)}, &p1, strength}, players);
                    }
                    else if (command == "-link2")
                    {
                        p2.addPiece(string(1, which), new Virus{1, Point{j / 2, (j == 6 || j == 8 ? 6 : 7)}, &p2, strength}, players);
                    }
                    ++which;
                    ++j;
                }
            }

            int totalLinks = 0;
            for (auto &p : linkCount)
            {
                totalLinks++;
                if (p.second != 1 || totalLinks > 8)
                {
                    cerr << "Invalid link setup, you must use each of D1, D2, D3, D4, V1, V2, V3, V4 exactly once." << endl;
                    return 1;
                }
            }
            ++i;
        }
        else if (command == "-graphics")
        {
            textgraphics = false;
        }

        ++i;
    }

    //Default link setup for p1
    if (p1.pieceCount() < 8)
    {
        char which = 'a';
        for (int i = 0; i < 8; i++)
        {
            if (i < 4)
                p1.addPiece(string(1, which + i), new Virus{1, Point{i, (i == 3 || i == 4 ? 1 : 0)}, &p1, i + 1}, players);
            else
                p1.addPiece(string(1, which + i), new Data{1, Point{i, (i == 3 || i == 4 ? 1 : 0)}, &p1, (i % 4) + 1}, players);
        }
    }

    //Default link setup for p2
    if (p2.pieceCount() < 8)
    {
        char which = 'A';
        for (int i = 0; i < 8; i++)
        {
            if (i < 4)
                p2.addPiece(string(1, which + i), new Virus{1, Point{i, (i == 3 || i == 4 ? 6 : 7)}, &p2, i + 1}, players);
            else
                p2.addPiece(string(1, which + i), new Data{1, Point{i, (i == 3 || i == 4 ? 6 : 7)}, &p2, (i % 4) + 1}, players);
        }
    }

    //Default abilites
    if (p1.abilityCount() == 0)
    { //player 1 defaults
        p1.addAbility(new Linkboost{&p1, &p2});
        p1.addAbility(new FirewallAbility{&p1, &p2});
        p1.addAbility(new Download{&p1, &p2});
        p1.addAbility(new Scan{&p1, &p2});
        p1.addAbility(new Polarize{&p1, &p2});
        p1Abilities.emplace_back("Link boost");
        p1Abilities.emplace_back("Firewall");
        p1Abilities.emplace_back("Download");
        p1Abilities.emplace_back("Scan");
        p1Abilities.emplace_back("Polarize");
    }

    if (p2.abilityCount() == 0)
    { //player 2 defaults
        p2.addAbility(new Linkboost{&p2, &p1});
        p2.addAbility(new FirewallAbility{&p2, &p1});
        p2.addAbility(new Download{&p2, &p1});
        p2.addAbility(new Scan{&p2, &p1});
        p2.addAbility(new Polarize{&p2, &p1});
        p2Abilities.emplace_back("Link boost");
        p2Abilities.emplace_back("Firewall");
        p2Abilities.emplace_back("Download");
        p2Abilities.emplace_back("Scan");
        p2Abilities.emplace_back("Polarize");
    }

    //Create graphics
    Graphics *g;
    if (textgraphics)
    {
        g = new TextDisplay{players, p1Abilities, p2Abilities};
    }
    else
    {
        g = new GraphicsDisplay{players, p1Abilities, p2Abilities};
    }

    // Create serverports
    p1.addPiece("S1", new Serverport{Point{3, 0}, &p1}, players);
    p1.addPiece("S2", new Serverport{Point{4, 0}, &p1}, players);
    p2.addPiece("S1", new Serverport{Point{3, 7}, &p2}, players);
    p2.addPiece("S2", new Serverport{Point{4, 7}, &p2}, players);

    string command;
    ifstream inFile{};
    string turn = "p1";
    string mode = "cin";
    bool usedAbility = false;

    g->update(p1);

    while (true)
    {
        //Game over
        if (p2.getVirusCount() > 3 || p1.getDataCount() > 3 || p1.getVirusCount() > 3 || p2.getDataCount() > 3)
        {
            g->gameOver(players);
            //break;
        }

        if (inFile.eof())
            mode = "cin";

        if (cin.eof())
            break;

        if (mode == "cin")
        {

            cin >> command;
        }
        else if (mode == "sequence")
        {

            inFile >> command;

            if (inFile.fail())
            {
                mode = "cin";
                continue;
            }
        }

        if (command == "move")
        {
            string which;
            string direction;

            if (mode == "cin")
            {
                cin >> which;
                cin >> direction;

                if (cin.eof())
                {
                    cerr << "Invalid direction" << endl;
                    continue;
                }
            }
            else if (mode == "sequence")
            {
                inFile >> which;
                inFile >> direction;

                if (inFile.eof())
                {
                    cerr << "Invalid direction" << endl;
                    continue;
                }
            }

            Direction d;

            if (direction == "up")
            {
                d = Direction::Up;
            }
            else if (direction == "down")
            {
                d = Direction::Down;
            }
            else if (direction == "left")
            {
                d = Direction::Left;
            }
            else if (direction == "right")
            {
                d = Direction::Right;
            }
            else
            {
                cerr << "Invalid direction" << endl;
                continue;
            }

            try
            {
                if (turn == "p1")
                    p1.move(which, d);
                else if (turn == "p2")
                    p2.move(which, d);
            }
            catch (InvalidMove im)
            {
                cerr << im.what() << endl;
                continue;
            }

            turn = (turn == "p1") ? "p2" : "p1";
            if (turn == "p1")
                g->update(p1);
            else if (turn == "p2")
                g->update(p2);
            usedAbility = false;
        }
        else if (command == "abilities")
        {
            if (turn == "p1")
                g->printAbilities(p1);
            else if (turn == "p2")
                g->printAbilities(p2);
        }
        else if (command == "ability")
        {
            try
            {
                int abNum;
                if (mode == "cin")
                {
                    if (!(cin >> abNum))
                    {
                        cerr << "Invalid ability" << endl;
                        cin.clear();
                        cin.ignore();
                        continue;
                    }
                }
                else if (mode == "sequence")
                {
                    if (!(inFile >> abNum))
                    {
                        cerr << "Invalid ability" << endl;
                        inFile.clear();
                        inFile.ignore();
                        continue;
                    }
                }

                if (!usedAbility)
                {
                    if (abNum < 1 || abNum > 5)
                    {
                        cerr << "Invalid ability" << endl;
                        continue;
                    }
                    if (turn == "p1")
                    {
                        if (mode == "cin")
                            p1.useAbility(abNum - 1, cin);
                        else if (mode == "sequence")
                            p1.useAbility(abNum - 1, inFile);
                    }
                    else if (turn == "p2")
                    {
                        if (mode == "cin")
                            p2.useAbility(abNum - 1, cin);
                        else if (mode == "sequence")
                            p2.useAbility(abNum - 1, inFile);
                    }
                }
                else
                {
                    cerr << "You have already used an ability this turn" << endl;
                }
                usedAbility = true;
            }
            catch (InvalidMove im)
            {
                cerr << im.what() << endl;
            }
        }
        else if (command == "board")
        {
            if (turn == "p1")
                g->update(p1);
            else if (turn == "p2")
                g->update(p2);
        }
        else if (command == "sequence")
        {
            if (inFile.is_open())
                inFile.close();
            string file;
            cin >> file;
            inFile.open(file);
            if (!inFile.fail())
            {
                mode = "sequence";
            }
            else
            {
                cerr << "Invalid file name" << endl;
                continue;
            }
        }
        else if (command == "quit")
        {
            break;
        }
        else if (command == "gameover")
        { //Only for testing and demonstration purposes
            g->gameOver(players);
        }
        else
        {
            cerr << "Invalid command" << endl;
        }
        command = "";
    }
    delete g;
}
