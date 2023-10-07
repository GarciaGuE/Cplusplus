#ifndef FUNCTION_H
#define FUNCTION_H
#include <string>
using namespace std;

struct Student{
	string dni;
	int age;
	float mark;
};

int read(string file_path, Student v[]);
bool DNI(string& cad);
bool save(string file_path, Student v[], int nstudents);
void print_student(int a);

#endif