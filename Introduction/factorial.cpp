#include <iostream>
using namespace std;

int factorial(int v) {
	int fac=1;
	    if (v<0){
		    return 0;
		}																			
		while(v>0) {																
		    fac=fac*v;
		    v--;
		}
    return fac;
}


int main() {
	int n;
	cout<<"Factorial number: "; cin>>n;
	cout<<"Factorial: "<<factorial(n)<<endl;
}
