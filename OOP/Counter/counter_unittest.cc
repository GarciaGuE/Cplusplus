// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "counter.h"
#include "gtest/gtest.h"

TEST(Counter, Constructor) {
  Counter c;
  EXPECT_EQ(0, c.get());
  Counter d(10);
  EXPECT_EQ(10, d.get());
  Counter d1(-5);
  EXPECT_EQ(0, d1.get());
  Counter d2(4000);
  EXPECT_EQ(0, d2.get());
  Counter e(-3,10,20);
  EXPECT_EQ(0, e.get());
  Counter f(10,20,15);
  EXPECT_EQ(0, f.get());
  Counter g(-10,200,55);
  EXPECT_EQ(0, g.get());
  Counter h(-10,200,-3);
  EXPECT_EQ(0, h.get());
  Counter i(10,-200,55);
  EXPECT_EQ(10, i.get());
  Counter j(250,200,300);
  EXPECT_EQ(250, j.get());
  Counter k(-300,-300,200);
  EXPECT_EQ(-300, k.get());
}

TEST(Counter, PostfixIncrement1) {
  Counter c;
  EXPECT_EQ(0, c.get());
  c++;
  EXPECT_EQ(1, c.get());
  c++;
  EXPECT_EQ(2, c.get());
}

TEST(Counter, PostfixIncrement2) {
  Counter c(1,10,9);
  EXPECT_EQ(0, c.get());
  c++;
  c++;
  EXPECT_EQ(2, c.get());
}

TEST(Counter, PostfixIncrement3) {
  Counter c(99,10,100);
  EXPECT_EQ(99, c.get());
  c++;
  EXPECT_EQ(100, c.get());
  c++;
  EXPECT_EQ(100, c.get());
}

TEST(Counter, PrefixIncrement1) {
  Counter c;
  EXPECT_EQ(0, c.get());
  ++c;
  EXPECT_EQ(1, c.get());
  ++c;
  EXPECT_EQ(2, c.get());
}

TEST(Counter, PrefixIncrement2) {
  Counter c(1,10,9);
  EXPECT_EQ(0, c.get());
  ++c;
  ++c;
  EXPECT_EQ(2, c.get());
}

TEST(Counter, PrefixIncrement3) {
  Counter c(99,10,100);
  EXPECT_EQ(99, c.get());
  ++c;
  EXPECT_EQ(100, c.get());
  ++c;
  EXPECT_EQ(100, c.get());
}

TEST(Counter, PostfixDecrement1) {
  Counter c;
  EXPECT_EQ(0, c.get());
  c--;
  EXPECT_EQ(0, c.get());
}

TEST(Counter, PostfixDecrement2) {
  Counter c(1,10,10);
  EXPECT_EQ(0, c.get());
  c--;
  EXPECT_EQ(0, c.get());
  c--;
  EXPECT_EQ(0, c.get());
  c++;
  EXPECT_EQ(1, c.get());
  c++;
  EXPECT_EQ(2, c.get());
  c--;
  EXPECT_EQ(1, c.get());
}

TEST(Counter, PostfixDecrement3) {
  Counter c(1,10,2);
  EXPECT_EQ(0, c.get());
  c--;
  c--;
  EXPECT_EQ(0, c.get());
}

TEST(Counter, PrefixDecrement1) {
  Counter c;
  EXPECT_EQ(0, c.get());
  --c;
  EXPECT_EQ(0, c.get());
}

TEST(Counter, PrefixDecrement2) {
  Counter c(1,10,10);
  EXPECT_EQ(0, c.get());
  --c;
  EXPECT_EQ(0, c.get());
  --c;
  EXPECT_EQ(0, c.get());
}

TEST(Counter, PrefixDecrement3) {
  Counter c(11,10,200);
  EXPECT_EQ(11, c.get());
  --c;
  EXPECT_EQ(10, c.get());
  --c;
  EXPECT_EQ(10, c.get());
}

TEST(Counter, Undo1) {
  Counter c;
  EXPECT_FALSE(c.undo());
  EXPECT_EQ(0,c.get());
  c++;
  EXPECT_EQ(1,c.get());
  EXPECT_TRUE(c.undo());
  EXPECT_EQ(0, c.get());
}

TEST(Counter, Undo2) {
  Counter c;
  EXPECT_FALSE(c.undo(-1));
  EXPECT_FALSE(c.undo(-7));
  c++;c++;c++;
  EXPECT_FALSE(c.undo(4));
  EXPECT_TRUE(c.undo(3));
}

