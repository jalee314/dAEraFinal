#include "gtest/gtest.h"
#include "header/Environment.h"
#include "header/Room.h"
#include "header/Item.h"
#include "header/Inventory.h"
#include "header/Enemy.h"
#include "header/Page.h"
#include <sstream> //Allows to change cout into readable/comparable string.

TEST(RoomTest, DisplayTest) {
   Room room("schmingus room", "This room contains a grip of schmingus");

   // Redirect std::cout to a stringstream
   std::stringstream buffer;
   std::streambuf* prevcoutbuf = std::cout.rdbuf();
   std::cout.rdbuf(buffer.rdbuf());

   room.printRoomName();

   // Restore original buffer before checking the output
   std::cout.rdbuf(prevcoutbuf);

   // Check the output
   std::string expected = "schmingus room\n";
   EXPECT_EQ(buffer.str(), expected);
}

TEST(RoomTest, GetNameTest) {
   Room room("schmingus room", "This room contains a grip of schmingus");
   std::string isSchmingus{"schmingus room"};
   EXPECT_EQ(room.getRoomName(), isSchmingus);
}

TEST(RoomTest, SetGetEnemyTest) {
   Room room("schmingus room", "This room contains a grip of schmingus");
   Rat remmy;
   room.setEnemyInRoom(&remmy);

   EXPECT_EQ(room.getEnemyFromRoom(), &remmy);
}

TEST(RoomTest, SetGetPageTest) {
   Room room("schmingus room", "This room contains a grip of schmingus");
   Page page;
   room.setPageInRoom(&page);

   EXPECT_EQ(room.getPageFromRoom(), &page);
}

TEST(RoomTest, SetGetItemRoomTest) {
   Room room("schmingus room", "This room contains a grip of schmingus");
   HelpItem schmingus("schmingus",3,"health");
   room.setItemInRoom(&schmingus);
   EXPECT_EQ(room.getItemFromRoom(), &schmingus);
}