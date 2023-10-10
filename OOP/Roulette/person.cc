#include "person.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//Change the age and validate its value
bool Person::setAge(int AGE){
    return (AGE>=0) ? (age=AGE, true) : false;
}

//Check if the person is legal
bool Person::legal(){
    return (getAge()>18) ? true : false;
}