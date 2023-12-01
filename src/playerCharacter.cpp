#include "../header/playerCharacter.h"
#include <iostream>

using namespace std;

PlayerCharacter::PlayerCharacter(int health, int attack, int defense, string diff) : IEntity(health, attack, defense) {
    difficulty = diff;
}

void PlayerCharacter::printStatus(){
    cout << "Current Health: " << getHealth() << endl; 
    cout << "Current Weapon: " << "----" << endl;
}


void Soldier::buffAttack(){
    attack += 2;
}

void Engineer::buffDefense(){
    defense += 1;
}

void Biologist::buffHealth(){
    health += 20;
}