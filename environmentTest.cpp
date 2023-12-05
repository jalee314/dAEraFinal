#include "gtest/gtest.h"
#include "header/Environment.h"
#include "header/Hallway.h"
#include "header/Item.h"
#include "header/Inventory.h"
#include <sstream> //Allows to change cout into readable/comparable string.
/*
TEST(EnvItemTest, GetItemName) {
  HelpItem item("schmingus",3);
    //Had to look up a way to test std::cout
  // Redirect std::cout to a stringstream
  std::stringstream buffer;
  std::streambuf* prevcoutbuf = std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());

  // Call the function being tested
  item.printItem();

  // Restore original buffer before checking the output
  std::cout.rdbuf(prevcoutbuf);

  // Check the output
  std::string expected = "schmingus\n";
  EXPECT_EQ(buffer.str(), expected);
}

TEST(EnvItemTest, EqualityOperator) {
   HelpItem item1("schmingus",3);
   HelpItem item2("schmingus",3);
   EXPECT_TRUE(item1 == item2);
}

TEST(EnvInvTest, AddItemToInventory) {
   InventoryManagement management(10);
   InventoryDisplay display(management);
   Item* item = new Item("schmingus",3);
   std::stringstream buffer;
   std::streambuf* prevcoutbuf = std::cout.rdbuf();
   std::cout.rdbuf(buffer.rdbuf());

   // Call the function being tested
   player.displayInventory();
   // Restore original buffer before checking the output
   std::cout.rdbuf(prevcoutbuf);
   std::string expected = "Item: Schmingus, Assistance: 3\n";
   EXPECT_EQ(buffer.str(), expected);
   delete item;
}

TEST(EnvInvTest, DisplayEmptyInventory) {
   InventoryManagement
   InventoryDisplay() player;
   
   // Redirect std::cout to a stringstream
   std::stringstream buffer;
   std::streambuf* prevcoutbuf = std::cout.rdbuf();
   std::cout.rdbuf(buffer.rdbuf());

   // Call the function being tested
   player.displayInventory();

   // Restore original buffer before checking the output
   std::cout.rdbuf(prevcoutbuf);

   // Check the output
   std::string expected = "Your inventory is empty.\n";
   EXPECT_EQ(buffer.str(), expected);
}

TEST(EnvInvTest, DisplayInventory) {
   PlayerStub player;
   ItemStub* item = new ItemStub("schmingus");
   player.addItemToInventory(item);

   // Redirect std::cout to a stringstream
   std::stringstream buffer;
   std::streambuf* prevcoutbuf = std::cout.rdbuf();
   std::cout.rdbuf(buffer.rdbuf());

   // Call the function being tested
   player.displayInventory();

   // Restore original buffer before checking the output
   std::cout.rdbuf(prevcoutbuf);

   // Check the output
   std::string expected = "Your inventory: schmingus\n";
   EXPECT_EQ(buffer.str(), expected);
}
*/

TEST(EnvironmentTest, DisplayDesc) {
   Hallway hallway("dark spooky hallway");

   // Redirect std::cout to a stringstream
   std::stringstream buffer;
   std::streambuf* prevcoutbuf = std::cout.rdbuf();
   std::cout.rdbuf(buffer.rdbuf());

   hallway.displayDescription();

   // Restore original buffer before checking the output
   std::cout.rdbuf(prevcoutbuf);

   // Check the output
   std::string expected = "dark spooky hallway\n";
   EXPECT_EQ(buffer.str(), expected);
}

TEST(EnvironmentTest, AddItem) {
   Hallway hallway("dark spooky hallway");
   HelpItem schmingus("schmingus",3);
   hallway.addItem(&schmingus);
   EXPECT_EQ(hallway.getNumberItems(), 1);
}

TEST(EnvironmentTest, DisplayItems) {
   Hallway hallway("dark spooky hallway");
   HelpItem schmingus("schmingus",3);
   hallway.addItem(&schmingus);

   // Redirect std::cout to a stringstream
   std::stringstream buffer;
   std::streambuf* prevcoutbuf = std::cout.rdbuf();
   std::cout.rdbuf(buffer.rdbuf());

   // Call the function being tested
   hallway.displayItems();

   // Restore original buffer before checking the output
   std::cout.rdbuf(prevcoutbuf);

   // Check the output
   std::string expected = "You see schmingus \n";
   EXPECT_EQ(buffer.str(), expected);
}

TEST(EnvironmentTest, DisplayItemsFail) {
   Hallway hallway("dark spooky hallway");

   // Redirect std::cout to a stringstream
   std::stringstream buffer;
   std::streambuf* prevcoutbuf = std::cout.rdbuf();
   std::cout.rdbuf(buffer.rdbuf());

   // Call the function being tested
   hallway.displayItems();

   // Restore original buffer before checking the output
   std::cout.rdbuf(prevcoutbuf);

   // Check the output
   std::string expected = "Nothing useful here.\n";
   EXPECT_EQ(buffer.str(), expected);
}

TEST(EnvironmentTest, TakeItem) {
   Hallway hallway("dark spooky hallway");
   Weapon schmingus("schmingus", 3);
   InventoryManagement management(10);
   InventoryDisplay display(management);
   hallway.addItem(&schmingus);

   // Redirect std::cout to a stringstream
   std::stringstream buffer;
   std::streambuf* prevcoutbuf = std::cout.rdbuf();
   std::cout.rdbuf(buffer.rdbuf());

   // Call the function being tested
   hallway.takeItem(&schmingus, management);
   display.displayInventory();

   // Restore original buffer before checking the output
   std::cout.rdbuf(prevcoutbuf);

   // Check the output
   std::string expected = "Inventory: schmingus\n";
   EXPECT_EQ(buffer.str(), expected);
}

TEST(EnvironmentTest, TakeItemFail) {
   Hallway hallway("dark spooky hallway");
   Weapon schmingus("schmingus", 3);
   InventoryManagement management(10);
   InventoryDisplay display(management);

   // Redirect std::cout to a stringstream
   std::stringstream buffer;
   std::streambuf* prevcoutbuf = std::cout.rdbuf();
   std::cout.rdbuf(buffer.rdbuf());

   // Call the function being tested
   hallway.takeItem(&schmingus, management);

   // Restore original buffer before checking the output
   std::cout.rdbuf(prevcoutbuf);

   // Check the output
   std::string expected = "Item not found in this environment.\n";
   EXPECT_EQ(buffer.str(), expected);
   EXPECT_FALSE(hallway.takeItem(&schmingus, management));
}