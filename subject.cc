#include "subject.h"
#include "observer.h"

void Subject::attach(Observer *o)
{
    observers.emplace_back(o);
}

void Subject::detach(Observer *o)
{
    for (int i = 0; i < (int)observers.size(); ++i)
    {
        if (observers[i] == o)
            observers.erase(observers.begin() + i);
    }
}

void Subject::notifyObservers()
{
    int i = 0;
    for (auto &ob : observers) {
        if (ob) {
            ob->notify(*this);
        }
        i++;
    }
}

Subject::~Subject() {}
