#include "../header/playerCharacter.h"
#include <iostream>

using namespace std;

const int INVENTORY_CAPACITY = 8;

PlayerCharacter::PlayerCharacter(int health, int attack, int defense, string diff, Weapon* charWeapon) : 
IEntity(health, attack, defense), 
inventory(INVENTORY_CAPACITY), 
inventoryDisplay(inventory),
weapon(charWeapon)            
{
    difficulty = diff;
}

void PlayerCharacter::printStatus(){
    cout << "Current Health: " << getHealth() << endl; 
    cout << "Current Weapon: " << weapon->getName() <<  " (" << weapon->getValue() << " damage)" << endl;
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

Item* PlayerCharacter::getItemFromInventory(std::string& item) {
    return inventory.getItem(item);
}

std::size_t PlayerCharacter::showCurrNumItems() {
    return inventoryDisplay.getNumItems();
}

void Soldier::buffStat(){
    attack += 2;
    std::cout << "\nAttack has been buffed +2\n";
}

void Engineer::buffStat(){
    defense += 1;
    std::cout << "\nDefense has been buffed +1\n";
}

void Biologist::buffStat(){
    health += 20;
    std::cout << "\nHealth has been buffed +20\n";
}