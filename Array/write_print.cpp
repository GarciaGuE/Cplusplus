#include <iostream>
using namespace std;

void write(float v[], int n){
	for(int i=0; i<n;i++){
        cout<<"Position "<<i<<": ";
		cin>>v[i];
	}
}

void print(float v[], int n){
	for(int i=0; i<n; i++){
		cout<<"Position "<<i<<": "<<v[i]<<endl;
	}
}

int main() {
	int n;
	cout<<"How many numbers do you want to write?"<<endl;
	cin>>n;
    cout<<endl;
	float v[n];
	write(v, n);
    cout<<endl<<endl;
	print(v, n);
}