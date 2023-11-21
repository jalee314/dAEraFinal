#include "../header/Inventory.h"
#include <iostream>
#include <algorithm>
//Shoutout Mario for making an inventoryStub for his environment class, lot of inspiration taken from him

void InventoryManagement::addItem(ItemStub &item) {
    if(backpack.size() < carryCap) {
        backpack.push_back(item);
    }
    else {
        std::cout << "Your backpack is full. Throw something out and try again.\n";
    }
}

void InventoryManagement::removeItem(ItemStub &itemRemove) {
    std::vector<ItemStub>::iterator item;
    item = std::find_if(backpack.begin(), backpack.end(), 
    [&itemRemove](const ItemStub &itemToRemove) {
        return itemRemove.getName() == itemToRemove.getName();
    });
    if(item !=backpack.end()) {
        backpack.erase(item);
        itemRemove.useItem();
        std::cout << item->getName() << " has been removed from the inventory.\n";
    }
    else std::cout << itemRemove.getName() << " was not found in the inventory.\n"
}

void InventoryDisplay::displayInventory() {
    std::vector<ItemStub>::iterator item;
    const std::vector<ItemStub>& backpack = inventory.getBackpack();
    if(!inventory.empty()){
        std::cout << "Inventory: "
        for(item = backpack.begin(); item != backpack.end(); ++item) {
            std::cout << item->getName();
            if(std::next(item) != backpack.end()) {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }
    else std::cout << "Nothing here...\n";
}

std::size_t InventoryDisplay::getNumItems() {
    const std::vector<ItemStub>& backpack = inventory.getBackpack();
    return backpack.size();
}

