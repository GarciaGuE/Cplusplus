#include "player.h"
#include <fstream>
#include <string>

//Clear previous bets
void Player::setBets(){
    bets.clear();
    string fichero=getDNI()+".txt";
    ifstream fe;
    fe.open(fichero);
    string CODE, VALUE, QUANTITY;
    while(getline(fe, CODE, ',')){
        getline(fe, VALUE, ',');
        getline(fe, QUANTITY, '\n');
        Bet a={stoi(CODE), stoi(QUANTITY), VALUE}; // Change string to int
        bets.push_back(a);
    }
    fe.close();
}
