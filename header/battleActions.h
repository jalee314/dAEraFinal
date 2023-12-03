#include <iostream>
#include "playerCharacter.h"
#include "Enemy.h"
#include "Item.h"
#pragma once
using namespace std;

class battleActions{ //friend to playerCharacter class
    public:
        virtual const int attack(EnemyStatus* attackedEnemy, PlayerCharacter* attacker);
        virtual void defend(PlayerCharacter* character, int damage);
        virtual void useItem(HelpItem* item, PlayerCharacter* character);
};