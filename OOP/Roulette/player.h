#ifndef PLAYER_H
#define PLAYER_H
#include "person.h"
#include <string>
#include <list>

using namespace std;

struct Bet{
    int type, quantity;
    string value;
};

// Player inherits from Person
class Player : public Person{
    private:
        int money;
        string code;
        list <Bet> bets;

    public:
        Player(string DNI, string CODE, string NAME="", string SURNAME="", 
               int AGE=0, string ADDRESS="", string LOCALITY="", string PROVINCE="", 
               string COUNTRY="") : Person(DNI, NAME, SURNAME, AGE, ADDRESS, LOCALITY, PROVINCE, COUNTRY){
            code=CODE; 
            money=1000;
        }
        inline void setCode(string CODE){code=CODE;}
        inline string getCode() const {return code;}
        inline void setMoney(int MONEY){money=MONEY;}
        inline int getMoney() const {return money;}
        inline list <Bet> getBets() const {return bets;}
        void setBets();
};
#endif