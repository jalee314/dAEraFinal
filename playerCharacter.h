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
        virtual const string getDifficulty() { return difficulty; }
        virtual const int getHealth() { return health; }
        virtual const int getAttack() { return attack; }
        virtual const int getDefense() { return defense; }

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
        Biologist() : PlayerCharacter(80, 3, 3, "Hard"){}
        void buffHealth();
};