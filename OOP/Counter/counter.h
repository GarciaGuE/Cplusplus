#ifndef COUNTER_H
#define COUNTER_H
#include <list>

class Counter{  
    private:
        int value_, min_, max_;
        std::list <int> operations;
        void Value();

    public:
        Counter(int value=0, int min=0, int max=1000){
            if(value<min || value>max || min>max){
                value_=0;
                min_=0;
                max_=1000;
            }
            else{
                value_=value;
                min_=min;
                max_=max;
            }
        }
        Counter operator=(const int &value);
        Counter operator=(const Counter &c);
        Counter operator++(void);
        Counter operator++(int);
        Counter operator--(void);
        Counter operator--(int);
        Counter operator+(const int &number);
        friend Counter operator+(const int &number, const Counter &c);
        Counter operator-(const int &number);
        friend Counter operator-(const int &number, const Counter &c);
        bool undo(int n=1);
        inline int get() const {return value_;}
};
#endif

