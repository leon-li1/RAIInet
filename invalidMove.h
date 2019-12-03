#ifndef INVALIDMOVE_H
#define INVALIDMOVE_H
#include <string>

class InvalidMove
{
    std::string err;

public:
    InvalidMove(std::string what);
    std::string what();
};

#endif
