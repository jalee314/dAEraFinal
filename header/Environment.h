// Environment.h
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <iostream>
#include <string>
#include <vector>

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

class Environment {
public:
    Environment(const std::string& description);
    virtual ~Environment();

    void displayDescription() const;

    // Add methods to manage items or interactable things
    void addItem(ItemStub* item);
    bool takeItem(ItemStub* item, PlayerStub& player);
    void displayItems() const;
    size_t getNumberItems() const;

protected:
    std::string description;
    std::vector<ItemStub*> items;
};

#endif // ENVIRONMENT_H
