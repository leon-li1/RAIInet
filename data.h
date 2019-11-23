#ifndef DATA_H
#define DATA_H
#include "link.h"

class Data : public Link
{
public:
    void notify(Subject &whoFrom);
};

#endif
