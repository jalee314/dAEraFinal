#include "gtest/gtest.h"
#include "../header/Inventory.h"
#include <sstream>

//now including official item class!!!

TEST(InventoryTests, GetNumberofInventoryItems) {
    Weapon Gun("Gun", 10);
    InventoryManagement management(10);
    InventoryDisplay display(management);
    for(int i = 0; i < 5; i++) {
        management.addItem(&Gun);
    }
    EXPECT_EQ(display.getNumItems(), 5);
}

TEST(InventoryTests, TestEmptyInventoryOutput) {
    InventoryManagement management(10);
    InventoryDisplay display(management);
    std::stringstream buffer;
    std::cout.rdbuf(buffer.rdbuf());
    display.displayInventory();
    EXPECT_EQ(buffer.str(), "Nothing here...\n");
}

TEST(InventoryTests, TestOneItemInventoryOutput) {
    Weapon Gun("Gun", 10);
    InventoryManagement management(10);
    InventoryDisplay display(management);
    management.addItem(&Gun);
    std::stringstream buffer;
    std::cout.rdbuf(buffer.rdbuf());
    display.displayInventory();
    EXPECT_EQ(buffer.str(), "Inventory: Gun\n");
}

TEST(InventoryTests, TestMultipleItemInventoryOutput) {
    Weapon Gun("Gun", 10);
    HelpItem Medpack("Medpack", 20);
    HelpItem Keycard("Keycard", 0);
    InventoryManagement management(10);
    InventoryDisplay display(management);
    management.addItem(&Gun);
    management.addItem(&Medpack);
    management.addItem(&Keycard);
    std::stringstream buffer;
    std::cout.rdbuf(buffer.rdbuf());
    display.displayInventory();
    EXPECT_EQ(buffer.str(), "Inventory: Gun, Medpack, Keycard\n");
}
    
TEST(InventoryTests, TestFullInventoryOutput) {
    Weapon Gun("Gun", 10);
    InventoryManagement management(10);
    InventoryDisplay display(management);
    for(int i = 0; i < 10; i++) {
        management.addItem(&Gun);
    }
    std::stringstream buffer;
    std::cout.rdbuf(buffer.rdbuf());
    management.addItem(&Gun);
    EXPECT_EQ(buffer.str(), "Your backpack is full. Throw something out and try again.\n");
}

TEST(InventoryTests, DeleteItemsFromInventory) {
    HelpItem Medpack("Medpack", 20);
    InventoryManagement management(10);
    InventoryDisplay display(management);
    management.addItem(&Medpack);
    std::stringstream buffer;
    std::cout.rdbuf(buffer.rdbuf());
    management.removeItem(&Medpack);
    EXPECT_EQ(buffer.str(), "Medpack has been removed from the inventory.\n");
}

TEST(InventoryTests, DeleteItemFromInventoryFail) {
    HelpItem Medpack("Medpack", 20);
    InventoryManagement management(10);
    InventoryDisplay display(management);
    std::stringstream buffer;
    std::cout.rdbuf(buffer.rdbuf());
    management.removeItem(&Medpack);
    EXPECT_EQ(buffer.str(), "Medpack was not found in the inventory.\n");
}
