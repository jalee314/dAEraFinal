#include "header/battleActions.h"
#include "header/playerCharacter.h"
#include "header/Enemy.h"
#include "header/Item.h"
#include "gtest/gtest.h"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

//test to make sure changes work
TEST(BattleTests, compileTest){
    ASSERT_NO_THROW(Soldier mate);  
    ASSERT_NO_THROW(Rat Remmy);
    ASSERT_NO_THROW(battleActions actions);
}