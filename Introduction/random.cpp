#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	int max=100;
    int secs=time(0);
    srand(secs);
    int random_number=rand()%max; //0-100
    cout<<"Result: "<<random_number<<endl;
}