TEST(Counter, Undo3) {
  Counter c;
  EXPECT_FALSE(c.undo(1));
  c++;
  EXPECT_TRUE(c.undo(1));
  EXPECT_EQ(0, c.get());
}

TEST(Counter, Undo4) {
  Counter c;
  c++;c++;c++;
  EXPECT_TRUE(c.undo(3));
  EXPECT_EQ(0,c.get());
}

TEST(Counter, Undo5) {
  Counter c(100,10,200);
  c++;c++;c++;
  EXPECT_TRUE(c.undo(3));
  EXPECT_EQ(100,c.get());
}

TEST(Counter, Assign1) {
  Counter c;
  c=10;
  EXPECT_EQ(10, c.get());
  c=5000;
  EXPECT_EQ(1000, c.get());
  c=-3000;
  EXPECT_EQ(0, c.get());
}

TEST(Counter, Assign2) {
  Counter c;  
  c=5555;
  EXPECT_EQ(1000, c.get());
  c=-55555;
  EXPECT_EQ(0, c.get());
}

TEST(Counter, Assign3) {
  Counter c, d;
  c=10;
  d=c;
  EXPECT_EQ(10, d.get());
}

TEST(Counter, ReturnPrefixUnary) {
  Counter c, d;
  c=10;
  EXPECT_EQ(10, c.get());
  d=++c;
  EXPECT_EQ(11, c.get());
  EXPECT_EQ(11, d.get());
  d=--c;
  EXPECT_EQ(10, c.get());
  EXPECT_EQ(10, d.get());
}

TEST(Counter, ReturnPostfixUnary) {
  Counter c, d;
  c=10;
  EXPECT_EQ(10, c.get());
  d=c++;
  EXPECT_EQ(11, c.get());
  EXPECT_EQ(10, d.get());
  d=c--;
  EXPECT_EQ(10, c.get());
  EXPECT_EQ(11, d.get());
}


TEST(Counter, Addition1) {
  Counter c,d;
  c=d+10;
  EXPECT_EQ(10, c.get());
  c=c+15;
  EXPECT_EQ(25, c.get());
}

TEST(Counter, Addition2) {
  Counter c,d;
  c=10+d;
  EXPECT_EQ(10, c.get());
  c=15+c;
  EXPECT_EQ(25, c.get());
}

TEST(Counter, Addition3) {
  Counter c,d;
  c=d+5555;
  EXPECT_EQ(1000, c.get());
  c=5555+d;
  EXPECT_EQ(1000, c.get());

  Counter e(1000,3000,2000);
  e=e+5000;
  EXPECT_EQ(1000, e.get());
  e=5000+e;
  EXPECT_EQ(1000, e.get());
}

TEST(Counter, Substract1) {
  Counter c(1,100,10), d(1,100,10);
  c=d-5;
  EXPECT_EQ(0, c.get());
  c=c-1;
  EXPECT_EQ(0, c.get());
}

TEST(Counter, Substract2) {
  Counter c(10,10,100), d(10,10,100);
  c=d-5;
  EXPECT_EQ(10, c.get());
  c=c-1;
  EXPECT_EQ(10, c.get());
}

TEST(Counter, Substract3) {
  Counter c(100,1,1000), d(100,1,1000);
  c=d-5;
  EXPECT_EQ(95, c.get());
  c=c-1;
  EXPECT_EQ(94, c.get());
}

TEST(Counter, Substract4) {
  Counter c(10,10,100), d(10,10,100);
  c=15-d;
  EXPECT_EQ(10, c.get());
  c=9-c;
  EXPECT_EQ(10, c.get());
}

TEST(Counter, Substract5) {
  Counter c(10000,1,1000000), d(10000,1,1000000);
  c=d-5555;
  EXPECT_EQ(4445, c.get());
  c=1-d;
  EXPECT_EQ(1, c.get());
}

TEST(Counter, ErrorConstructor) {
  Counter c(10,-200,55);
  EXPECT_EQ(10, c.get());
  c=-5000;  
  EXPECT_EQ(-200, c.get()); 
  c=5000;
  EXPECT_EQ(55, c.get());
  Counter d(10,200,300);
  EXPECT_EQ(0, d.get());
  Counter e(10,200,-300);
  EXPECT_EQ(0, e.get());
}
