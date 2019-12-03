#include "subject.h"
#include "observer.h"
#include "invalidMove.h"

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
    for (auto &ob : observers)
    {
        if (ob)
        {
            try
            {
                ob->notify(*this);
            }
            catch (InvalidMove)
            {
                return;
            }
        }
    }
}

Subject::~Subject() {}
