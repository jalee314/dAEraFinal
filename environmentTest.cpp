#include "gtest/gtest.h"
#include "header/Environment.h"
#include <sstream>

TEST(ItemStubTest, GetItemName) {
  ItemStub item("TestItem");
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
  std::string expected = "TestItem\n";
  EXPECT_EQ(buffer.str(), expected);
}

TEST(ItemStubTest, EqualityOperator) {
   ItemStub item1("TestItem");
   ItemStub item2("TestItem");
   EXPECT_TRUE(item1 == item2);
}

TEST(PlayerStubTest, AddItemToInventory) {
   PlayerStub player;
   ItemStub* item = new ItemStub("TestItem");
   player.addItemToInventory(item);
   EXPECT_EQ(player.inventory.size(), 1);
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
   std::string expected = "TestItem\n";
   EXPECT_EQ(buffer.str(), expected);
}

TEST(PlayerStubTest, DisplayInventory) {
   PlayerStub player;
   ItemStub* item = new ItemStub("TestItem");
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
   std::string expected = "TestItem\n";
   EXPECT_EQ(buffer.str(), expected);
}

TEST(EnvironmentTest, AddItem) {
   Environment environment("TestEnvironment");
   ItemStub* item = new ItemStub("TestItem");
   environment.addItem(item);
   EXPECT_EQ(environment.items.size(), 1);
   delete item;
}

TEST(EnvironmentTest, DisplayItems) {
   Environment environment("TestEnvironment");
   ItemStub* item = new ItemStub("TestItem");
   environment.addItem(item);

   // Redirect std::cout to a stringstream
   std::stringstream buffer;
   std::streambuf* prevcoutbuf = std::cout.rdbuf();
   std::cout.rdbuf(buffer.rdbuf());

   // Call the function being tested
   environment.displayItems();

   // Restore original buffer before checking the output
   std::cout.rdbuf(prevcoutbuf);

   // Check the output
   std::string expected = "You see TestItem ";
   EXPECT_EQ(buffer.str(), expected);

   delete item;
}

TEST(EnvironmentTest, TakeItem) {
   Environment environment("TestEnvironment");
   PlayerStub player;
   ItemStub* item = new ItemStub("TestItem");
   environment.addItem(item);
   EXPECT_TRUE(environment.takeItem(item, player));
   EXPECT_EQ(player.inventory.size(), 1);
   EXPECT_EQ(environment.items.size(), 0);
   delete item;
}