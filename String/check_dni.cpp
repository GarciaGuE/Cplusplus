#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool DNI(string& cad){
	int s=cad.size();
	if(s!=9){
		cout<<"DNI's size must be 9.";
		return false;
	}
	for(int i=0; i<s-1; i++){
		if(!isdigit(cad[i])){
			cout<<"Only the last character is not a digit.";
			return false;
		}
	}
	string letras="TRWAGMYFPDXBNJZSQVHLCKE";
	int num=stoi(cad);
	if(cad[8]!=letras[(num%23)]){
		cout<<"Letter must be valid.";
		return false;
	}
	return true;
}

int main(){
	string cad;
	cout<<"DNI checking: ";
	getline(cin, cad);
	while(!DNI(cad)){
		cout<<" Incorrect, try again: ";
		getline(cin, cad);
	}
    cout<<"OK, it's valid"<<endl;
}