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
#include "croupier.h"
#include "roulette.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Roulette, Constructor) {
  Croupier c("33XX","code1");
  Roulette r(c);
  
  EXPECT_EQ("33XX", r.getCroupier().getDNI());
  EXPECT_EQ("code1", r.getCroupier().getCode());
  EXPECT_EQ(-1, r.getBall());
  EXPECT_EQ(1000000, r.getBank());
  EXPECT_TRUE(r.getPlayers().empty());
}

TEST(Roulette, setBall) {
  Croupier c("33XX","code1");
  Roulette r(c);
  EXPECT_TRUE(r.setBall(25));
  EXPECT_EQ(25, r.getBall());
  EXPECT_FALSE(r.setBall(77));
  EXPECT_EQ(25, r.getBall());
}

TEST(Roulette, setBank) {
  Croupier c("33XX","code1");
  Roulette r(c);
  EXPECT_TRUE(r.setBank(2000000));
  EXPECT_EQ(2000000, r.getBank());
  EXPECT_FALSE(r.setBank(-5));
  EXPECT_EQ(2000000, r.getBank());
}

TEST(Roulette, getCroupier) {
  Croupier c("33XX","code1");
  Croupier d("66XX","code2");
  Roulette r(c);
  d=r.getCroupier();
  EXPECT_EQ("33XX", d.getDNI());
  EXPECT_EQ("code1", d.getCode());
}

TEST(Roulette, addPlayer) {
  Croupier c("33XX","croupier1");
  Player j1("44XX","player1");
  Player j2("55XX","player2");
  Roulette r(c);
  EXPECT_TRUE(r.addPlayer(j1));
  EXPECT_TRUE(r.addPlayer(j2));
  EXPECT_FALSE(r.getPlayers().empty());
  EXPECT_EQ(2, r.getPlayers().size());
  EXPECT_EQ("44XX", r.getPlayers().begin()->getDNI());
  EXPECT_EQ("player1", r.getPlayers().begin()->getCode());
  EXPECT_EQ("55XX", (--r.getPlayers().end())->getDNI());
  EXPECT_EQ("player2", (--r.getPlayers().end())->getCode());
  EXPECT_FALSE(r.addPlayer(j1));
  EXPECT_FALSE(r.addPlayer(j1));
}

TEST(Roulette, addPlayerFiles) {
  Croupier c("33XX","croupier1");
  Player j1("44XX","player1");
  Player j2("55XX","player2");
  Roulette r(c);
  r.addPlayer(j1);
  r.addPlayer(j2);
  string nomfich = r.getPlayers().begin()->getDNI() + ".txt";
  fstream salida(nomfich.c_str(), ios::in);
  EXPECT_TRUE((bool)salida);
  salida.close();
  nomfich = (--r.getPlayers().end())->getDNI() + ".txt";
  salida.open(nomfich.c_str(), ios::in);
  EXPECT_TRUE((bool)salida);
  salida.close();
}

TEST(Roulette, deletePlayer) {
  Croupier c("33XX","croupier1");
  Player j1("44XX","player1");
  Player j2("55XX","player2");
  Roulette r(c);
  r.addPlayer(j1);
  r.addPlayer(j2);
  EXPECT_EQ(1,r.deletePlayer(j1));
  EXPECT_EQ(1, r.getPlayers().size());
  EXPECT_EQ("55XX", r.getPlayers().begin()->getDNI());
  EXPECT_EQ("player2", r.getPlayers().begin()->getCode());
  EXPECT_EQ(1, r.getPlayers().size());
  j1.setDNI("88XX");
  EXPECT_EQ(-2,r.deletePlayer(j1));
  EXPECT_EQ(1,r.deletePlayer(j2));
  EXPECT_EQ(-1,r.deletePlayer(j1));
  EXPECT_EQ(0, r.getPlayers().size());
}

TEST(Roulette, deletePlayerDNI) {
  Croupier c("33XX","croupier1");
  Player j1("44XX","player1");
  Player j2("55XX","player2");
  Roulette r(c);
  r.addPlayer(j1);
  r.addPlayer(j2);
  EXPECT_EQ(1,r.deletePlayer("44XX"));
  EXPECT_EQ(1, r.getPlayers().size());
  EXPECT_EQ("55XX", r.getPlayers().begin()->getDNI());
  EXPECT_EQ("player2", r.getPlayers().begin()->getCode());
  EXPECT_EQ(1, r.getPlayers().size());
  EXPECT_EQ(-2,r.deletePlayer("88XX"));
  EXPECT_EQ(1,r.deletePlayer("55XX"));
  EXPECT_EQ(-1,r.deletePlayer("55XX"));
  EXPECT_EQ(0, r.getPlayers().size());
}

