#include "gtest/gtest.h"
#include "../header/Inventory.h"
#include <sstream>

TEST(InventoryTests, TestEmptyInventoryOutput) {
    InventoryManagement management(10);
    InventoryDisplay display(management);
    std::stringstream buffer;
    std::streambuf* prev = std::cout.rdbuf(buffer.rdbuf());
    display.displayInventory();
    std::cout.rdbuf(prev);
    EXPECT_EQ(buffer.str(), "Nothing here...\n");
}

TEST(InventoryTests, TestOneItemInventoryOutput) {
    ItemStub weapon("Gun");
    InventoryManagement management(10);
    InventoryDisplay display(management);
    management.addItem(weapon);
    std::stringstream buffer;
    std::streambuf* prev = std::cout.rdbuf(buffer.rdbuf());
    display.displayInventory();
    std::cout.rdbuf(prev);
    EXPECT_EQ(buffer.str(), "Inventory: Gun\n");
}

TEST(InventoryTests, TestMultipleItemInventoryOutput) {
    ItemStub weapon("Gun");
    ItemStub health("Medpack");
    ItemStub misc("Keycard");
    InventoryManagement management(10);
    InventoryDisplay display(management);
    management.addItem(weapon);
    management.addItem(health);
    management.addItem(misc);
    std::stringstream buffer;
    std::streambuf* prev = std::cout.rdbuf(buffer.rdbuf());
    display.displayInventory();
    std::cout.rdbuf(prev);
    EXPECT_EQ(buffer.str(), "Inventory: Gun, Medpack, Keycard\n");
}
    
TEST(InventoryTests, TestFullInventoryOutput) {
    ItemStub weapon("Gun");
    InventoryManagement management(10);
    InventoryDisplay display(management);
    for(int i = 0; i < 10; i++) {
        management.addItem(weapon);
    }
    std::stringstream buffer;
    std::streambuf* prev = std::cout.rdbuf(buffer.rdbuf());
    management.addItem(weapon);
    std::cout.rdbuf(prev);
    EXPECT_EQ(buffer.str(), "Your backpack is full. Throw something out and try again.\n");
}

TEST(InventoryTests, DeleteItemsFromInventory) {
    ItemStub weapon("Gun");
    InventoryManagement management(10);
    InventoryDisplay display(management);
    management.addItem(weapon);
    std::stringstream buffer;
    std::streambuf* prev = std::cout.rdbuf(buffer.rdbuf());
    management.removeItem(weapon);
    std::cout.rdbuf(prev);
    EXPECT_EQ(buffer.str(), "Gun has been removed from the inventory.\n");
}

TEST(InventoryTests, DeleteItemFromInventoryFail) {
    ItemStub weapon("Gun");
    InventoryManagement management(10);
    InventoryDisplay display(management);
    std::stringstream buffer;
    std::streambuf* prev = std::cout.rdbuf(buffer.rdbuf());
    management.removeItem(weapon);
    std::cout.rdbuf(prev);
    EXPECT_EQ(buffer.str(), "Gun was not found in the inventory.\n");
}

TEST(InventoryTests, GetNumberofInventoryItems) {
    ItemStub weapon("Gun");
    InventoryManagement management(10);
    InventoryDisplay display(management);
    for(int i = 0; i < 5; i++) {
        management.addItem(weapon);
    }
    EXPECT_EQ(display.getNumItems(), 5);

}