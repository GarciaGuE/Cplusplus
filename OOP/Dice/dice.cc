#include "dice.h"
#include <iostream>
#include <ctime>
#include <vector>

using namespace std; 

//Default constructor declaration
Dice::Dice(){
    d1=d2=1;
    srand(time(NULL));
    count1=count2=0;
    avg1=avg2=0;
    v1.resize(5,0);
    v2.resize(5,0);
}

//Default constructor declaration with previous values
Dice::Dice(int &die1, int &die2){
    d1=die1;
    d2=die2;
    srand(time(NULL));
    count1=count2=0;
    avg1=avg2=0;
    v1.resize(5,0);
    v2.resize(5,0);
}

//Initializes the values of the dice
void Dice::roll(){
    d1=((rand()%6)+1);
    pushDie1(d1);
    avg1=avg1+d1;
    d2=((rand()%6)+1);
    pushDie2(d2);
    avg2=avg2+d2;
    count1++;
    count2++;
}

//Sets the value of the die 1
bool Dice::setDie1(int die1){
    if(die1>=1 && die1<=6){
        d1=die1;
        avg1=avg1+d1;
        count1++;
        pushDie1(d1);
        return true;
    }
    return false;
}

//Sets the value of the die 2
bool Dice::setDie2(int die2){
    if(die2>=1 && die2<=6){
        d2=die2;
        avg2=avg2+d2;
        count2++;
        pushDie2(d2);
        return true;
    }
    return false;
}

//Save the last value of the die 1
void Dice::pushDie1(int &valor){
    for(int i=4; i>0; i--)
        v1[i]=v1[i-1];
    v1[0]=valor;
}

//Save the last value of the die 2
void Dice::pushDie2(int &valor){
    for(int i=4; i>0; i--)
        v2[i]=v2[i-1];
    v2[0]=valor;
}

//Calculates the average of the last values of the die 1
float Dice::getAvg1() const{
    if(count1==0)
        return 0;
    float avg=(float) avg1 / (float) count1;
    return avg;
}

//Calculates the average of the last values of the die 2
float Dice::getAvg2() const{
    if(count2==0)
        return 0;
    float avg= (float) avg2/ (float) count2;
    return avg;
}

//Gets the last 5 values of the die 1
void Dice::getLast1(int v[]) const{
    for(int i=0; i<5; i++)
        v[i]=v1[i];
}

//Gets the last 5 values of the die 2
void Dice::getLast2(int v[]) const{
    for(int i=0; i<5; i++)
        v[i]=v2[i];
}

//Own inserter
ostream &operator<<(ostream &out, const Dice &d){
    out<<"Die 1 Value="<<d.getDie1()<<endl;
    out<<"Die 2 Value="<<d.getDie2()<<endl;
    return out;
};

//Own extractor
istream &operator>>(istream &in, Dice &d){
    int valor=0;
    while(!d.setDie1(valor)){
        cout<<"Die 1: ";
        in>>valor;
        if(!d.setDie1(valor))
            cout<<"Incorrect Value"<<endl;
    }
    valor=0;
    while(!d.setDie2(valor)){
        cout<<"Die 2: ";
        in>>valor;
        if(!d.setDie2(valor))
            cout<<"Incorrect Value"<<endl;
    }
    return in;
};
