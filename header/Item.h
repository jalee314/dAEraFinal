#ifndef ITEM_H 
#define ITEM_H
#include <string>

class IAssistive {
public:
    virtual int getAssistance() const = 0; // Pure virtual function
    virtual ~IAssistive() = default;
};

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
    std::string getName() const{return name;}
        // Added equality operator
    bool operator==(const Item& other) const {
        return name == other.name;
    }
protected:
    std::string name;
};

class HelpItem: public Item, public IAssistive {
public:
    HelpItem(const std::string& itemName, int assistanceValue, const std::string& itemType): Item(itemName), assistance(assistanceValue), type(itemType){}
    virtual int useItem();
    virtual void printItem();
    virtual int getAssistance() const{return assistance;}
    std::string getType(){return type;}
private:
    int assistance;
    std::string type;
};

class Weapon: public Item {
public:
    Weapon(const std::string& itemName, int damageValue): Item(itemName), damage(damageValue){}
    virtual int useItem();
    virtual void printItem();
private:
    int damage;
};

#endif //ITEM_H


