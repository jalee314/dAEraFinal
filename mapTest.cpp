#include "gtest/gtest.h"
#include "header/Environment.h"
#include "header/Hallway.h"
#include "header/Map.h"

TEST(MapTest, AddRoom) {
 Map map(5);
 Hallway hw("dark spooky hallway");
 map.addRoom(&hw);
 EXPECT_EQ(map.getRoom(0), &hw);
}

TEST(MapTest, ConnectRooms) {
   Map map(5);
   Hallway hw1("dark spooky hallway");
   Hallway hw2("light happy hallway");
   map.addRoom(&hw1);
   map.addRoom(&hw2);
   map.connectRooms(0, 1);
   EXPECT_TRUE(map.canMove(0, 1));
}

TEST(MapTest, CanMoveFalse) {
   Map map(5);
   EXPECT_FALSE(map.canMove(0, 1));
}