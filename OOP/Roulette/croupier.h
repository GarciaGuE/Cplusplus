#ifndef CROUPIER_H
#define CROUPIER_H
#include "person.h"
#include <string>


using namespace std;

//Croupier inherits from Person
class Croupier : public Person{
    private:
        string code;

    public:
        Croupier(string DNI, string CODE, string NAME="", string SURNAME="", 
               int AGE=0, string ADDRESS="", string LOCALITY="", string PROVINCE="", 
               string COUNTRY="") : Person(DNI, NAME, SURNAME, AGE, ADDRESS, LOCALITY, PROVINCE, COUNTRY){
            code=CODE;
		}
        inline void setCode(string CODE){code=CODE;}
        inline string getCode() const {return code;}
};
#endif