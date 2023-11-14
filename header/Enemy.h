#ifndef ENEMY_H
#define ENEMY_H
#include <random>
//Interface for all enemy modules

class Enemy {
public:
    Enemy(int h, int a, int e):health(h), attack(a), evasion(e) {}
    virtual int dealDamage() = 0;
    virtual void takeDamage(int damage) = 0;
    virtual void printStatus() = 0;
    int getHealth(){return health;}
    int getAttack(){return health;}
    void setHealth(int newHealth){this->health = newHealth;} 
    bool isAlive(int getHealth()){
        if(this-> health <= 0) return false;
        else return true;
    }
    int rng() {
        static std::mt19937 gen(std::random_device rd());
        std::uniform_int_distribution<int> distribution(1, 100);
        return distribution(gen);    
    }


private:
    int health;
    int attack;
    int evasion;

};

//Rat Class, squeak squeak 

class Rat : public Enemy {
public:
    Rat(): Enemy(5, 1, 30) {}
    int dealDamage() override;
    void takeDamage(int damage) override;
    void printStatus() override;
};

//Terrorist enemy, scary :o 

class Terrorist : public Enemy {
public:
    Terrorist: Enemy(20, 15, 10) {}
    int dealDamage() override;
    void takeDamage(int damage) override;
    void printStatus() override;
};

//Crewmate enemy, from friends to foe :(

class Crewmate : public Enemy {
public:
    Crewmate: Enemy(15, 10, 15) {}
    int dealDamage() override;
    void takeDamage(int damage) override;
    void printStatus() override;
};

//Alien enemy, spooky

class Alien : public Enemy {
public:
    Alien: Enemy(10, 20, 5) {}
    int dealDamage() override;
    void takeDamage(int damage) override;
    void printStatus() override;
};

#endif //ENEMY_H