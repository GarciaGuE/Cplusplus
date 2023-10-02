#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "function.h"
using namespace std;

int read(string file_path, Student v[]){
	ifstream file;
	file.open(file_path);
	if(file.is_open()==false){
		return -1;
	}	
	int z=0;
	while(!file.eof()){
		Student aux;
		file>>aux.dni;
		file>>aux.age;
		file>>aux.mark;
		v[z]=aux;
		z++;
	}
	file.close();
	return z;
}

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

bool save(string file_path, Student v[], int nstudents){
	ofstream file;
	file.open(file_path);
	if(!file.is_open()){
		return false;
	}
	for(int i=0; i<nstudents; i++){
		if(v[i].dni!= ""){
			file<<v[i].dni<<endl;
			file<<v[i].age<<endl;
			file<<v[i].mark<<endl;
		}
	}
	file.close();
	return true;
}

void print_student(int a){
	for(int k=1; k<=a; k++){
		cout<<"Student "<<k<<endl;
	}
}