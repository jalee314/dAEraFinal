#include "gtest/gtest.h"
#include "../header/Environment.h"
#include "../header/Room.h"
#include "../header/Item.h"
#include "../header/Inventory.h"
#include "../header/Enemy.h"
#include "../header/Page.h"
#include <sstream> //Allows to change cout into readable/comparable string.

TEST(RoomTest, GetNameTest) {
   Room room("This room contains a grip of schmingus", "schmingus room", nullptr, nullptr, nullptr);

   EXPECT_EQ(room.displayDescription(), "This room contains a grip of schmingus");
}

TEST(RoomTest, DisplayTest) {
   Room room("This room contains a grip of schmingus", "schmingus room", nullptr, nullptr, nullptr);
   std::string isSchmingus{"schmingus room"};
   EXPECT_EQ(room.displayName(), isSchmingus);
}

TEST(RoomTest, SetGetEnemyTest) {
   Room room("This room contains a grip of schmingus", "schmingus room", nullptr, nullptr, nullptr);
   Rat remmy;
   room.setEnemyInRoom(&remmy);

   EXPECT_EQ(room.getEnemyFromRoom(), &remmy);
}

TEST(RoomTest, SetGetPageTest) {
   Room room("This room contains a grip of schmingus", "schmingus room", nullptr, nullptr, nullptr);
   Page page;
   room.setPageInRoom(&page);

   EXPECT_EQ(room.getPageFromRoom(), &page);
}

TEST(RoomTest, SetGetItemRoomTest) {
   Room room("This room contains a grip of schmingus", "schmingus room", nullptr, nullptr, nullptr);
   HelpItem schmingus("schmingus",3,"health");
   room.setItemInRoom(&schmingus);
   EXPECT_EQ(room.getItemFromRoom(), &schmingus);
}