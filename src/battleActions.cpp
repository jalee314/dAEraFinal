#include "../header/battleActions.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

const int battleActions::attack(EnemyStatus* attackedEnemy, PlayerCharacter* attacker){//returns damage to be done
    srand(time(NULL));

        int totalDamage = attacker->attack;

        if(totalDamage <= 0){
            totalDamage = 1;
        }

        if((rand() %  100) + 1 <= 7){ //crit chance
            totalDamage *= 2;
        }
        return totalDamage;
}


void battleActions::useItem(Item* item, PlayerCharacter* character){ //for now does perma buffs
    if(!character->itemInInventory(item->getName())) {
        std::cout << "\n\nItem not in inventory.\n\n" << std::endl;
        return;
    }
        if(item->getType() == "health") { //checks what type of buff to give
            character->health = character->health + item->getValue();
        }
        else if(item->getType() == "defense"){
            character->defense = character->defense + item->getValue();
        }
        else if(item->getType() == "defense"){
            character->attack = character->attack + item->getValue();
        }
        else if(item->getType() == "weapon"){
            std::cout << "\n\nThis is a weapon, I can't use this item, I can only equip it...\n\n";
            return;
        }
        else if(item->getType() == "wincon") { //wincon = win condition for keycard
            std::cout << "\n\nYou're gonna need this to escape, I'd think twice before leaving it behind...\n\n";
            return;
        }
        std::cout << "\n\nYou use the " << item->getName() << ". It gives you +" << item->getValue() << " " << item->getType() << ".\n\n";
        character->inventory.removeItem(item);
}

void battleActions::defend(PlayerCharacter* character, int damage){ //deals damage to characters

    if(damage <= 0){
        return;
    }
    else {
        int netDamage = damage - character->defense;
        if(netDamage > 0) {
            character->health -= netDamage;
        }
    }
}