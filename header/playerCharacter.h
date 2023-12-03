#pragma once

#include "Entity.h"
#include "Inventory.h"
#include "Item.h"
#include <iostream>

using namespace std;

class PlayerCharacter : public IEntity{
    private:
        string difficulty;
        InventoryManagement inventory;
        InventoryDisplay inventoryDisplay;
        //Basar -> needs implementation (stub not needed)
    public:
        PlayerCharacter(int health, int attack, int defense, string diff);
        virtual void printStatus();
        virtual const string getDifficulty() { return difficulty; }
        virtual const int getHealth() { return health; }
        virtual const int getAttack() { return attack; }
        virtual const int getDefense() { return defense; }
        void addToInventory(Item* item);
        void removeFromInventory(Item* item);
        bool itemInInventory(Item* item);
        void showInventory();

        virtual ~PlayerCharacter(){}

    friend class battleActions;
};

class Soldier : public PlayerCharacter{ //for all characters they are given default stats
    public:
        Soldier() : PlayerCharacter(120, 7, 5, "Easy"){}
        void buffAttack();
};

class Engineer : public PlayerCharacter{
    public:
        Engineer() : PlayerCharacter(100, 5, 4, "Medium"){}
        void buffDefense();
};

class Biologist : public PlayerCharacter{
    public:
        Biologist() : PlayerCharacter(80, 4, 3, "Hard"){}
        void buffHealth();
};