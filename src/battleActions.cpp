#include "../header/battleActions.h"
#include "../header/Enemy.h"
#include "../header/playerCharacter.h"
#include "../header/Item.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

const int battleActions::attack(EnemyStatus* attackedEnemy, PlayerCharacter* attacker){//returns damage to be done
    srand(time(NULL));

    if((rand() % 25) <= attackedEnemy->getEvasion()){ //chance of hitting
        int totalDamage = 0;

        totalDamage = attacker->attack;


        if(totalDamage <= 0){
            totalDamage = 1;
        }

        if((rand() %  100) + 1 <= 7){ //crit chance
            totalDamage *= 2;
        }

        return totalDamage;
    }
    else{
        return 0;
    }
}


void battleActions::useItem(HelpItem item, PlayerCharacter* character){ //for now does perma buffs
    if(item.type() == "health"){ //checks what type of buff to give
        character->health = character->health + item.getAssistance();
    }
    else if(item.type() == "defense"){
        character->defense = character->defense + item.getAssistance();
    }
    else{
        character->attack = character->attack + item.getAssistance();
    }
}


void battleActions::defend(PlayerCharacter* character, int damage){ //deals damage to characters

    if(damage < 0){ //if damage is negative then it switches the sign (dmg cannot be negative)
        character->health = character->health + (character->defense + damage);
    }
    else if(damage > 0){
        character->health = character->health + (character->defense - damage);
    }
}