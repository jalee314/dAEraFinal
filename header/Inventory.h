#ifndef INVENTORY_H 
#define INVENTORY_H
#include <vector>
#include <string>
#include <iostream>

class ItemStub {
public:
    ItemStub(std::string itemName): name(itemName){}
    std::string getName() const {return name;}
private:
    std::string name;
};

class IAdjustInventory {
public:
    virtual void addItem(ItemStub &item) = 0;
    virtual void removeItem(ItemStub &item) = 0;
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

#endif //INVENTORY_H