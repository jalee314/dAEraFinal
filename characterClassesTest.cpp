#include "playerCharacter.h"
#include "gtest/gtest.h"
#include <iostream>


using namespace std;

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


//TESTS FOR CREATION
TEST(playerCharactertest, characterCreationSOL){
  Soldier victor;

  ASSERT_EQ(victor.getAttack(), 7);
  ASSERT_EQ(victor.getDefense(), 5);
  ASSERT_EQ(victor.getHealth(), 120);
  ASSERT_STREQ(victor.getDifficulty().c_str(), "Easy");
}

TEST(playerCharactertest, characterCreationENGI){
  Engineer justin;

  ASSERT_EQ(justin.getAttack(), 5);
  ASSERT_EQ(justin.getDefense(), 4);
  ASSERT_EQ(justin.getHealth(), 100);
  ASSERT_STREQ(justin.getDifficulty().c_str(), "Medium");
}

TEST(playerCharactertest, characterCreationBIOL){
  Biologist matthew;

  ASSERT_EQ(matthew.getAttack(), 3);
  ASSERT_EQ(matthew.getDefense(), 3);
  ASSERT_EQ(matthew.getHealth(), 80);
  ASSERT_STREQ(matthew.getDifficulty().c_str(), "Hard");
}


//BUFF CHECKING
TEST(playerCharactertest, buffAttack){
  Soldier victor;
  victor.buffAttack();

  EXPECT_EQ(victor.getAttack(), 9);
}

TEST(playerCharactertest, buffDefense){
  Engineer justin;
  justin.buffDefense();

  EXPECT_EQ(justin.getDefense(), 5);
}

TEST(playerCharactertest, buffHealth){
  Biologist matthew;
  matthew.buffHealth();

  EXPECT_EQ(matthew.getHealth(), 100);
}