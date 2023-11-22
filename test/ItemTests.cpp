#include "gtest/gtest.h"
#include "../header/Item.h"
#include <iostream>
#include <sstream>

TEST(ItemsTestSuite, useHelpItem) {
    HelpItem vitamins("Vitamins", 5);
    EXPECT_EQ(vitamins.useItem(), 5);
}

TEST(ItemsTestSuite, printHelpItem) {
    HelpItem vitamins("Vitamins", 10); 
    std::stringstream buffer;
    std::streambuf* prev = std::cout.rdbuf(buffer.rdbuf()); 
    vitamins.printItem();
    std::cout.rdbuf(prev);
    EXPECT_EQ("Item: Vitamins, Assistance: 10\n", buffer.str());
}

TEST(ItemsTestSuite, printWeapon) {
    Weapon musket("Musket", 10); 
    std::stringstream buffer;
    std::streambuf* prev = std::cout.rdbuf(buffer.rdbuf()); 
    musket.printItem();
    std::cout.rdbuf(prev);
    EXPECT_EQ("Weapon: Musket, Damage: 10\n", buffer.str());
}

TEST(ItemsTestSuite, useWeapon) {
    Weapon musket("Musket", 10); 
    EXPECT_EQ(musket.useItem(), 10);
}
