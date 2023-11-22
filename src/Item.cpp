#include "../header/Item.h"
#include <iostream>

int HelpItem::useItem() {
    std::cout << "You use the " << name << ".\n"; //This might be violated kinda badly based on the item
    return assistance;
}

void HelpItem::printItem() {
    std::cout << "Item: " << name << ", Assistance: " << assistance << "\n";
}

int Weapon::useItem() {
    std::cout << "You use the " << name << ".\n";
    return damage;
}

void Weapon::printItem() {
    std::cout << "Weapon: " << name << ", Damage: " << damage << "\n";
}