#include "../header/playerCharacter.h"
#include <iostream>

using namespace std;

const int INVENTORY_CAPACITY = 8;

PlayerCharacter::PlayerCharacter(int health, int attack, int defense, string diff) : 
IEntity(health, attack, defense), 
inventory(INVENTORY_CAPACITY), 
inventoryDisplay(inventory){
    difficulty = diff;
}

void PlayerCharacter::printStatus(){
    cout << "Current Health: " << getHealth() << endl; 
    cout << "Current Weapon: " << "----" << endl;
}

void PlayerCharacter::addToInventory(Item* item) {
    inventory.addItem(item);
}

void PlayerCharacter::removeFromInventory(Item* item) {
    inventory.removeItem(item);
}

bool PlayerCharacter::itemInInventory(const std::string& item) {
    return inventory.hasItem(item);
}   

void PlayerCharacter::showInventory() {
    inventoryDisplay.displayInventory();
}

Item* PlayerCharacter::getItemFromInventory(const std::string& item) {
    return inventory.getItem(item);
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