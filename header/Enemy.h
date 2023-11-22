#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include <random>
//Interface for all enemy modules

class IEnemyState { //interface for the state of the enemy
public:
    virtual int getAttack() = 0;
    virtual int getHealth() = 0;
    virtual void setHealth(int newHealth) = 0;
    virtual void setEvasion(int newEvasion) = 0;
    virtual void setAccuracy(int newAccuracy) = 0;
    virtual void printStatus() = 0;
    virtual ~IEnemyState(){}
};

class IEnemyCombatActions { //interface for combat actions
public:
    virtual int dealDamage() = 0;
    virtual void takeDamage(int damage) = 0;
    virtual bool evadeAttack() = 0;
    virtual bool attackHits() = 0;
    virtual bool isAlive() = 0;
    virtual ~IEnemyCombatActions(){}
};

class Enemy: public IEntity ,public IEnemyState, public IEnemyCombatActions{
public:
    Enemy(int healthValue, int attackValue, int defenseValue, int evasionValue, int accuracyValue):
    IEntity(healthValue, attackValue, defenseValue), evasion(evasionValue), accuracy(accuracyValue){}
    virtual int getHealth(){return health;}
    virtual int getAttack(){return attack;}
    virtual void setHealth(int newHealth){health = newHealth;} 
    virtual void setEvasion(int newEvasion){evasion = newEvasion;} //function primarily for unit tests, don't think this will change in game
    virtual void setAccuracy(int newAccuracy){accuracy = newAccuracy;} //function primarily for unit tests, don't think this will change in game
    virtual bool isAlive(){return health > 0;}
    virtual bool evadeAttack();
    virtual bool attackHits();
   
private: 
    int evasion;
    int accuracy;    
};

class Rat : public Enemy {
public:
    Rat(): Enemy(5, 1, 0, 30, 60) {}
    virtual int dealDamage();
    virtual void takeDamage(int damage);
    virtual void printStatus();
};

//Terrorist enemy

class Terrorist : public Enemy {
public:
    Terrorist(): Enemy(20, 8, 3, 10, 90) {}
    virtual int dealDamage();
    virtual void takeDamage(int damage);
    virtual void printStatus();
};

//Crewmate enemy

class Crewmate : public Enemy {
public:
    Crewmate(): Enemy(15, 5, 2, 15, 70) {}
    virtual int dealDamage();
    virtual void takeDamage(int damage);
    virtual void printStatus();
};

//Alien enemy

class Alien : public Enemy {
public:
    Alien(): Enemy(10, 10, 4, 20, 85) {}
    virtual int dealDamage();
    virtual void takeDamage(int damage);
    virtual void printStatus();
};

//IMPORTANT, current Health, Attack, and Evasion values are just temporary stats chosen at my liking, will  
//figure out actual stats in a bit

#endif //ENEMY_H