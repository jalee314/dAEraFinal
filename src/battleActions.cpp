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
        std::cout << "Item not in inventory." << std::endl;
        return;
    }

    HelpItem* helpItem = dynamic_cast<HelpItem*>(item);

    if(helpItem != nullptr) {
        if(helpItem->getType() == "health") { //checks what type of buff to give
            character->health = character->health + helpItem->getAssistance();
        }
        else if(helpItem->getType() == "defense"){
            character->defense = character->defense + helpItem->getAssistance();
        }
        else {
            character->attack = character->attack + helpItem->getAssistance();
        }
        std::cout << "You use the " << helpItem->getName() << ". It gives you +" << helpItem->getAssistance() << " " << helpItem->getType() << ".\n";
        character->inventory.removeItem(item);
    }
    else {
        std::cout << "Invalid item for this function.\n\n";
    }
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