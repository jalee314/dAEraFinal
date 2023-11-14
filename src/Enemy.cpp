#include "../header/Enemy.h"
#include <iostream>
#include "RNG.cpp"

int Rat::dealDamage() {
    if(rng() <= 10) {
        std::cout << "Squeak! (The rat tries sinking its teeth into your arm, but it misses). \n";
        return 0;
    }
    std::cout << "Squeak squeak...SQUEAK! (The rat sinks its teeth into your arm).\n" << this->getAttack() << " damage has been taken \n"; 
    //Not sure if the damage taken will be outputted in a different function, could remove everything after the first \n if so.
    return this->attack;
}

void Rat::takeDamage(int damage) {
    std::cout << "Squeak... (The rat looks visibly shaken up).\n";
    int newHealth = this->health - damage;
    setHealth(newHealth);
}

void Rat::printStatus() {
    if(this->getHealth() == 5) {
        std:: cout << "The rat has " << getHealth() << " HP. It looks healthy and ready to destroy you.\n";
    }
    if(this->getHealth() <= 4 && this->getHealth() > 1) {
        std:: cout << "The rat has " << getHealth() << " HP. It's looking a little disheveled.\n";
    }
    if(this->getHealth() == 1) {   
        std:: cout << "The rat has " << getHealth() << " HP. It's definitely on its last legs.\n";
    }
}

int Terrorist::dealDamage() {
    if(rng() <= 10) {
        std::cout << "Take this! (The terrorist swipes his blade, but narrowly misses you).\n";
        return 0;
    }
    std::cout << "DÆRA is ours! (The terrorist slashes his blade, cutting you in the chest). \n" << this->getAttack() << " damage has been taken\n"; 
    //Not sure if the damage taken will be outputted in a different function, could remove everything after the first \n if so.
    return this->attack;
}

void Terrorist::takeDamage(int damage) {
    std::cout << "Ahh! (The terrorist keels over in pain).\n";
    int newHealth = this->health - damage;
    setHealth(newHealth);
}

void Terrorist::printStatus() {
    if(this->getHealth() == 20) {
        std:: cout << "The terrorist has " << getHealth() << " HP. He looks confident that he can beat you.\n";
    }
    if(this->getHealth() <= 19 && this->getHealth() > 4) {
        std:: cout << "The terrorist has " << getHealth() << " HP. He's in visible pain, but he's still motivated to try and stop you.\n";
    }
    if(this->getHealth() <= 4) {   
        std:: cout << "The terrorist has " << getHealth() << " HP. You can see the fear for his life in his eyes.\n";
    }
}

int Crewmate::dealDamage() {
    if(rng() <= 10) {
        std::cout << "Braughhhhgh..... (Your former crewmate tries biting you, but they miss).\n";
        return 0;
    }
    std::cout << "Graughhhhhh... (Your former crewmate lunges and bites your leg). \n" << this->getAttack() << " damage has been taken\n"; 
    //Not sure if the damage taken will be outputted in a different function, could remove everything after the first \n if so.
    return this->attack;
}

void Crewmate::takeDamage(int damage) {
    std::cout << "Mrrghhhhhh... (Your crewmate has no reaction, their nerve endings are toast).\n";
    int newHealth = this->health - damage;
    setHealth(newHealth);
}

void Crewmate::printStatus() {
    if(this->getHealth() == 15) {
        std:: cout << "Your crewmate has " << getHealth() << " HP. They look like a shadow of their former selves.\n";
    }
    if(this->getHealth() <= 14 && this->getHealth() > 5) {
        std:: cout << "Your crewmate has " << getHealth() << " HP. They almost look sane again, but they won't ever be the same.\n";
    }
    if(this->getHealth() <= 4) {   
        std:: cout << "Your crewmate has " << getHealth() << " HP. They want you to end their suffering from this virus.\n";
    }
}

int Alien::dealDamage() {
    if(rng() <= 10) {
        std::cout << "𒁲𒅎𒊑! (The alien tries probing your mind, but your willpower disallows it and the atempt fails).\n";
        return 0;
    }
    std::cout << "𒉽𒈪𒊒! (The alien probes your mind, and attacks your brain from the inside).\n" << this->getAttack() << " damage has been taken\n"; 
    //Not sure if the damage taken will be outputted in a different function, could remove everything after the first \n if so.
    return this->attack;
}

void Alien::takeDamage(int damage) {
    std::cout << "𒍢𒄷𒉌! (The alien looks at you with its buggy eyes in contempt).\n";
    int newHealth = this->health - damage;
    setHealth(newHealth);
}

void Alien::printStatus() {
    if(this->getHealth() == 10) {
        std:: cout << "The alien has " << getHealth() << " HP. It's ready to abduct you and take you onto its UFO.\n";
    }
    if(this->getHealth() <= 10 && this->getHealth() > 3) {
        std:: cout << "The alien has " << getHealth() << " HP. It's confused as to how an inferior life form can fight back.\n";
    }
    if(this->getHealth() <= 3) {   
        std:: cout << "The alien has " << getHealth() << " HP. It's enraged that you are currently beating it.\n";
    }
}
