#include "invalidMove.h"
#include <string>

InvalidMove::InvalidMove(std::string what) : err{what} {}

std::string InvalidMove::what()
{
  return err;
}
