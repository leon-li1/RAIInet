#include "ability.h"

Ability::Ability(Player* owner, Player* other) : owner{owner}, other{other} {}

Ability::~Ability() {}
