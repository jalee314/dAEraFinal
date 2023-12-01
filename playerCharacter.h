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

class Soldier : public PlayerCharacter{ //for all characters they are given default stats
    private:
        void buffAttack();
    public:
        Soldier() : PlayerCharacter(120, 7, 5, "Easy"){}
};

class Engineer : public PlayerCharacter{
    private:
        void buffDefense();
    public:
        Engineer() : PlayerCharacter(100, 5, 4, "Medium"){}
};

class Biologist : public PlayerCharacter{
    private:
        void buffHealth();
    public:
        Biologist() : PlayerCharacter(80, 3, 3, "Hard"){}
};