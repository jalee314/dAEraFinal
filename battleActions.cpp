#include "battleActions.h"
#include <stdlib.h>
#include <time.h>

int battleActions::attack(EnemyStub attackedEnemy){ 
    srand(time);
    if((rand() % 25) <= attackedEnemy.getEvasion()){
        int addedWeaponDmg = (rand() % this->weaponDmg);
        int totalDamage = addedWeaponDmg + this->attack;

        if((rand() %  100) + 1 <= 7){
            totalDamage *= 2;
        }

        return totalDamage;
    }
    else{
        return 0;
    }
}

    // int battleActions::defend(){

    // }

    // void battleActions::useItem(){


    // }
/*
Damage to player character is done by doing srand % (baseAttack/#) and adding the highest modifier 
to the baseAttack which is the damage, the players defenses are then subtracted from the attack to 
see how much health is lost; bigger monsters have more chances to do big damage but the lil rats for 
example only have one shot at it (the # is the bit from the base Attack to modulo to (S)
*/

/*
class PlayerCharacterStub{
    private:
        int attack;
        int defense;
        int weaponDmg;

    public:
    
    friend class battleActions;
};


class EnemyStub{
    private:
        int attack;
        int evasion; 

    public:
        int getEvasion() {return evasion;}
        int dealDamage();
};
*/