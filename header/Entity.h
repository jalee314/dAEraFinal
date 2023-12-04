#ifndef ENTITY_H
#define ENTITY_H

class IEntity {
public:
    IEntity(int h, int a, int d): health(h), attack(a), defense(d) {}
    virtual void printStatus() = 0;
    bool isAlive(){return health > 0;} 
    virtual ~IEntity(){}
protected:
    int health;
    int attack;
    int defense;
};

#endif //ENTITY_H