// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "person.h"
#include "gtest/gtest.h"

TEST(Person, ConstructorDefaultParameters) {
  Person p("33XX");
  
  EXPECT_EQ("33XX", p.getDNI());
  EXPECT_EQ("", p.getName());
  EXPECT_EQ("", p.getSurname());
  EXPECT_EQ("", p.getAddress());
  EXPECT_EQ("", p.getLocality());
  EXPECT_EQ("", p.getProvince());
  EXPECT_EQ("", p.getCountry());
  EXPECT_EQ(0, p.getAge());
  EXPECT_EQ(", ", p.getSurname_Name());
}
 
TEST(Person, ConstructorParameters) {
  Person p("44XX", "Carlos", "Gutierrez", 30, "C/ Table 1", "Aguilar", "Seville", "Spain");
  
  EXPECT_EQ("44XX", p.getDNI());
  EXPECT_EQ("Carlos", p.getName());
  EXPECT_EQ("Gutierrez", p.getSurname());
  EXPECT_EQ(30, p.getAge());
  EXPECT_EQ("C/ Table 1", p.getAddress());
  EXPECT_EQ("Aguilar", p.getLocality());
  EXPECT_EQ("Seville", p.getProvince());
  EXPECT_EQ("Spain", p.getCountry());
  EXPECT_EQ("Gutierrez, Carlos", p.getSurname_Name());
}

TEST(Person, ConstructorDefaultCopy) {
  Person p("44XX", "Carlos", "Gutierrez", 30, "C/ Table 1", "Aguilar", "Seville", "Spain");
  Person q(p);
  Person r=q;
  EXPECT_EQ("44XX", q.getDNI());
  EXPECT_EQ("Carlos", q.getName());
  EXPECT_EQ("Gutierrez", q.getSurname());
  EXPECT_EQ("C/ Table 1", q.getAddress());
  EXPECT_EQ("Aguilar", q.getLocality());
  EXPECT_EQ("Seville", q.getProvince());
  EXPECT_EQ("Spain", q.getCountry());
  EXPECT_EQ("Gutierrez, Carlos", q.getSurname_Name());
  
  EXPECT_EQ("44XX", r.getDNI());
  EXPECT_EQ("Carlos", r.getName());
  EXPECT_EQ("Gutierrez", r.getSurname());
  EXPECT_EQ("C/ Table 1", r.getAddress());
  EXPECT_EQ("Aguilar", r.getLocality());
  EXPECT_EQ("Seville", r.getProvince());
  EXPECT_EQ("Spain", r.getCountry());
  EXPECT_EQ("Gutierrez, Carlos", r.getSurname_Name());
}

TEST(Person, DefaultOperatorEqual) {
  Person p("44XX", "Carlos", "Gutierrez", 30, "C/ Table 1", "Aguilar", "Seville", "Spain");
  Person q("66FF");
  q=p;
  EXPECT_EQ("44XX", q.getDNI());
  EXPECT_EQ("Carlos", q.getName());
  EXPECT_EQ("Gutierrez", q.getSurname());
  EXPECT_EQ("C/ Table 1", q.getAddress());
  EXPECT_EQ("Aguilar", q.getLocality());
  EXPECT_EQ("Seville", q.getProvince());
  EXPECT_EQ("Spain", q.getCountry());
  EXPECT_EQ("Gutierrez, Carlos", q.getSurname_Name());
}
 
 TEST(Person, legal) {
  Person p("44XX", "Carlos", "Gutierrez", 30, "C/ Table 1", "Aguilar", "Seville", "Spain");
  
  EXPECT_EQ(true, p.legal());
  EXPECT_FALSE(p.setAge(-5));
  EXPECT_TRUE(p.setAge(5));
  EXPECT_EQ(false, p.legal());
  
}
