#include "download.h"
#include "player.h"

Download::Download(Player *owner, Player *other) : Ability{owner, other} {}

void Download::use() {}
