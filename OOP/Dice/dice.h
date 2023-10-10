#ifndef DICE_H
#define DICE_H
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

class Dice{
    private:                                           
        int d1, avg1, count1;
        int d2, avg2, count2;
        vector <int> v1, v2;
        void pushDie1(int &valor);
        void pushDie2(int &valor);

    public:
        Dice();
        Dice(int &die1, int &die2);
        void roll();
        inline int getRolls1() const {return count1;}  
        inline int getRolls2() const {return count2;}
        inline int getDie1() const {return d1;}
        inline int getDie2() const {return d2;}
        bool setDie1(int dado1);
        bool setDie2(int dado2);
        inline int getAdd() const {return d1+d2;}   
        float getAvg1() const;
        float getAvg2() const;
        inline int getDiff() const {return abs(d1-d2);}
        void getLast1(int v[]) const;                
        void getLast2(int v[]) const;
        friend ostream &operator<<(ostream &out, const Dice &d);
        friend istream &operator>>(istream &in, Dice &d);
};
#endif



