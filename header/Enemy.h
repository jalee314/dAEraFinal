#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include <random>
//Interface for all enemy modules

class IEnemyDamage {
public:
    virtual int dealDamage() = 0;
    virtual void takeDamage(int damage) = 0;
    virtual ~IEnemyDamage(){}
};


class Enemy: public IEntity ,public IEnemyDamage{
public:
    Enemy(int h, int a, int d, int e, int ac):IEntity(h, a, d), evasion(e), accuracy(a){}
    int getHealth(){return health;}
    int getAttack(){return attack;}
    void setHealth(int newHealth){health = newHealth;} 
    void setEvasion(int newEvasion){evasion = newEvasion;} //function primarily for unit tests, don't think this will change in game
    void setAccuracy(int newAccuracy){accuracy = newAccuracy;} //function primarily for unit tests, don't think this will change in game
    inline bool evadeAttack(){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> chance(1, 100);
        int evadeChance = chance(gen);
        return evadeChance <= evasion; //Random number generator will generate a number between 1-100, if the number 
                                       //is less than or equal to enemy's evasion stat, the enemy will successfully dodge.
    }
    inline bool attackHits() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> chance(1, 100);
        int attackChance = chance(gen);
        return attackChance <= accuracy; //same concept as evadeAttack, but for enemy possibly missing attacks
    }
    inline bool isAlive(){
        return health > 0;
    }
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