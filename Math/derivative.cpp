#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std; 

double derivative(double(*f)(double), double x){
	double h=0.000000001;
	double res=(f(x+h)-f(x))/h;
	return res;
}


double const_f(double x){return x;}
double f2(double x){return x*x+sin(x);}
double f3(double x){return x*sin(x)+x*x*log(x);}

int main(){ 
	cout<<"X: "<<derivative(const_f,0)<<endl;
	cout<<"Sin(π): "<<derivative(sin,M_PI)<<endl;
	cout<<"Sin(π/2): "<<derivative(sin,M_PI/2)<<endl;
	cout<<"Cos(π/2): "<<derivative(cos,M_PI/2)<<endl;
	cout<<"Cos(π/5): "<<derivative(cos,M_PI/5)<<endl;
	cout<<"3*sin(3)+3*3*log(3): "<<derivative(f3,3)<<endl;

}