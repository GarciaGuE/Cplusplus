#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    srand(time(NULL));                      //Rand seed time(NULL) returns “UNIX Epoch”, this is seconds since 00:00:00 1 January 1970
    int x;
    int numero=(rand()%10);
    bool encontrado=false;
    cout<<"Guess the number (0-9): ";
    cin>>x;
    while(!encontrado){
        if(numero==x){
            cout<<"Correct"<<endl;
            encontrado=true;
        }
        else{
            cout<<"Try again: ";
            cin>>x;
        }
    }
}
