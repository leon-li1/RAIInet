#include "firewallAbility.h"

FirewallAbility::FirewallAbility(Player* owner, Player* other) : Ability{owner, other} {}

void FirewallAbility::use(istream& in) override {
    
    Point p;
    in >> p;
    vector<Player> players { owner, other};
    owner->addPiece("firewall", new Firewall(p, owner), players);

}