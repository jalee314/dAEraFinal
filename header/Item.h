#ifndef ITEM_H 
#define ITEM_H
#include <string>


/*thought about splitting up the virtual functions into two separate 
classes for useItem and printItem due to SRP, but this class in my opinion
can be described as "A class that controls item usage for the player character".
so even though functions serve different purposes, I thought at the end of they day it 
fits under the same umbrella
*/

class Item {
public:
    Item(const std::string& itemName): name(itemName){}
    virtual int useItem() = 0;
    virtual void printItem() = 0;
    virtual int getValue() const = 0;
    virtual std::string getType() = 0;
    std::string getName() const{return name;}
        // Added equality operator
    bool operator==(const Item& other) const {
        return name == other.name;
    }
    
protected:
    std::string name;
};

class HelpItem: public Item{
public:
    HelpItem(const std::string& itemName, int assistanceValue, const std::string& itemType): Item(itemName), assistance(assistanceValue), type(itemType){}
    virtual int useItem();
    virtual void printItem();
    virtual int getValue() const{return assistance;}
    virtual std::string getType(){return type;}
private:
    int assistance;
    std::string type;
};

class Weapon: public Item {
public:
    Weapon(const std::string& itemName, int damageValue): Item(itemName), damage(damageValue){}
    virtual int useItem();
    virtual void printItem();
    virtual int getValue() const{return damage;}
    virtual std::string getType(){return "weapon";}
private:
    int damage;
};

#endif //ITEM_H


