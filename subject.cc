#include "subject .h"

void Subject::attach(Observer *o)
{
    observers.emplace_back(o);
}

void Subject::detach(Observer *o)
{
    for (auto &ob : observers)
    {
        if (ob == o)
            observers.erase(ob);
    }
}

void Subject::notifyObservers()
{
    for (auto &ob : observers)
        ob->notify(*this);
}
