// dados_unittest.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//


// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "croupier.h"
#include "gtest/gtest.h"

TEST(Croupier, ConstructorDefaultParameters) {
  Croupier c("33XX", "1");
  
  EXPECT_EQ("33XX", c.getDNI());
  EXPECT_EQ("1", c.getCode());
  EXPECT_EQ("", c.getName());
  EXPECT_EQ("", c.getSurname());
  EXPECT_EQ("", c.getAddress());
  EXPECT_EQ("", c.getLocality());
  EXPECT_EQ("", c.getProvince());
  EXPECT_EQ("", c.getCountry());
  EXPECT_EQ(", ", c.getSurname_Name());
}

TEST(Croupier, ConstructorParameters) {
  Croupier c("44XX", "2", "Carlos", "Gutierrez",30, "C/ Table 1", "Aguilar", "Seville", "Spain");
  
  EXPECT_EQ("44XX", c.getDNI());
  EXPECT_EQ("2", c.getCode());
  EXPECT_EQ("Carlos", c.getName());
  EXPECT_EQ("Gutierrez", c.getSurname());
  EXPECT_EQ("C/ Table 1", c.getAddress());
  EXPECT_EQ("Aguilar", c.getLocality());
  EXPECT_EQ("Seville", c.getProvince());
  EXPECT_EQ("Spain", c.getCountry());
  EXPECT_EQ("Gutierrez, Carlos", c.getSurname_Name());
}

TEST(Croupier, ConstructorDefaultCopy) {
  Croupier p("55XX", "3", "Carlos", "Gutierrez",30, "C/ Table 1", "Aguilar", "Seville", "Spain");
  Croupier q(p);
  
  EXPECT_EQ("55XX", q.getDNI());
  EXPECT_EQ("3", q.getCode());
  EXPECT_EQ("Carlos", q.getName());
  EXPECT_EQ("Gutierrez", q.getSurname());
  EXPECT_EQ("C/ Table 1", q.getAddress());
  EXPECT_EQ("Aguilar", q.getLocality());
  EXPECT_EQ("Seville", q.getProvince());
  EXPECT_EQ("Spain", q.getCountry());
  EXPECT_EQ("Gutierrez, Carlos", q.getSurname_Name());
}

TEST(Croupier, EqualOperator) {
  Croupier p("66XX", "4", "Carlos", "Gutierrez", 30,"C/ Table 1", "Aguilar", "Seville", "Spain");
  Croupier q("77FF", "5");
  q=p;
  EXPECT_EQ("66XX", q.getDNI());
  EXPECT_EQ("4", q.getCode());
  EXPECT_EQ("Carlos", q.getName());
  EXPECT_EQ("Gutierrez", q.getSurname());
  EXPECT_EQ("C/ Table 1", q.getAddress());
  EXPECT_EQ("Aguilar", q.getLocality());
  EXPECT_EQ("Seville", q.getProvince());
  EXPECT_EQ("Spain", q.getCountry());
  EXPECT_EQ("Gutierrez, Carlos", q.getSurname_Name());
}
