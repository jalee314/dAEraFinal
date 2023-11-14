#include "../header/Enemy.h"
#include <iostream>

int Rat::dealDamage() {
    std::cout << "Squeak squeak...SQUEAK (The rat sinks it's teeth into your arm)\n";
    return this->attack;
}

void Rat::takeDamage(int damage) {
    std::cout << "Squeak... (The rat looks visibly shaken up)\n";
    int newHealth = this->health - damage;
    setHealth(newHealth);
}



