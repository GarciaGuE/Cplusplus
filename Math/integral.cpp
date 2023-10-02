#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

double integral(double(*f)(double), double a, double b){
    int n=1000;
    double interval=b-a;
    double d=interval/n;
    double sum=0;
    for(double i=1; i<n; i++){
        sum+=2*f(a+i*d);
    }
    double res=d/2*(f(a)+sum+f(b));
    return res;
}

double const_f(double x){return x;}

int main(){ 
	cout<<"Const x(0-1): "<<integral(const_f,0,1)<<endl;
	cout<<"Sin x(0-1): "<<integral(sin,0,1)<<endl;
	cout<<"Cos x(0-1): "<<integral(cos,0,1)<<endl;
	cout<<"Exp x(0-2): "<<integral(exp,0,2)<<endl;
	cout<<"Log x(1-2): "<<integral(log,1,2)<<endl;
}