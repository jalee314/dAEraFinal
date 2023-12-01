#include <iostream>
#pragma once
using namespace std;

class EnemyStub{
    private:
        int attack;
        int evasion; 

    public:
        EnemyStub(int num, int num2): attack(num), evasion(num2){};

        int getEvasion() {return evasion;}
};


class PlayerCharacterStub{
    private:
        int health = 5;
        int attack;
        int defense;
        int weaponDmg;

    public:
        PlayerCharacterStub(int num, int num2, int num3): attack(num), defense(num2), weaponDmg(num3){};
        int getHealth() { return health; }
        int getAttack() { return attack; }
        int getDefense() { return defense; }
    
    friend class battleActions;
};


class HelpItemStub{
    private:
        int assistance;
        string give;

    public:
        HelpItemStub(int assist, string part) : assistance(assist), give(part) {};
        int getAssistance() { return assistance; }
        string type() { return give; }
};


class battleActions{ //friend to playerCharacter class
    public:
        virtual const int attack(EnemyStub*, PlayerCharacterStub*);
        virtual void defend(PlayerCharacterStub*, int damage);
        virtual void useItem(HelpItemStub, PlayerCharacterStub*);
};

