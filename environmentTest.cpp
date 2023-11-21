#include "gtest/gtest.h"
#include "header/Environment.h"
#include "header/Hallway.h"
#include <sstream> //Allows to change cout into readable/comparable string.

TEST(ItemStubTest, GetItemName) {
  ItemStub item("schmingus");
    //Had to look up a way to test std::cout
  // Redirect std::cout to a stringstream
  std::stringstream buffer;
  std::streambuf* prevcoutbuf = std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());

  // Call the function being tested
  item.getItemName();

  // Restore original buffer before checking the output
  std::cout.rdbuf(prevcoutbuf);

  // Check the output
  std::string expected = "schmingus\n";
  EXPECT_EQ(buffer.str(), expected);
}

TEST(ItemStubTest, EqualityOperator) {
   ItemStub item1("schmingus");
   ItemStub item2("schmingus");
   EXPECT_TRUE(item1 == item2);
}

TEST(PlayerStubTest, AddItemToInventory) {
   PlayerStub player;
   ItemStub* item = new ItemStub("schmingus");
   player.addItemToInventory(item);
   EXPECT_EQ(player.getInventorySize(), 1);
   delete item;
}

TEST(PlayerStubTest, DisplayEmptyInventory) {
   PlayerStub player;
   
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

TEST(PlayerStubTest, DisplayInventory) {
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

TEST(EnvironmentTest, AddItem) {
   Hallway hallway("dark spooky hallway");
   ItemStub* item = new ItemStub("schmingus");
   hallway.addItem(item);
   EXPECT_EQ(hallway.getNumberItems(), 1);
   delete item;
}

TEST(EnvironmentTest, DisplayItems) {
   Hallway hallway("dark spooky hallway");
   ItemStub* item = new ItemStub("schmingus");
   hallway.addItem(item);

   // Redirect std::cout to a stringstream
   std::stringstream buffer;
   std::streambuf* prevcoutbuf = std::cout.rdbuf();
   std::cout.rdbuf(buffer.rdbuf());

   // Call the function being tested
   hallway.displayItems();

   // Restore original buffer before checking the output
   std::cout.rdbuf(prevcoutbuf);

   // Check the output
   std::string expected = "You see schmingus\n";
   EXPECT_EQ(buffer.str(), expected);

   delete item;
}

TEST(EnvironmentTest, TakeItem) {
   Hallway hallway("dark spooky hallway");
   PlayerStub player;
   ItemStub* item = new ItemStub("schmingus");
   hallway.addItem(item);
   EXPECT_TRUE(hallway.takeItem(item, player));
   EXPECT_EQ(player.getInventorySize(), 1);
   EXPECT_EQ(hallway.getNumberItems(), 0);
   delete item;
}