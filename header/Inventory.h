#ifndef INVENTORY_H 
#define INVENTORY_H
#include <vector>
#include <string>
#include <iostream>
#include "Item.h"

class IAdjustInventory {
public:
    virtual void addItem(Item* item) = 0;
    virtual void removeItem(Item* item) = 0;
    virtual bool hasItem(Item* itemToFind) = 0;
    virtual ~IAdjustInventory(){}
};

class IDisplayInventory {
public:
    virtual void displayInventory() = 0;
    virtual std::size_t getNumItems() = 0;
    virtual ~IDisplayInventory(){}
};

class InventoryManagement: public IAdjustInventory{
public:
    InventoryManagement(int cap): carryCap(cap){}
    virtual void addItem(Item* item);
    virtual void removeItem(Item* item);
    virtual bool hasItem(Item* itemToFind);
    const std::vector<Item*>& getBackpack() const {return backpack;}
private:
    std::vector<Item*> backpack; 
    int carryCap;
};

class InventoryDisplay: public IDisplayInventory {
public: 
    InventoryDisplay(InventoryManagement& userInventory): inventory(userInventory){}
    virtual void displayInventory();
    virtual std::size_t getNumItems();
private:
    InventoryManagement& inventory;
};

#endif //INVENTORY_H