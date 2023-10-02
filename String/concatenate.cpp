#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string concat(string a, string b){
	string cad=a+b;
	return cad;
}

int main(){
	string a;
	cout<<"String a: ";
	getline(cin, a);
	string b;
	cout<<"String b (a+b): ";
	getline(cin, b);
	cout<<"Result: "<<concat(a, b)<<endl;
}