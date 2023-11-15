// Environment.cpp
#include "Environment.h"

Environment::Environment(const std::string& description) : description(description) {}

Environment::~Environment() {}

void Environment::displayDescription() const {
    std::cout << description << std::endl;
}

void Environment::addItem(const ItemStub& item) {
    items.push_back(item);
}

void Environment::displayItems() const {
    if (!items.empty()) {
        std::cout << "You see ";
        for (const auto& item : items) {
            item.getItemName();
            std::cout << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Nothing useful here." << std::endl;
    }
}

bool Environment::takeItem(const ItemStub& item, PlayerStub& player) {
    auto it = std::find(items.begin(), items.end(), item);

    if (it != items.end()) {
        // Item found in the environment
        player.addItemToInventory(item);
        items.erase(it);
        return true;
    } else {
        // Item not found in the environment
        std::cout << "Item not found in this environment." << std::endl;
        return false;
    }
}