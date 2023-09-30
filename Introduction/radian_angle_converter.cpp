#include <iostream>
#include <cmath>
using namespace std;

//Radian/Angle converter
int main(){
	float angle,radian;
    int opt;
	cout<<"Choose an option radian to angle(0) or angle to radian(else): ";
    cin>>opt;
    if (opt==0){
        cout<<"Radian value: ";
	    cin>>radian;
	    angle=radian*(180/M_PI);
	    cout<<"Angle value: "<<angle<<endl;
    }
    else{
        cout<<"Angle value: ";
	    cin>>angle;
	    radian=angle*(M_PI/180);
	    cout<<"Radian value: "<<radian<<endl;
    }
}

