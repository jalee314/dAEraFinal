#ifndef INVENTORY_H 
#define INVENTORY_H
#include <vector>
#include <string>
#include <iostream>

class ItemStub {
public:
    int getAssistance(){return assistance;}
    void useItem() {std::cout << getName() << " has been used!\n"; }
    const std::string getName const(){return name};
private:
    int assistance;
    std::string name;
};

class IAdjustInventory {
    virtual void addItem(ItemStub &item) = 0;
    virtual void removeItem(ItemStub &item) = 0;
    virtual ~IAdjustInventory();
};

class IDisplayInventory {
    virtual void displayInventory() = 0;
    virtual std::size_t getNumItems() = 0;
    virtual ~IDisplayInventory();
};

class InventoryManagement: public IAdjustInventory{
public:
    InventoryManagement(int cap): carryCap(cap){}
    virtual void addItem(ItemStub &item);
    virtual void removeItem(ItemStub &itemRemove);
    const std::vector<ItemStub>& getBackpack() const {return backpack;}
private:
    std::vector<ItemStub> backpack; 
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
