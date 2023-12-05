// Environment.h
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <iostream>
#include <string>
#include <vector>
#include "Inventory.h"
#include "Item.h"

class Environment {

protected:
    std::string description;
    std::vector<Item*> items;

public:
    Environment(const std::string& description);
    virtual ~Environment();

    void displayDescription() const;

    void addItem(Item* item);
    bool takeItem(Item* item, InventoryManagement& player);
    void displayItems() const;
    size_t getNumberItems() const;
};

/*
class ItemStub{
    private:
        std::string itemName; 

    public:
        ItemStub(std::string n): itemName(n){};

        void getItemName() const {
            std::cout << itemName << std::endl;
        }
    // Added equality operator
    bool operator==(const ItemStub& other) const {
        return itemName == other.itemName;
    }
};

class PlayerStub{
    private:
        std::vector<ItemStub*> inventory;
    public:
        void addItemToInventory(ItemStub* item) {
            inventory.push_back(item);
            std::cout << "You got ";
            item->getItemName();
        }
        void displayInventory() const{
            if (!inventory.empty()) {
                std::cout << "Your inventory: ";
                for (const auto& item : inventory) {
                    item->getItemName();
                }
            } else {
                std::cout << "Your inventory is empty." <<std::endl;
            }
        }
        size_t getInventorySize() const {
            return inventory.size();
        }
};
*/

#endif // ENVIRONMENT_H
