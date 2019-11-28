#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <string>

class Point;
class Observer;
class Player;

class Subject
{
    std::vector<Observer *> observers;

public:
    void attach(Observer *o);
    void detach(Observer *o);
    void notifyObservers();
    virtual ~Subject() = 0;
    virtual Point getPos() = 0;
    virtual Player *getOwner() = 0;
    virtual int getStrength() = 0;
    virtual std::string getInfo() = 0;
};

#endif
