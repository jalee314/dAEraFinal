#include "../header/Room.h"

Room::Room(const std::string& description, const std::string& name, Item* item, EnemyStatus* enemy, Page* page) : Environment(description, name) {
    itemPointer = item;
    enemyPointer = enemy;
    pagePointer = page;
}

void Room::setItemInRoom(Item* item) {
    itemPointer = item;
}

Item* Room::getItemFromRoom() {
    return itemPointer;
}

void Room::setEnemyInRoom(EnemyStatus* enemy) {
    enemyPointer = enemy;
}

EnemyStatus* Room::getEnemyFromRoom() {
    return enemyPointer;
}

void Room::setPageInRoom(Page* page) {
    pagePointer = page;
}

Page* Room::getPageFromRoom() {
    return pagePointer;
}
Room::~Room() {}