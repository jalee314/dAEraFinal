// Environment.cpp
#include "../header/Environment.h"
#include <algorithm>

Environment::Environment(const std::string& description) : description(description) {}

Environment::~Environment() {}

void Environment::displayDescription() const {
    std::cout << description << std::endl;
}

void Environment::addItem(ItemStub* item) {
    items.push_back(item);
}

void Environment::displayItems() const {
    if (!items.empty()) {
        std::cout << "You see ";
        for (const auto& item : items) {
            item->getItemName();
        }
    } else {
        std::cout << "Nothing useful here." << std::endl;
    }
}

bool Environment::takeItem(ItemStub* item, PlayerStub& player) {
   auto it = std::find_if(items.begin(), items.end(), [&](ItemStub* i){ return *i == *item; });

   if (it != items.end()) {
       // Item found in the environment
       player.addItemToInventory(*it);
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