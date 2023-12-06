#ifndef ROOM_H
#define ROOM_H

#include "Environment.h"
#include "Enemy.h"
#include "Page.h"

class Room : public Environment {
private:
    std::string roomName{};
    Item* itemPointer{};
    EnemyStatus* enemyPointer{};
    Page* pagePointer{};

public:
    Room(const std::string& name, const std::string& description);
    std::string& getRoomName() const;
    void prtintRoomName();
        //put a item in the room for the player to find
    void setItemInRoom(Item* item);

        //pointer to the item thats in the room
    Item* getItemFromRoom();

        //put a baddy in the room for the player to fight
    void setEnemyInRoom(EnemyStatus* enemy);

        //pointer to the baddy thats in the room
    EnemyStatus* getEnemyFromRoom();

        //put a page in the room for the player to read
    void setPageInRoom(Page* page);

        //pointer to page in the room
    Page* getPageInRoom();
    virtual ~Room();
};

#endif // ROOM_H
