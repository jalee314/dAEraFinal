#include "gtest/gtest.h"
#include "../header/Enemy.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(EnemyInteractionTest, AlienDeathTest) {
    Alien alien;
    alien.setEvasion(0);
    alien.takeDamage(100);
    EXPECT_FALSE(alien.isAlive());
}

TEST(EnemyInteractionTest, AlienAttackedTest) {
    Alien alien;
    alien.setEvasion(0);
    alien.takeDamage(5);
    EXPECT_EQ(alien.getHealth(), 15);
}

TEST(EnemyInteractionTest, MissAttackOnAlien) {
    Alien alien;
    alien.setEvasion(100);
    alien.takeDamage(1000);
    EXPECT_EQ(alien.getHealth(), 20);
}

TEST(EnemyInteractionTest, AlienAttacks) {
    Alien alien;
    alien.setAccuracy(100);
    EXPECT_EQ(alien.dealDamage(), 15);
}

TEST(EnemyInteractionTest, AlienAttackMisses) {
    Alien alien;
    alien.setAccuracy(0);
    EXPECT_EQ(alien.dealDamage(), 0);
}

TEST(EnemyInteractionTest, RatDeathTest) {
    Rat rat;
    rat.setEvasion(0);
    rat.takeDamage(100);
    EXPECT_FALSE(rat.isAlive());
}

TEST(EnemyInteractionTest, RatAttackedTest) {
    Rat rat;
    rat.setEvasion(0);
    rat.takeDamage(3);
    EXPECT_EQ(rat.getHealth(), 2);
}

TEST(EnemyInteractionTest, MissAttackOnRat) {
    Rat rat;
    rat.setEvasion(100);
    rat.takeDamage(1000);
    EXPECT_EQ(rat.getHealth(), 5);
}

TEST(EnemyInteractionTest, RatAttacks) {
    Rat rat;
    rat.setAccuracy(100);
    EXPECT_EQ(rat.dealDamage(), 6);
}

TEST(EnemyInteractionTest, RatAttackMisses) {
    Rat rat;
    rat.setAccuracy(0);
    EXPECT_EQ(rat.dealDamage(), 0);
}

TEST(EnemyInteractionTest, CrewmateDeathTest) {
    Crewmate crewmate;
    crewmate.setEvasion(0);
    crewmate.takeDamage(100);
    EXPECT_FALSE(crewmate.isAlive());
}

TEST(EnemyInteractionTest, CrewmateAttackedTest) {
    Crewmate crewmate;
    crewmate.setEvasion(0);
    crewmate.takeDamage(10);
    EXPECT_EQ(crewmate.getHealth(), 5);
}

TEST(EnemyInteractionTest, MissAttackOnCrewmate) {
    Crewmate crewmate;
    crewmate.setEvasion(100);
    crewmate.takeDamage(1000);
    EXPECT_EQ(crewmate.getHealth(), 15);
}

TEST(EnemyInteractionTest, CrewmateAttacks) {
    Crewmate crewmate;
    crewmate.setAccuracy(100);
    EXPECT_EQ(crewmate.dealDamage(), 11);
}

TEST(EnemyInteractionTest, CrewmateAttackMisses) {
    Alien alien;
    alien.setAccuracy(0);
    EXPECT_EQ(alien.dealDamage(), 0);
}

TEST(EnemyInteractionTest, TerroristDeathTest) {
    Terrorist terrorist;
    terrorist.setEvasion(0);
    terrorist.takeDamage(100);
    EXPECT_FALSE(terrorist.isAlive());
}

TEST(EnemyInteractionTest, TerroristAttackedTest) {
    Terrorist terrorist;
    terrorist.setEvasion(0);
    terrorist.takeDamage(12);
    EXPECT_EQ(terrorist.getHealth(), 8);
}

TEST(EnemyInteractionTest, MissAttackOnTerrorist) {
    Terrorist terrorist;
    terrorist.setEvasion(100);
    terrorist.takeDamage(1000);
    EXPECT_EQ(terrorist.getHealth(), 20);
}

TEST(EnemyInteractionTest, TerroristAttacks) {
    Terrorist terrorist;
    terrorist.setAccuracy(100);
    EXPECT_EQ(terrorist.dealDamage(), 13);
}

TEST(EnemyInteractionTest, TerroristAttackMisses) {
    Terrorist terrorist;
    terrorist.setAccuracy(0);
    EXPECT_EQ(terrorist.dealDamage(), 0);
}