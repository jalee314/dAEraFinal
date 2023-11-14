#ifndef ENEMY_H
#define ENEMY_H
//Interface for all enemy modules

class IEnemyDealDamage {
    virtual int dealDamage() = 0;
};

class IEnemyTakeDamage {
    virtual void takeDamage(int damage) = 0;
};

class IEnemyStatus {
    virtual void printStatus() = 0;
};

class Enemy: public IEnemyDealDamage, public IEnemyTakeDamage, public IEnemyStatus {
public:
    Enemy(int h, int a, int e):health(h), attack(a), evasion(e) {}
    int getHealth(){return health;}
    int getAttack(){return attack;}
    void setHealth(int newHealth){this->health = newHealth;} 
    bool isAlive(int getHealth()){
        if(this->health <= 0) return false;
        else return true;
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

//IMPORTANT, current Health, Attack, and Evasion values are just temporary stats chosen at my liking, will  
//figure out actual stats in a bit

#endif //ENEMY_H