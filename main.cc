#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <sstream>
#include "player.h"
#include "direction.h"
#include "invalidAbility.h"
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
            abilityCount['L'] = 0;  //Linkboost
            abilityCount['F'] = 0;  //Firewall
            abilityCount['D'] = 0;  //Download
            abilityCount['S'] = 0;  //Scan
            abilityCount['P'] = 0;  //Polarize
            abilityCount['T'] = 0;  //Teleport
            abilityCount['R'] = 0;  //Steal
            abilityCount['G'] = 0;  //Strengthen

            string a = argv[i + 1];
            if ((int) a.length() != 5)
            {
                cerr << "Error: You must take 5 abilities" << endl;
                return 1;
            }

            for (int j = 0; j < 5; ++j)
            {
                //check what each ability is a display for now, eventually we will add to abilities array
                if (a[j] == 'L')
                {
                    abilityCount['L']++;
                    if (abilityCount['L'] >= 3)
                    {
                        cerr << "Invalid Ability setup, you cannot have more than 2 of the same ability" << endl;
                        return 1;
                    }
                    cout << "link boost ";
                    if (command == "-ability1")
                    {
                        cout << "to player 1 in position " << j + 1 << endl;
                        p1.addAbility(new Linkboost{&p1, &p2});
                        p1Abilities.emplace_back("Link boost");
                    }
                    else if (command == "-ability2")
                    {
                        cout << "to player 2 in position " << j + 1 << endl;
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
                    cout << "firewall ";
                    if (command == "-ability1")
                    {
                        cout << "to player 1 in position " << j + 1 << endl;
                        p1.addAbility(new FirewallAbility{&p1, &p2});
                        p1Abilities.emplace_back("Firewall");
                    }
                    else if (command == "-ability2")
                    {
                        cout << "to player 2 in position " << j + 1 << endl;
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
                    cout << "download ";
                    if (command == "-ability1")
                    {
                        cout << "to player 1 in position " << j + 1 << endl;
                        p1.addAbility(new Download{&p1, &p2});
                        p1Abilities.emplace_back("Download");
                    }
                    else if (command == "-ability2")
                    {
                        cout << "to player 2 in position " << j + 1 << endl;
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
                    cout << "scan ";
                    if (command == "-ability1")
                    {
                        cout << "to player 1 in position " << j + 1 << endl;
                        p1.addAbility(new Scan{&p1, &p2});
                        p1Abilities.emplace_back("Scan");
                    }
                    else if (command == "-ability2")
                    {
                        cout << "to player 2 in position " << j + 1 << endl;
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
                    cout << "polarize ";
                    if (command == "-ability1")
                    {
                        cout << "to player 1 in position " << j + 1 << endl;
                        p1.addAbility(new Polarize{&p1, &p2});
                        p1Abilities.emplace_back("Polarize");
                    }
                    else if (command == "-ability2")
                    {
                        cout << "to player 2 in position " << j + 1 << endl;
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
                    cout << "teleport ";
                    if (command == "-ability1")
                    {
                        cout << "to player 1 in position " << j + 1 << endl;
                        p1.addAbility(new Teleport{&p1, &p2});
                        p1Abilities.emplace_back("Teleport");
                    }
                    else if (command == "-ability2")
                    {
                        cout << "to player 2 in position " << j + 1 << endl;
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
                    cout << "steal ";
                    if (command == "-ability1")
                    {
                        cout << "to player 1 in position " << j + 1 << endl;
                        p1.addAbility(new Steal{&p1, &p2});
                        p1Abilities.emplace_back("Steal");
                    }
                    else if (command == "-ability2")
                    {
                        cout << "to player 2 in position " << j + 1 << endl;
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
                    cout << "strengthen ";
                    if (command == "-ability1")
                    {
                        cout << "to player 1 in position " << j + 1 << endl;
                        p2.addAbility(new Strengthen{&p1, &p2});
                        p1Abilities.emplace_back("Strenghten");
                    }
                    else if (command == "-ability2")
                    {
                        cout << "to player 2 in position " << j + 1 << endl;
                        p2.addAbility(new Strengthen{&p2, &p1});
                        p2Abilities.emplace_back("Strenghten");
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
                        cout << "Setting player 1's " << which << " to data with strength " << strength << endl;
                        p1.addPiece(to_string(which), new Data{1, Point{j, (j == 3 || j == 4 ? 1 : 0)}, &p1, strength}, players);
                    }
                    else if (command == "-link2")
                    {
                        cout << "Setting player 2's " << which << " to data with strength " << strength << endl;
                        p2.addPiece(to_string(which), new Data{1, Point{j, (j == 3 || j == 4 ? 6 : 7)}, &p2, strength}, players);
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
                        cout << "Setting player 1's " << which << " to virus with strength " << strength << endl;
                        p1.addPiece(to_string(which), new Virus{1, Point{j, (j == 3 || j == 4 ? 1 : 0)}, &p1, strength}, players);
                    }
                    else if (command == "-link2")
                    {
                        cout << "Setting player 2's " << which << " to virus with strength " << strength << endl;
                        p2.addPiece(to_string(which), new Virus{1, Point{j, (j == 3 || j == 4 ? 6 : 7)}, &p2, strength}, players);
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
            cout << "fancy graphics enabled" << endl;
            //g = new GraphicsDisplay{};
        }

        ++i;
    }


    //Default link setup
    if (p1.pieceCount() < 8)
    {
        char which = 'a';
        for (int i = 0; i < 8; i++)
        {
            if (i < 4)
            {
                p1.addPiece(string(1, which + i), new Virus{1, Point{i, (i == 3 || i == 4 ? 1 : 0)}, &p1, i + 1}, players);
            }
            else if (i >= 4)
            {
                p1.addPiece(string(1, which + i), new Data{1, Point{i, (i == 3 || i == 4 ? 1 : 0)}, &p1, (i % 4) + 1}, players);
            }
        }
    }
    if (p2.pieceCount() < 8)
    {
        char which = 'A';
        for (int i = 0; i < 8; i++)
        {
            if (i < 4)
            {
                p2.addPiece(string(1, which + i), new Virus{1, Point{i, (i == 3 || i == 4 ? 6 : 7)}, &p2, i + 1}, players);
            }
            else if (i >= 4)
            {
                p2.addPiece(string(1, which + i), new Data{1, Point{i, (i == 3 || i == 4 ? 6 : 7)}, &p2, (i % 4) + 1}, players);
            }
        }
    }

    //Default abilites
    if (p1.abilityCount() == 0) { //player 1 defaults
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
    if (p2.abilityCount() == 0) { //player 2 defaults
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
    Graphics *g = new TextDisplay{players, p1Abilities, p2Abilities};

    // Create serverports
    p1.addPiece("S1", new Serverport{Point{3, 0}, &p1}, players);
    p1.addPiece("S2", new Serverport{Point{4, 0}, &p1}, players);
    p2.addPiece("S1", new Serverport{Point{3, 7}, &p2}, players);
    p2.addPiece("S2", new Serverport{Point{4, 7}, &p2}, players);

    string command;
    ifstream inFile{};
    string turn = "p1";
    string mode = "cin";

    g->update(p1);

    while (true)
    {

        if (inFile.eof())
            mode = "cin";

        if (mode == "cin")
            cin >> command;
        else if (mode == "sequence")
            inFile >> command;

        if (command == "move")
        {
            string which;
            string direction;
            if (mode == "cin")
            {
                cin >> which;
                cin >> direction;
            }
            else if (mode == "sequence")
            {
                inFile >> which;
                inFile >> direction;
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
            } else {
                cerr << "Invalid direction" << endl;
                continue;
            }

            try
            {
                if (turn == "p1")
                {
                    p1.move(which, d); //check this
                }
                else if (turn == "p2")
                {
                    p2.move(which, d); //check this
                }
            }
            catch (InvalidMove im)
            {
                cout << im.what() << endl;
                continue;
            }

            turn = (turn == "p1") ? "p2" : "p1";
            //cout << "moving " << which << " in direction " << direction << endl;
            if (turn == "p1")
            {
                g->update(p1);
            }
            else if (turn == "p2")
            {
                g->update(p2);
            }
        }
        else if (command == "abilities")
        {
            if (turn == "p1")
            {
                g->printAbilities(p1);
            }
            else if (turn == "p2")
            {
                g->printAbilities(p2);
            }
        }
        else if (command == "ability")
        {
            try
            {
                int abNum = -1;
                if (mode == "cin")
                {
                    cin >> abNum;
                    if (abNum != -1)
                    {
                        if (abNum < 1 || abNum > 5)
                        {
                            cout << "Invalid ability" << endl;
                            continue;
                        }
                        if (turn == "p1")
                        {
                            p1.useAbility(abNum, cin);
                        }
                        else if (turn == "p2")
                        {
                            p2.useAbility(abNum, cin);
                        } 
                    } else {
                        cin.clear();
                        cin.ignore();
                        cerr << "Invalid ability" << endl;
                        continue;
                    }
                }
                else if (mode == "sequence")
                {
                    inFile >> abNum;
                    if (abNum != -1)
                    {
                        if (abNum < 1 || abNum > 5)
                        {
                            cout << "Invalid ability" << endl;
                            continue;
                        }
                        if (turn == "p1")
                        {
                            p1.useAbility(abNum, inFile);
                        }
                        else if (turn == "p2")
                        {
                            p2.useAbility(abNum, inFile);
                        }
                    } else {
                        inFile.clear();
                        inFile.ignore();
                        cerr << "Invalid ability" << endl;
                    }
                }
            }
            catch (InvalidMove im)
            {
                cerr << im.what() << endl;
            }
        }
        else if (command == "board")
        {
            if (turn == "p1")
            {
                g->update(p1);
            }
            else if (turn == "p2")
            {
                g->update(p2);
            }
        }
        else if (command == "sequence")
        {
            if (inFile.is_open())
                inFile.close();
            string file;
            cin >> file;
            inFile.open(file);
            if (!inFile.fail()) {
                mode = "sequence";
            } else {
                cerr << "Invalid file name" << endl;
                continue;
            }
        }
        else if (command == "quit")
        {
            break;
        } else {
            cerr << "Invalid command" << endl;
        }
    }
}
