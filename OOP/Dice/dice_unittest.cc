// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class. You don't have to do that exactly, but it helps to keep
// your tests organized. You may also throw in additional tests as
// needed.

#include "dice.h"
#include "gtest/gtest.h"

#include <cstdlib>
#include <ctime>
#include <cmath>

// Tests the c'tor.
TEST(Dice, Constructor) {
  Dice d;
  
  EXPECT_EQ(1, d.getDie1());
  EXPECT_EQ(1, d.getDie2());
  EXPECT_EQ(2, d.getAdd());
  
}

// Tests rolls
TEST(Dice, Roll) {
  Dice d;
  for (int i=0; i<1000; i++){
  d.roll();
  EXPECT_GT(d.getDie1(), 0);
  EXPECT_LT(d.getDie1(), 7);
  EXPECT_GT(d.getDie2(), 0);
  EXPECT_LT(d.getDie2(), 7);
}

}

// Tests Additions
TEST(Dice, getAdd) {
  Dice d;
  EXPECT_EQ(d.getDie1()+d.getDie2(), d.getAdd());
  d.roll();
  EXPECT_EQ(d.getDie1()+d.getDie2(), d.getAdd());
  d.roll();
  EXPECT_EQ(d.getDie1()+d.getDie2(), d.getAdd());
}

// Tests modifiers
TEST(Dice, Modifiers) {
  Dice d;
  int r1, r2;
  EXPECT_FALSE(d.setDie1(9));
  EXPECT_FALSE(d.setDie1(-9));
  EXPECT_FALSE(d.setDie2(9));
  EXPECT_FALSE(d.setDie2(-9));
  d.setDie1(3);
  EXPECT_EQ(3, d.getDie1());
  d.setDie2(2);
  EXPECT_EQ(2, d.getDie2());
  EXPECT_EQ(5, d.getAdd());
  srand(time(NULL));
  for (int i=0;i<100;i++)
  {
    r1=(rand()%6)+1;
    r2=(rand()%6)+1;
    EXPECT_TRUE(d.setDie1(r1));
    EXPECT_TRUE(d.setDie2(r2));
    EXPECT_EQ(r1, d.getDie1());
    EXPECT_EQ(r2, d.getDie2());
  }
}

TEST(Dice, getDiff) {
  Dice d;
  int r1,r2;
  d.setDie1(2);
  d.setDie2(2);
  EXPECT_EQ(0, d.getDiff());
  d.setDie1(2);
  d.setDie2(3);
  EXPECT_EQ(1, d.getDiff());
  d.setDie1(3);
  d.setDie2(2);
  EXPECT_EQ(1, d.getDiff());
  d.setDie1(1);
  d.setDie2(6);
  EXPECT_EQ(5, d.getDiff());
  d.setDie1(6);
  d.setDie2(1);
  EXPECT_EQ(5, d.getDiff());
  srand(time(NULL));
  for (int i=0;i<100;i++)
  {
    r1=(rand()%6)+1;
    r2=(rand()%6)+1;
    d.setDie1(r1);
    d.setDie2(r2);
    EXPECT_EQ(abs(r1-r2), d.getDiff());
  }
}

TEST(Dice, getRolls) {
  Dice d;
  EXPECT_EQ(0, d.getRolls1());
  EXPECT_EQ(0, d.getRolls2());
  d.setDie1(2);
  d.setDie2(2);
  d.roll();
  EXPECT_EQ(2, d.getRolls1());
  EXPECT_EQ(2, d.getRolls2());
  for (int i=0;i<5;i++) d.setDie1(4);
  for (int i=0;i<10;i++) d.setDie2(4);
  EXPECT_EQ(7, d.getRolls1());
  EXPECT_EQ(12, d.getRolls2());
}

TEST(Dice, getAvg) {
  Dice d;
  int i, r1, r2, s1=0, s2=0;
  EXPECT_NEAR(0.0, d.getAvg1(), 0.001); // No EXPECT_EQ with floats
  EXPECT_NEAR(0.0, d.getAvg2(), 0.001); // Not use == with floats
  d.setDie1(2);
  d.setDie2(2);
  EXPECT_NEAR(2.0, d.getAvg1(), 0.001);
  EXPECT_NEAR(2.0, d.getAvg2(), 0.001);
  srand(time(NULL));
  s1+=2;
  s2+=2;
  d.roll();
  s1+=d.getDie1();
  s2+=d.getDie2();
  for (i=0;i<10;i++){
    r1=rand()%6+1;
    r2=rand()%6+1;
    s1+=r1;
    s2+=r2;
    d.setDie1(r1);
    d.setDie2(r2);
  }
  EXPECT_NEAR((s1/12.0), d.getAvg1(), 0.001);
  EXPECT_NEAR((s2/12.0), d.getAvg2(), 0.001);
}

TEST(Dice, getLast1) {
  Dice d;
  int i;
  int v1[5], v2[5];
  for (i=1;i<6;i++) d.setDie1(i);
  for (i=1;i<6;i++) d.setDie2(i);
  d.getLast1(v1);
  d.getLast2(v2);
  for (i=0;i<5;i++) EXPECT_EQ(5-i,v1[i]);
  for (i=0;i<5;i++) EXPECT_EQ(5-i,v2[i]);
}

TEST(Dice, getLast2) {
  Dice d;
  int i;
  int v1[5], v2[5], v1t[5], v2t[5];
  for (i=(rand()%100)+6;i>0;i--){
      d.setDie1(1);
      d.setDie2(1);
      }
  for (i=0;i<5;i++){
      d.setDie1(v1t[i]=rand()%6+1);
      d.setDie2(v2t[i]=rand()%6+1);
      }
  d.getLast1(v1);
  d.getLast2(v2);
  for (i=0;i<5;i++) EXPECT_EQ(v1t[i],v1[4-i]);
  for (i=0;i<5;i++) EXPECT_EQ(v2t[i],v2[4-i]);
}

TEST(Dice, getLast3) {
  Dice d;
  int i;
  int v1a[5], v2a[5];
  int v1b[5], v2b[5];
  for (i=0;i<5;i++) {
    v1a[i]=(rand()%6)+1;
    v2a[i]=(rand()%6)+1;
    d.setDie1(v1a[i]);
    d.setDie2(v2a[i]);
  }
  d.getLast1(v1b);
  d.getLast2(v2b);
  for (i=0;i<5;i++) EXPECT_EQ(v1a[i],v1b[4-i]);
  for (i=0;i<5;i++) EXPECT_EQ(v2a[i],v2b[4-i]);
}
