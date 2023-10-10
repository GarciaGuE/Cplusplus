#ifndef ROULETTE_H
#define ROULETTE_H
#include "croupier.h"
#include "player.h"
#include "person.h"
#include <list>
#include <ctime>
#include <string>

using namespace std;

class Roulette{  
    private:
        int bank_, ball_;
        list <Player> players_;
        Croupier crup_;

    public:
        Roulette(Croupier croupier):crup_(croupier){
            ball_=-1; 
            bank_=1000000; 
            srand(time(NULL));
        }
        inline int getBank() const {return bank_;}
        inline int getBall() const {return ball_;}
        bool setBank(int BANK);
        bool setBall(int BALL);
        inline Croupier getCroupier() const {return crup_;}
        inline void setCroupier(Croupier &CROUPIER){crup_=CROUPIER;}
        inline list <Player> getPlayers() const {return players_;}
        bool addPlayer(Player j);
        int deletePlayer(string DNI);
        int deletePlayer(Player j);
        void writePlayers();
        void readPlayers();
        inline void spinRoulette(){ball_=(rand()%37);}
        void getPrize();
};
#endif

