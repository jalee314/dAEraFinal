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
        std::vector<ItemStub> inventory;
    public:
        void PlayerStub::addItemToInventory(const ItemStub& item){
            inventory.push_back(item);
            std::cout << "You got ";
            item.getItemName();
        }
        void PlayerStub::displayInventory() const{
            if (!inventory.empty()) {
                std::cout << "Your Inventory: ";
                for (const auto& item : inventory) {
                    item.getItemName();
                }
                std::cout << std::endl;
            } else {
                std::cout << "Your inventory is empty." <<std::endl;
            }
        }
};

class Environment {
public:
    Environment(const std::string& description);
    virtual ~Environment();

    virtual void performAction() const = 0;
    void displayDescription() const;

    // Add methods to manage items or interactable things
    void addItem(const ItemStub& item);
    bool takeItem(const ItemStub& item, PlayerStub& player);
    void displayItems() const;

protected:
    std::string description;
    std::vector<ItemStub> items;
};

#endif // ENVIRONMENT_H
