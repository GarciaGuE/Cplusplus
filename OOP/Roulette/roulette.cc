#include "roulette.h"
#include <iostream>
#include <fstream>


using namespace std; 

//Save the players in a file
void Roulette::writePlayers(){
    string fichero="players.txt";    
    ofstream fs;
    fs.open(fichero);
    fs.clear();
    list <Player>::iterator it;
    for(it=players_.begin(); it!=players_.end(); it++){
        fs<<it->getDNI()<<","<<it->getCode()<<","<<it->getName()<<","
          <<it->getSurname()<<","<<it->getAddress()<<","<<it->getLocality()
          <<","<<it->getProvince()<<","<<it->getCountry()<<","<<it->getMoney()<<endl;
    }
    fs.close();
}

//Add a player to the list
bool Roulette::addPlayer(Player j){
    list <Player>::iterator it;
    for(it=players_.begin(); it!=players_.end(); it++)
        if(j.getDNI()==it->getDNI())
            return false;
    players_.push_back(j);
    string fichero=j.getDNI()+".txt";
    ofstream fs;
    fs.open(fichero);
    fs.close();
    return true;
}

//Delete a player from the list with his DNI
int Roulette::deletePlayer(string DNI){
    if(players_.empty())
        return -1;
    list <Player>::iterator it;
    for(it=players_.begin(); it!=players_.end(); it++){
        if(DNI==it->getDNI()){
            players_.erase(it);
            return 1;
        }
    }
    return -2;
}

//Delete a player from the list
int Roulette::deletePlayer(Player j){
    if(players_.empty())
        return -1;
    list <Player>::iterator it;
    for(it=players_.begin(); it!=players_.end(); it++){
        if(j.getDNI()==it->getDNI()){
            players_.erase(it);
            return 1;
        }
    }
    return -2;
}

//Read the players from a file
void Roulette::readPlayers(){
    players_.clear();
    string fichero="players.txt";   
    ifstream fe;
    fe.open(fichero);
    char edad[100];
    string dni, codigo, name, surname, address, locality, province, country, money;
    while(getline(fe, dni, ',')){
        getline(fe, codigo, ',');
        getline(fe, name, ',');
        getline(fe, surname, ',');
        getline(fe, address, ',');
        getline(fe, locality, ',');
        getline(fe, province, ',');
        getline(fe, country, ',');
        getline(fe, money, '\n');
        Player j(dni,codigo, name, surname, atoi(edad), address ,locality, province, country);
        j.setMoney(stoi(money));
        players_.push_back(j);
    }
    fe.close();
}

//Calculate the prize of the players
void Roulette::getPrize(){
    list <Player>::iterator it;
    list <Bet> bets;
    list <Bet>::iterator ita;
    for(it=players_.begin(); it!=players_.end(); it++){
        it->setBets();
        bets=it->getBets();
        for(ita=bets.begin(); ita!=bets.end(); ita++){
            switch(ita->type){
                case 1:
                    if(getBall()==stoi(ita->value)){
                        it->setMoney(it->getMoney()+35*ita->quantity);
                        setBank(getBank()-35*ita->quantity);
                    }
                    else{
                        it->setMoney(it->getMoney()-ita->quantity);
                        setBank(getBank()+ita->quantity);
                    }
                break;
                case 2:
                    if(ita->value=="red"){
                        if(getBall()==(1|3|5|7|9|12|14|16|18|19|21|23|25|27|30|32|34|36)){
                            it->setMoney(it->getMoney()+ita->quantity);
                            setBank(getBank()-ita->quantity);
                        }
                        else{
                            it->setMoney(it->getMoney()-ita->quantity);
                            setBank(getBank()+ita->quantity);
                        }
                    }
                    else if(ita->value=="black"){
                        if(getBall()==(2|4|6|8|10|11|13|15|17|20|22|24|26|28|29|31|33|35)){
                            it->setMoney(it->getMoney()+ita->quantity);
                            setBank(getBank()-ita->quantity);
                        }
                        else{
                            it->setMoney(it->getMoney()-ita->quantity);
                            setBank(getBank()+ita->quantity);
                        }
                    }
                break;
                case 3:
                    if(ita->value=="even"){
                        if(getBall()%2==0 && getBall()!=0){
                            it->setMoney(it->getMoney()+ita->quantity);
                            setBank(getBank()-ita->quantity);
                        }
                        else{
                            it->setMoney(it->getMoney()-ita->quantity);
                            setBank(getBank()+ita->quantity);
                        }
                    }
                    else if(ita->value=="odd"){
                        if(getBall()%2!=0){
                            it->setMoney(it->getMoney()+ita->quantity);
                            setBank(getBank()-ita->quantity);
                        }
                        else{
                            it->setMoney(it->getMoney()-ita->quantity);
                            setBank(getBank()+ita->quantity);
                        }
                    }
                break;
                case 4:
                     if(ita->value=="high"){
                        if(getBall()>=19 && getBall()<=36){
                            it->setMoney(it->getMoney()+ita->quantity);
                            setBank(getBank()-ita->quantity);
                        }
                        else{
                            it->setMoney(it->getMoney()-ita->quantity);
                            setBank(getBank()+ita->quantity);
                        }
                    }
                    else if(ita->value=="low"){
                        if(getBall()>=1 && getBall()<=18){
                            it->setMoney(it->getMoney()+ita->quantity);
                            setBank(getBank()-ita->quantity);
                        }
                        else{
                            it->setMoney(it->getMoney()-ita->quantity);
                            setBank(getBank()+ita->quantity);
                        }
                    }
                break;

                default:
                break;
            }
        }
    }
}

//Change the bank and validate its value
bool Roulette::setBank(int BANK){
    return (BANK>=0) ? (bank_=BANK, true) : false;
}

//Change the ball and validate its value
bool Roulette::setBall(int BALL){
    return (BALL>=0 && BALL<=36) ? (ball_=BALL, true) : false;
}

