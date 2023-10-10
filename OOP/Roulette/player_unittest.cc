// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include <fstream>
#include <list>
#include "player.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Player, ConstructorDefaulParameters) {
  Player j("33XX", "1");
  
  EXPECT_EQ("33XX", j.getDNI());
  EXPECT_EQ("1", j.getCode());
  EXPECT_EQ("", j.getName());
  EXPECT_EQ("", j.getSurname());
  EXPECT_EQ("", j.getAddress());
  EXPECT_EQ("", j.getLocality());
  EXPECT_EQ("", j.getProvince());
  EXPECT_EQ("", j.getCountry());
  EXPECT_EQ(", ", j.getSurname_Name());
}

TEST(Player, ConstructorParameters) {
  Player j("44XX", "2", "Carlos", "Gutierrez",30, "C/ Table 1", "Aguilar", "Seville", "Spain");
  
  EXPECT_EQ("44XX", j.getDNI());
  EXPECT_EQ("2", j.getCode());
  EXPECT_EQ("Carlos", j.getName());
  EXPECT_EQ("Gutierrez", j.getSurname());
  EXPECT_EQ("C/ Table 1", j.getAddress());
  EXPECT_EQ("Aguilar", j.getLocality());
  EXPECT_EQ("Seville", j.getProvince());
  EXPECT_EQ("Spain", j.getCountry());
  EXPECT_EQ("Gutierrez, Carlos", j.getSurname_Name());
}

TEST(Player, setMoney_getMoney) {
  Player j("33XX", "1");

  EXPECT_EQ(1000, j.getMoney());
  j.setMoney(555);
  EXPECT_EQ(555, j.getMoney());
}

TEST(Player, setCode_getCode) {
  Player j("33XX", "1");

  EXPECT_EQ("1", j.getCode());
  j.setCode("55");
  EXPECT_EQ("55", j.getCode());
}

TEST(Player, setBets_getVoidBets) {
  Player j("33XX", "1");
  list<Bet> l;
  l= j.getBets();
  EXPECT_TRUE(l.empty());
}

TEST(Player, setBets_getBets) {
  Player j("33XX", "1");
  string nomfich=j.getDNI()+".txt";
  ofstream salida(nomfich.c_str());
  salida << 1 << "," << "10" << "," << 15<< "\n";
  salida << 2 << "," << "red" << "," << 25<< "\n";
  salida << 3 << "," << "even" << "," << 35<< "\n";
  salida << 4 << "," << "low" << "," << 45<< "\n";
  salida.close();
  list<Bet> l;
  j.setBets();
  l= j.getBets();
  EXPECT_EQ(4, l.size());
  list<Bet>::iterator i;
  i=l.begin();
  EXPECT_EQ(1, (*i).type);
  EXPECT_EQ("10", (*i).value);
  EXPECT_EQ(15, (*i).quantity);
  i++;
  EXPECT_EQ(2, (*i).type);
  EXPECT_EQ("red", (*i).value);
  EXPECT_EQ(25, (*i).quantity);
  i++;
  EXPECT_EQ(3, (*i).type);
  EXPECT_EQ("even", (*i).value);
  EXPECT_EQ(35, (*i).quantity);
  i++;
  EXPECT_EQ(4, (*i).type);
  EXPECT_EQ("low", (*i).value);
  EXPECT_EQ(45, (*i).quantity);
}

