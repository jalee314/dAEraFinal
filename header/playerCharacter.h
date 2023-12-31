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
        Item* weapon;
    public:
        PlayerCharacter(int health, int attack, int defense, string diff, Weapon* charWeapon);
        virtual void printStatus();
        virtual const string getDifficulty() { return difficulty; }
        virtual const int getHealth() { return health; }
        virtual const int getAttack() { return attack; }
        virtual const int getDefense() { return defense; }
        virtual void buffStat() = 0;
        void setAttack(Item* weapon) {attack = weapon->getValue();} //switching weapon
        Item* getWeapon() {return weapon;}
        void setWeapon(Item* newWeapon) {weapon = newWeapon;} 
        void addToInventory(Item* item);
        void removeFromInventory(Item* item);
        bool itemInInventory(const std::string& item);
        Item* getItemFromInventory(std::string& item);
        void showInventory();
        std::size_t showCurrNumItems();

        virtual ~PlayerCharacter(){}

    friend class battleActions;
};

class Soldier : public PlayerCharacter{ //for all characters they are given default stats
    public:
        Soldier(Weapon* weapon) : PlayerCharacter(120, 7, 5, "Easy", weapon){}
        virtual void buffStat();
};

class Engineer : public PlayerCharacter{
    public:
        Engineer(Weapon* weapon) : PlayerCharacter(100, 5, 4, "Medium", weapon){}
        virtual void buffStat();
};

class Biologist : public PlayerCharacter{
    public:
        Biologist(Weapon* weapon) : PlayerCharacter(80, 4, 3, "Hard", weapon){}
        virtual void buffStat();
};