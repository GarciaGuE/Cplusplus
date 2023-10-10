#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person{
    private:
        string dni, name, surname, address, locality, province, country;
        int age;
        
    public:
        Person(string DNI, string NAME="", string SURNAME="", int AGE=0, string ADDRESS="", string LOCALITY="", string PROVINCE="", string COUNTRY=""){
            dni=DNI;
            name=NAME;
            surname=SURNAME;
            age=AGE;
            address=ADDRESS;
            locality=LOCALITY;
            province=PROVINCE;
            country=COUNTRY;
        }
        inline void setDNI(string DNI){dni=DNI;}
        inline string getDNI() const {return dni;}
        inline void setName(string NAME){name=NAME;}
        inline string getName() const {return name;}  
        inline void setSurname(string SURNAME){surname=SURNAME;}
        inline string getSurname() const {return surname;}
        inline string getSurname_Name() const {return surname+", "+name;}
        inline void setAddress(string ADDRESS){address=ADDRESS;}
        inline string getAddress() const {return address;}
        inline void setLocality(string LOCALITY){locality=LOCALITY;}
        inline string getLocality() const {return locality;}
        inline void setProvince(string PROVINCE){province=PROVINCE;}
        inline string getProvince() const {return province;}
        inline void setCountry(string COUNTRY){country=COUNTRY;}
        inline string getCountry() const {return country;}
        bool setAge(int AGE);
        inline int getAge() const {return age;}
        bool legal();
};
#endif

