#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool palindrome(string& cad){
	int s=cad.size();
	for(int j=0; j<s; j++){
		cad[j]=toupper(cad[j]);
	}
	for(int i=0; i<s; i++){
		if(cad[i]!=cad[s-1-i]){
			return false;
		}
	}
	return true;
}

int main(){
	string cad;
	cout<<"Palindrome verification: ";
	getline(cin, cad);
	if(palindrome(cad))cout<<"TRUE"<<endl;
	else cout<<"FALSE"<<endl;
}