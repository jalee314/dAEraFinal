#include "battleActions.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

const int battleActions::attack(EnemyStub attackedEnemy, PlayerCharacterStub attacker){ 
    srand(time(NULL));

    if((rand() % 25) <= attackedEnemy.getEvasion()){ //chance of hitting
        int totalDamage = 0;

        if(attacker.weaponDmg == 0){
            totalDamage = attacker.attack;
        }
        else{
            int addedWeaponDmg = (rand() % attacker.weaponDmg) + 1;
            totalDamage = addedWeaponDmg + attacker.attack;
        }


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


void battleActions::useItem(HelpItemStub item, PlayerCharacterStub& character){ //for now does perma buffs
    if(item.type() == "health"){
        character.health = character.health + item.getAssistance();
    }
    else if(item.type() == "defense"){
        character.defense = character.defense + item.getAssistance();
    }
    else{
        character.attack = character.attack + item.getAssistance();
    }
}


/*
Damage to player character is done by doing srand % (baseAttack/#) and adding the highest modifier 
to the baseAttack which is the damage, the players defenses are then subtracted from the attack to 
see how much health is lost; bigger monsters have more chances to do big damage but the lil rats for 
example only have one shot at it (the # is the bit from the base Attack to modulo to (S)
*/