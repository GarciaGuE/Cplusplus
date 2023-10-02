#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "function.h"
using namespace std;

int main(int argc, char** argv){
	if(argc!=2){
		cout<<"ERROR: Invalid arguments"<<endl;
		cout<<"USAGE: "<< argv[0] << " [file]"<<endl;
		return -1;
	}
	Student students[10];
	string file=argv[1];
	int n=read(file, students);
	if(n==-1){
		cout<<"ERROR: File doesn't exist, opening a new one"<<endl;
		n=0;
	}
	else{
		n--;
	}
	int opt=0;
	while(opt!=6){
		cout<<"Select an option:"<<endl;
		cout<<"		1. Add student"<<endl;
		cout<<"		2. Print student data"<<endl;
		cout<<"		3. Print all students data"<<endl;
		cout<<"		4. Modify student"<<endl;
		cout<<"		5. Delete student"<<endl;
		cout<<"		6. Exit"<<endl;
		
		cin>>opt;
		switch(opt){
		case 1:{
			if(n<10){
				cin.ignore();
				cout<<"DNI: ";
				getline(cin, students[n].dni);	
				while(DNI(students[n].dni)!=true){
					cout<<"Invalid DNI, write it again: "<<endl;
					getline(cin, students[n].dni);
					cout<<DNI(students[n].dni)<<endl;
				}
			cout<<"Age: ";
			cin>>students[n].age;
			cout<<"Mark: ";
			cin>>students[n].mark;
			n++;
			}
		}
			break;
		case 2:{
			if(n>0){
				int m=0;
				print_student(n);
				cout<<"Write a student: ";	
				cin>>m;
				cout<<"Student"<<m<<endl;
				m--;
				cout<<"DNI: "<<students[m].dni<<endl;
				cout<<"Age: "<<students[m].age<<endl;
				cout<<"Mark: "<<students[m].mark<<endl;
			}
			else{
				cout<<"No data"<<endl;
			}
		}
			break;
		case 3:{
			if(n>0){
				for(int i=0; i<n; i++){
					cout<<"Student"<<i+1<<endl;
					cout<<"DNI: "<<students[i].dni<<endl;
					cout<<"Age: "<<students[i].age<<endl;
					cout<<"Mark: "<<students[i].mark<<endl;
					cout<<endl;
				}
			}
			else{
				cout<<"No data"<<endl;
			}
		}
			break;
		case 4:{
			if(n>0){
				int mod=0;
				print_student(n);
				cout<<"Write a student: ";
				cin>>mod;
				mod--;
				cin.ignore();
				cout<<"DNI: ";
				getline(cin, students[mod].dni);	
					while(DNI(students[mod].dni)!=true){
						cout<<"Invalid DNI, write it again: ";
						getline(cin, students[mod].dni);
						cout<<DNI(students[mod].dni)<<endl;
					}
				cout<<"Age: ";
				cin>>students[mod].age;
				cout<<"Mark";
				cin>>students[mod].mark;
			}
			else{
				cout<<"No data"<<endl;
			}
		}
			break;
		case 5:{
			if(n>0){
				int del=0;
				print_student(n);
				cout<<"Which student do you want to delete?"<<endl;
				cin>>del;
				del--;
				for(int j=0; j<n; j++){
					students[del+j]=students[del+j+1];
				}
				n--;
			}
			else{
				cout<<"No data"<<endl;
			}
		}
			break;
		}
	}
	if(!save(file, students, 10)){
		cout<<"ERROR: File couldn't be saved"<<endl;
	}
	return 0;
}