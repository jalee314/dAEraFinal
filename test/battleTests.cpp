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
    Weapon universalWeapon("Gun", 8);
    ASSERT_NO_THROW(Soldier mate(&universalWeapon));  
    ASSERT_NO_THROW(Rat Remmy);
    ASSERT_NO_THROW(battleActions actions);
}

TEST(BattleTests, testPlayerAttacksEnemy) {
  Rat remmy;
  Weapon universalWeapon("Gun", 8);
  Biologist protagonist(&universalWeapon);
  battleActions battle;
  remmy.setEvasion(0);
  remmy.takeDamage(battle.attack(&remmy, &protagonist));
  ASSERT_EQ(remmy.getHealth(), 1); 
}

TEST(BattleTests, testPlayerAttacksMissEnemy) {
  Rat remmy;
  Weapon universalWeapon("Gun", 8);
  Biologist protagonist(&universalWeapon);
  battleActions battle;
  remmy.setEvasion(100);
  remmy.takeDamage(battle.attack(&remmy, &protagonist));
  ASSERT_EQ(remmy.getHealth(), 5); 
}

TEST(BattleTests, testEnemyAttacksPlayer) {
  Alien allen;
  Weapon universalWeapon("Gun", 8);
  Biologist protagonist(&universalWeapon);
  battleActions battle;
  allen.setAccuracy(100);
  battle.defend(&protagonist, allen.dealDamage());
  ASSERT_EQ(protagonist.getHealth(), 68); 
}

TEST(BattleTests,testEnemyAttacksMissPlayer) {
  Alien allen;
  Weapon universalWeapon("Gun", 8);
  Biologist protagonist(&universalWeapon);
  battleActions battle;
  allen.setAccuracy(0);
  battle.defend(&protagonist, allen.dealDamage());
  ASSERT_EQ(protagonist.getHealth(), 80); 
}

TEST(BattleTests, testItemHealthBuff) {
  Alien allen;
  Weapon universalWeapon("Gun", 8);
  Biologist protagonist(&universalWeapon);
  battleActions battle;
  HelpItem bandages("Bandages", 5, "health");
  protagonist.addToInventory(&bandages);
  allen.setAccuracy(100);
  battle.defend(&protagonist, allen.dealDamage());
  ASSERT_TRUE(protagonist.itemInInventory("Bandages"));
  battle.useItem(&bandages, &protagonist);
  ASSERT_FALSE(protagonist.itemInInventory("Bandages"));
  ASSERT_EQ(protagonist.getHealth(), 73); 
}

TEST(BattleTests, testItemAttackBuff) {
  Crewmate rick;
  Weapon universalWeapon("Gun", 8);
  Engineer protagonist(&universalWeapon);
  battleActions battle;
  HelpItem roids("Steroids", 3, "attack");
  protagonist.addToInventory(&roids);
  ASSERT_TRUE(protagonist.itemInInventory("Steroids"));
  rick.setEvasion(0);
  battle.useItem(&roids, &protagonist);
  ASSERT_FALSE(protagonist.itemInInventory("Steroids"));
  rick.takeDamage(battle.attack(&rick, &protagonist));
  ASSERT_EQ(rick.getHealth(), 10); 
}

TEST(BattleTests, testItemDefenseBuff) {
  Terrorist grunt;
  Weapon universalWeapon("Gun", 8);
  Soldier protagonist(&universalWeapon);
  battleActions battle;
  HelpItem chestplate("Chestplate", 2, "defense"); 
  protagonist.addToInventory(&chestplate);
  ASSERT_TRUE(protagonist.itemInInventory("Chestplate"));
  grunt.setAccuracy(100);
  battle.useItem(&chestplate, &protagonist);
  ASSERT_FALSE(protagonist.itemInInventory("Chestplate"));
  battle.defend(&protagonist, grunt.dealDamage());
  ASSERT_EQ(protagonist.getHealth(), 114); 
}

TEST(BattleTests, killEnemy) {
  Terrorist grunt;
  Weapon universalWeapon("Gun", 100);
  Soldier protagonist(&universalWeapon);
  protagonist.setAttack(&universalWeapon);
  battleActions battle;
  grunt.setEvasion(0);
  grunt.takeDamage(battle.attack(&grunt, &protagonist));
  ASSERT_FALSE(grunt.isAlive()); 
}

TEST(BattleTests, characterDeath) {
  Alien allen;
  Weapon universalWeapon("Gun", 8);
  Biologist protagonist(&universalWeapon);
  battleActions battle;
  allen.setAccuracy(100);
  battle.defend(&protagonist, allen.dealDamage());
  ASSERT_TRUE(protagonist.isAlive()); 
  for(int i = 0; i < 10; i++) {
    battle.defend(&protagonist, allen.dealDamage());
  }
  EXPECT_FALSE(protagonist.isAlive());
}