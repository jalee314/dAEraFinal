#include "../header/Environment.h"
#include <algorithm>

Environment::Environment(const std::string& description, const std::string& name) : description(description),  roomName(name){}

Environment::~Environment() {}

std::string Environment::displayDescription() const {
    return description;
}
std::string Environment::displayName() const {
    return roomName;
}

/*
void Environment::addItem(Item* item) {
    items.push_back(item);
}

void Environment::displayItems() const {
    if (!items.empty()) {
        std::cout << "You see ";
        for (const auto& item : items) {
            std::cout << item->getName();
            std::cout << ' ';
        }
        std::cout << '\n';
    } else {
        std::cout << "Nothing useful here." << std::endl;
    }
}

//Takes item from the environment and adds it to players inv
bool Environment::takeItem(Item* item, InventoryManagement& player) {
   auto it = std::find_if(items.begin(), items.end(), [&](Item* i){ return *i == *item; });

   if (it != items.end()) {
       // Item found in the environment
       player.addItem(*it);
       items.erase(it);
       return true;
   } else {
       // Item not found in the environment
       std::cout << "Item not found in this environment." << std::endl;
       return false;
   }
}

size_t Environment::getNumberItems() const {
    return items.size();
}
*/