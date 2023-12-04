#include "../header/Enemy.h"
#include <iostream>

bool EnemyBattle::evadeAttack() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> chance(1, 100);
    int evadeChance = chance(gen);
    return evadeChance <= enemyStatus.getEvasion(); //Random number generator will generate a number between 1-100, if the number 
                                   //is less than or equal to enemy's evasion stat, the enemy will successfully dodge.
}

bool EnemyBattle::attackHits() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> chance(1, 100);
    int attackChance = chance(gen);
    return attackChance <= enemyStatus.getAccuracy(); //same concept as evadeAttack, but for enemy possibly missing attacks
}

int Rat::dealDamage() {
    if(!enemyBattle.attackHits()) {
        std::cout << "Squeak! (The rat tries sinking its teeth into your arm, but it misses). \n";
        return 0;
    }
    std::cout << "Squeak squeak...SQUEAK! (The rat sinks its teeth into your arm).\n"; 
    //Not sure if the damage taken will be outputted in a different function, could remove everything after the first \n if so.
    return attack;
}

void Rat::takeDamage(int damage) {
    if(enemyBattle.evadeAttack()) {
        std::cout << "Squeak! (The rat does a flip, and you miss your attack).\n";
        return;
    }   
    int netDamage = damage - defense;
    if(netDamage < 0) netDamage = 0;
    int newHealth = health - netDamage;
    setHealth(newHealth);
    if(!isAlive()) std::cout << "Squeak... (The rat falls on its back as the life in its eyes fades away).\n";
    else std::cout << "Squeak... (The rat looks visibly shaken up).\n";
}

void Rat::printStatus() {
    if(getHealth() == 5) {
        std:: cout << "The rat has " << getHealth() << " HP. It looks healthy and ready to destroy you.\n";
    }
    if(getHealth() <= 4 && getHealth() > 1) {
        std:: cout << "The rat has " << getHealth() << " HP. It's looking a little disheveled.\n";
    }
    if(getHealth() == 1) {   
        std:: cout << "The rat has " << getHealth() << " HP. It's definitely on its last legs.\n";
    }
}

int Terrorist::dealDamage() {
    if(!enemyBattle.attackHits()) {
        std::cout << "Take this! (The terrorist swipes his blade, but narrowly misses you).\n";
        return 0;
    }
    std::cout << "DÆRA is ours! (The terrorist slashes his blade, cutting you in the chest). \n"; 
    //Not sure if the damage taken will be outputted in a different function, could remove everything after the first \n if so.
    return attack;
}

void Terrorist::takeDamage(int damage) {
    if(enemyBattle.evadeAttack()) {
        std::cout << "Too slow! (The terrorist sidesteps, and you miss your attack).\n";
        return;
    }
    int netDamage = damage - defense;
    if(netDamage < 0) netDamage = 0;
    int newHealth = health - netDamage;
    setHealth(newHealth);
    if(!isAlive()) std::cout << "My mission...This can't be! (The terrorist kneels as the life fades from his eyes).\n";
    else std::cout << "Ahh! (The terrorist keels over in pain).\n";
}

void Terrorist::printStatus() {
    if(getHealth() == 20) {
        std:: cout << "The terrorist has " << getHealth() << " HP. He looks confident that he can beat you.\n";
    }
    if(getHealth() <= 19 && getHealth() > 4) {
        std:: cout << "The terrorist has " << getHealth() << " HP. He's in visible pain, but he's still motivated to try and stop you.\n";
    }
    if(getHealth() <= 4) {   
        std:: cout << "The terrorist has " << getHealth() << " HP. You can see the fear for his life in his eyes.\n";
    }
}

int Crewmate::dealDamage() {
    if(!enemyBattle.attackHits()) {
        std::cout << "Braughhhhgh..... (Your former crewmate tries biting you, but they miss).\n";
        return 0;
    }
    std::cout << "Graughhhhhh... (Your former crewmate lunges and bites your leg). \n"; 
    //Not sure if the damage taken will be outputted in a different function, could remove everything after the first \n if so.
    return attack;
}

void Crewmate::takeDamage(int damage) {
    if(enemyBattle.evadeAttack()) {
        std::cout << "Grghhhhh... (The terrorist sidesteps, and you miss your attack).\n";
        return;
    }
    int netDamage = damage - defense;
    if(netDamage < 0) netDamage = 0;
    int newHealth = health - netDamage;
    setHealth(newHealth);
    if(!isAlive()) std::cout << "Brghhhhhh... (Your crewmate collapses, thankful to be free from the virus' pain).\n";
    else std::cout << "Mrrghhhhhh... (Your crewmate has no reaction, their nerve endings are toast).\n";
}

void Crewmate::printStatus() {
    if(getHealth() == 15) {
        std:: cout << "Your crewmate has " << getHealth() << " HP. They look like a shadow of their former selves.\n";
    }
    if(getHealth() <= 14 && getHealth() > 5) {
        std:: cout << "Your crewmate has " << getHealth() << " HP. They almost look sane again, but they won't ever be the same.\n";
    }
    if(getHealth() <= 4) {   
        std:: cout << "Your crewmate has " << getHealth() << " HP. They want you to end their suffering from this virus.\n";
    }
}

int Alien::dealDamage() {
    if(!enemyBattle.attackHits()) {
        std::cout << "𒁲𒅎𒊑! (The alien tries probing your mind, but your willpower disallows it and the attempt fails).\n";
        return 0;
    }
    std::cout << "𒉽𒈪𒊒! (The alien probes your mind, and attacks your brain from the inside).\n"; 
    return attack;
}

void Alien::takeDamage(int damage) {
    if(enemyBattle.evadeAttack()) {
        std::cout << "𒆤𒄯𒊩! (The alien levitates, and you miss your attack).\n";
        return;
    }
    int netDamage = damage - defense;
    if(netDamage < 0) netDamage = 0;
    int newHealth = health - netDamage;
    setHealth(newHealth);
    if(!isAlive()) std::cout << "𒋻𒀭𒈾! (The alien's body starts disengrating into dust. That was weird).\n";
    else std::cout << "𒍢𒄷𒉌! (The alien looks at you with its buggy eyes in contempt).\n";
}

void Alien::printStatus() {
    if(getHealth() == 20) {
        std:: cout << "The alien has " << getHealth() << " HP. It's ready to abduct you and take you onto its UFO.\n";
    }
    if(getHealth() <= 19 && getHealth() > 8) {
        std:: cout << "The alien has " << getHealth() << " HP. It's confused as to how an inferior life form can fight back.\n";
    }
    if(getHealth() <= 8) {   
        std:: cout << "The alien has " << getHealth() << " HP. It's enraged that you are currently beating it.\n";
    }
}