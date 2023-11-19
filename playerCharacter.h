#pragma once

#include "header/Entity.h"
#include <iostream>

using namespace std;

class PlayerCharacter : public IEntity{
    private:
        string difficulty;
        //Basar -> needs implementation (stub not needed)
        //Inventory -> needs implementation (stub not needed)
    public:
        PlayerCharacter(int, int, int, string); //IEntity, h, a, d
        virtual void printStatus();
        virtual int getHealth() { return health; }
        virtual int getAttack() { return attack; }
        virtual int getDefense() { return defense; }

    friend class battleActions;
};

class Soldier : public PlayerCharacter{ //for all characters, ONLY pass in the health, attack, and defense
    private:
        void buffAttack();
    public:
        Soldier(int health, int attack, int defense, string diff = "Easy") : PlayerCharacter(health, attack, defense, diff){}
};

class Engineer : public PlayerCharacter{
    private:
        void buffDefense();
    public:
        Engineer(int health, int attack, int defense, string diff = "Medium") : PlayerCharacter(health, attack, defense, diff){}
};

class Biologist : public PlayerCharacter{
    private:
        void buffHealth();
    public:
        Biologist(int health, int attack, int defense, string diff = "Hard") : PlayerCharacter(health, attack, defense, diff){}
};