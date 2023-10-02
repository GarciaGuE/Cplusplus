#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std; 

void invert(float v1[], float v2[], int n){
	for(int i=0; i<n; i++){
		v2[n-i-1]=v1[i];
	}
}

int main(){
    int n;
    cout<<"How many numbers do you want to save?"<<endl;
    cin>>n;

    float array[n];
    for(int i=0; i<n; i++){
        cout<<"Position "<<i<<": ";
        cin>>array[i];
    }   

    float inverse[n];
    invert(array, inverse, n);

    cout<<endl<<"Array: ";
    for(int i=0; i<n; i++) {
        cout<<array[i]<<" ";
        if(i==n-1) cout<<endl<<"Inverted Array: ";
    }
    
    for(int j=0; j <n; j++) { 
        cout<<inverse[j]<<" ";
    }
    cout<<endl;
}


