#include "gtest/gtest.h"
#include "../header/Enemy.h"
#include "../src/Enemy.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(EnemyInteractionTest, AlienDeathTest) {
    Alien alien;
    alien.takeDamage(100);
    EXPECT_FALSE(alien.isAlive());
}

TEST(EnemyInteractionTest, AlienAttackedTest) {
    Alien alien;
    alien.takeDamage(5);
    EXPECT_EQ(alien.getHealth(), 5);
}

TEST(EnemyInteractionTest, RatDeathTest) {
    Rat rat;
    rat.takeDamage(100);
    EXPECT_FALSE(rat.isAlive());
}

TEST(EnemyInteractionTest, RatAttackedTest) {
    Rat rat;
    rat.takeDamage(3);
    EXPECT_EQ(rat.getHealth(), 2);
}

TEST(EnemyInteractionTest, CrewmateDeathTest) {
    Crewmate crewmate;
    crewmate.takeDamage(100);
    EXPECT_FALSE(crewmate.isAlive());
}

TEST(EnemyInteractionTest, CrewmateAttackedTest) {
    Crewmate crewmate;
    crewmate.takeDamage(10);
    EXPECT_EQ(crewmate.getHealth(), 5);
}

TEST(EnemyInteractionTest, TerroristDeathTest) {
    Terrorist terrorist;
    terrorist.takeDamage(100);
    EXPECT_FALSE(terrorist.isAlive());
}

TEST(EnemyInteractionTest, TerroristAttackedTest) {
    Terrorist terrorist;
    terrorist.takeDamage(12);
    EXPECT_EQ(terrorist.getHealth(), 8);
}