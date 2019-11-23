#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>

class Observer;

class Subject
{
    std::vector<Observer *> observers;

public:
    void attach(Observer *o);
    void dettach(Observer *o);
    void notifyObservers();
};

#endif