TEST(Roulette, deletePlayerInTheMiddle) {
  Croupier c("33XX","croupier1");
  Player j1("44XX","player1");
  Player j2("55XX","player2");
  Player j3("66XX","player3");
  Player j4("77XX","player4");
  Player j5("88XX","player5");
  Roulette r(c);
  r.addPlayer(j1);
  r.addPlayer(j2);
  r.addPlayer(j3);
  r.addPlayer(j4);
  r.addPlayer(j5);
  EXPECT_EQ(1,r.deletePlayer("55XX"));
  EXPECT_EQ(4, r.getPlayers().size());
  EXPECT_EQ("44XX", r.getPlayers().begin()->getDNI());
  EXPECT_EQ("player1", r.getPlayers().begin()->getCode());
  EXPECT_EQ(4, r.getPlayers().size());
  EXPECT_EQ(-2,r.deletePlayer("99XX"));
  EXPECT_EQ(1,r.deletePlayer("77XX"));
  EXPECT_EQ(3, r.getPlayers().size());
}

TEST(Roulette, write_readPlayers) {
  Croupier c("33XX","croupier1");
  Player j1("44XX","player1");
  Player j2("55XX","player2");
  Roulette r(c);
  r.addPlayer(j1);
  r.addPlayer(j2);
  r.writePlayers();
  Roulette r2(c);
  r2.readPlayers();
  EXPECT_FALSE(r2.getPlayers().empty());
  EXPECT_EQ(2, r2.getPlayers().size());
  EXPECT_EQ("44XX", r2.getPlayers().begin()->getDNI());
  EXPECT_EQ("player1", r2.getPlayers().begin()->getCode());
  EXPECT_EQ("55XX", (--r2.getPlayers().end())->getDNI());
  EXPECT_EQ("player2", (--r2.getPlayers().end())->getCode());
}

TEST(Roulette, spinRoulette) {
  Croupier c("33XX","croupier1");
  Roulette r(c);
  for (int i=0;i<100;i++){
    r.spinRoulette();
    EXPECT_GT(r.getBall(), -1);
    EXPECT_LT(r.getBall(), 37);
  }
}

TEST(Roulette, getPrize) {
  Croupier c("33XX","croupier1");
  Player j1("44XX","player1");
  Player j2("55XX","player2");
  Roulette r(c);
  r.addPlayer(j1);
  r.addPlayer(j2);

  ofstream salida("44XX.txt");
  salida << 1 << "," << "10" << "," << 15<< "\n";
  salida << 2 << "," << "red" << "," << 25<< "\n";
  salida << 3 << "," << "even" << "," << 35<< "\n";
  salida << 4 << "," << "low" << "," << 45<< "\n";
  salida.close();

  salida.open("55XX.txt");
  salida << 2 << "," << "red" << "," << 15<< "\n";
  salida << 1 << "," << "15" << "," << 25<< "\n";
  salida << 4 << "," << "high" << "," << 35<< "\n";
  salida << 3 << "," << "odd" << "," << 45<< "\n";
  salida.close();

  r.setBall(10); // negro, even, low
  r.getPrize();
  //44XX -> 1000 + 15*35 - 25 + 35 + 45 = 1580 
  //55XX -> 1000 - 15 - 25 - 35 - 45 = 880
  //Bank_ = Bank_ - 580 + 120 = 999540
  EXPECT_EQ(1580, r.getPlayers().begin()->getMoney());
  EXPECT_EQ(880, (++r.getPlayers().begin())->getMoney());
  EXPECT_EQ(999540, r.getBank());
}

TEST(Roulette, getPrizeNull) {
  Croupier c("33XX","croupier1");
  Player j1("44XX","player1");
  Player j2("55XX","player2");
  Roulette r(c);
  r.addPlayer(j1);
  r.addPlayer(j2);

  ofstream salida("44XX.txt");
  salida << 1 << "," << "10" << "," << 10<< "\n";
  salida << 2 << "," << "red" << "," << 20<< "\n";
  salida << 3 << "," << "even" << "," << 30<< "\n";
  salida << 4 << "," << "low" << "," << 40<< "\n";
  salida.close();

  salida.open("55XX.txt");
  salida << 2 << "," << "red" << "," << 50<< "\n";
  salida << 1 << "," << "15" << "," << 60<< "\n";
  salida << 4 << "," << "high" << "," << 70<< "\n";
  salida << 3 << "," << "odd" << "," << 80<< "\n";
  salida.close();

  r.setBall(0); // Players lost all their bets
  r.getPrize();
  //44XX -> 1000 - 10 - 20 - 30 - 40 = 900 
  //55XX -> 1000 - 50 - 60 - 70 - 80 = 740
  EXPECT_EQ(900, r.getPlayers().begin()->getMoney());
  EXPECT_EQ(740, (++r.getPlayers().begin())->getMoney());
  EXPECT_EQ(1000360, r.getBank());
}


