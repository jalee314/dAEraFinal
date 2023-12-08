#ifndef ROOM_H
#define ROOM_H

#include "Environment.h"
/*
#include "Enemy.h"
#include "Page.h"
*/
class Room : public Environment {
private:
    Item* itemPointer;
    EnemyStatus* enemyPointer;
    Page* pagePointer;

public:
    Room(const std::string& description, const std::string& name, Item* item, EnemyStatus* enemy, Page* page);
    /*
    const std::string& getRoomName() const;
    
    void printRoomName();
        //put a item in the room for the player to find
    */
    virtual void setItemInRoom(Item* item);

        //pointer to the item thats in the room
    virtual Item* getItemFromRoom();

        //put a baddy in the room for the player to fight
    virtual void setEnemyInRoom(EnemyStatus* enemy);

        //pointer to the baddy thats in the room
    virtual EnemyStatus* getEnemyFromRoom();

        //put a page in the room for the player to read
    virtual void setPageInRoom(Page* page);

        //pointer to page in the room
    virtual Page* getPageFromRoom();
    virtual ~Room();
};

#endif // ROOM_H