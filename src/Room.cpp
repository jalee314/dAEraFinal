#include "../header/Room.h"

Room::Room(const std::string& name, const std::string& description) : Environment(description) {
    roomName = name;
}

const std::string& Room::getRoomName() const {
    return roomName;
}

void Room::printRoomName() {
    std::cout << roomName << '\n';
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