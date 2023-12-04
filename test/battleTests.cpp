#include "../header/battleActions.h"
#include "../header/playerCharacter.h"
#include "../header/Enemy.h"
#include "../header/Item.h"
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

TEST(BattleTests, testPlayerAttacksEnemy) {
  Rat remmy;
  Biologist protagonist;
  battleActions battle;
  remmy.setEvasion(0);
  remmy.takeDamage(battle.attack(&remmy, &protagonist));
  ASSERT_EQ(remmy.getHealth(), 1); 
}

TEST(BattleTests, testPlayerAttacksMissEnemy) {
  Rat remmy;
  Biologist protagonist;
  battleActions battle;
  remmy.setEvasion(100);
  remmy.takeDamage(battle.attack(&remmy, &protagonist));
  ASSERT_EQ(remmy.getHealth(), 5); 
}

TEST(BattleTests, testEnemyAttacksPlayer) {
  Alien allen;
  Biologist protagonist;
  battleActions battle;
  allen.setAccuracy(100);
  battle.defend(&protagonist, allen.dealDamage());
  ASSERT_EQ(protagonist.getHealth(), 68); 
}

TEST(BattleTests,testEnemyAttacksMissPlayer) {
  Alien allen;
  Biologist protagonist;
  battleActions battle;
  allen.setAccuracy(0);
  battle.defend(&protagonist, allen.dealDamage());
  ASSERT_EQ(protagonist.getHealth(), 80); 
}

TEST(BattleTests, testItemHealthBuff) {
  Alien allen;
  Biologist protagonist;
  battleActions battle;
  HelpItem bandages("Bandages", 5, "health");
  protagonist.addToInventory(&bandages);
  allen.setAccuracy(100);
  battle.defend(&protagonist, allen.dealDamage());
  ASSERT_TRUE(protagonist.itemInInventory(&bandages));
  battle.useItem(&bandages, &protagonist);
  ASSERT_FALSE(protagonist.itemInInventory(&bandages));
  ASSERT_EQ(protagonist.getHealth(), 73); 
}

TEST(BattleTests, testItemAttackBuff) {
  Crewmate rick;
  Engineer protagonist;
  battleActions battle;
  HelpItem roids("Steroids", 3, "attack");
  protagonist.addToInventory(&roids);
  ASSERT_TRUE(protagonist.itemInInventory(&roids));
  rick.setEvasion(0);
  battle.useItem(&roids, &protagonist);
  ASSERT_FALSE(protagonist.itemInInventory(&roids));
  rick.takeDamage(battle.attack(&rick, &protagonist));
  ASSERT_EQ(rick.getHealth(), 8); 
}

TEST(BattleTests, testItemDefenseBuff) {
  Terrorist grunt;
  Soldier protagonist;
  battleActions battle;
  HelpItem chestplate("Chestplate", 2, "defense"); 
  protagonist.addToInventory(&chestplate);
  ASSERT_TRUE(protagonist.itemInInventory(&chestplate));
  grunt.setAccuracy(100);
  battle.useItem(&chestplate, &protagonist);
  ASSERT_FALSE(protagonist.itemInInventory(&chestplate));
  battle.defend(&protagonist, grunt.dealDamage());
  ASSERT_EQ(protagonist.getHealth(), 114); 
}

TEST(BattleTests, killEnemy) {
  Terrorist grunt;
  Soldier protagonist;
  battleActions battle;
  HelpItem devtool("devtool", 100, "attack"); 
  grunt.setEvasion(0);
  protagonist.addToInventory(&devtool);
  ASSERT_TRUE(protagonist.itemInInventory(&devtool));
  battle.useItem(&devtool, &protagonist);
  ASSERT_FALSE(protagonist.itemInInventory(&devtool));
  grunt.takeDamage(battle.attack(&grunt, &protagonist));
  ASSERT_FALSE(grunt.isAlive()); 
}

TEST(BattleTests, characterDeath) {
  Alien allen;
  Biologist protagonist;
  battleActions battle;
  allen.setAccuracy(100);
  battle.defend(&protagonist, allen.dealDamage());
  ASSERT_TRUE(protagonist.isAlive()); 
  for(int i = 0; i < 10; i++) {
    battle.defend(&protagonist, allen.dealDamage());
  }
  EXPECT_FALSE(protagonist.isAlive());
}