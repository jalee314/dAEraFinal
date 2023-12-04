#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include <random>
//Interface for all enemy modules

class IEnemyState{ //interface for the state of the enemy
public:
    virtual int getHealth() = 0;
    virtual int getAttack() = 0;
    virtual int getEvasion() = 0;
    virtual int getAccuracy() = 0;
    virtual void setHealth(int newHealth) = 0;
    virtual void setEvasion(int newEvasion) = 0; //function primarily for unit tests, don't think this will change in game
    virtual void setAccuracy(int newAccuracy) = 0; //function primarily for unit tests, don't think this will change in game
    virtual ~IEnemyState(){}
};

class IEnemyCombatChance { //interface for combat chance actions
public:
    virtual bool evadeAttack() = 0;
    virtual bool attackHits() = 0;
    virtual ~IEnemyCombatChance(){}
};

class IEnemyDamagePrompts { //interface for combat damage
public:
    virtual int dealDamage() = 0;
    virtual void takeDamage(int damage) = 0;
    virtual ~IEnemyDamagePrompts(){}
};


class EnemyStatus: public IEntity, public IEnemyState{
public:
    EnemyStatus(int healthValue, int attackValue, int defenseValue, int evasionValue, int accuracyValue) :
    IEntity(healthValue, attackValue, defenseValue), evasion(evasionValue), accuracy(accuracyValue){}

    virtual int getHealth(){return health;}
    virtual int getAttack(){return attack;}
    virtual int getEvasion(){return evasion;}
    virtual int getAccuracy(){return accuracy;}
    virtual void setHealth(int newHealth){health = newHealth;}
    virtual void setEvasion(int newEvasion){evasion = newEvasion;}
    virtual void setAccuracy(int newAccuracy){accuracy = newAccuracy;}

private:
    int evasion;
    int accuracy;
};

class EnemyBattle: public IEnemyCombatChance{
public:
    EnemyBattle(EnemyStatus& status): enemyStatus(status){}
    virtual bool evadeAttack();
    virtual bool attackHits();
   
private: 
    EnemyStatus& enemyStatus;
};

class Rat : public EnemyStatus, public IEnemyDamagePrompts {
public:
    Rat(): EnemyStatus(5, 6, 0, 30, 60), enemyBattle(*this) {}
    virtual int dealDamage();
    virtual void takeDamage(int damage);
    virtual void printStatus();
private:
    EnemyBattle enemyBattle;
};

//Terrorist enemy

class Terrorist : public EnemyStatus, public IEnemyDamagePrompts {
public:
    Terrorist(): EnemyStatus(20, 13, 2, 10, 90), enemyBattle(*this) {}
    virtual int dealDamage();
    virtual void takeDamage(int damage);
    virtual void printStatus();
private:
    EnemyBattle enemyBattle;
};

//Crewmate enemy

class Crewmate : public EnemyStatus, public IEnemyDamagePrompts {
public:
    Crewmate(): EnemyStatus(15, 11, 1, 15, 70), enemyBattle(*this) {}
    virtual int dealDamage();
    virtual void takeDamage(int damage);
    virtual void printStatus();
private:
    EnemyBattle enemyBattle;
};

//Alien enemy

class Alien : public EnemyStatus, public IEnemyDamagePrompts {
public:
    Alien(): EnemyStatus(20, 15, 3, 20, 85), enemyBattle(*this)  {}
    virtual int dealDamage();
    virtual void takeDamage(int damage);
    virtual void printStatus();
private:
    EnemyBattle enemyBattle;
};

//IMPORTANT, current Health, Attack, and Evasion values are just temporary stats chosen at my liking, will  
//figure out actual stats in a bit

#endif //ENEMY_H