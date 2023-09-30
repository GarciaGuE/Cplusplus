#include <iostream>
#include <cmath>
using namespace std;

//The area of ​​a circle known as the radius
int main(){
	float area,radius;
	cout<<"Radius value: ";
	cin>>radius;
	area=radius*radius*M_PI;
	cout<<"Area value :"<<area<<endl;
}