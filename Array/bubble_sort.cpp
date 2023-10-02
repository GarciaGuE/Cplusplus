#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

void bble_sort(float v[], int n){
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(v[i]>v[j]){
				float aux=v[i];
				v[i]=v[j];
				v[j]=aux;
			}
		}
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

    cout<<endl<<"Array: ";
    for(int i=0; i<n; i++) {
        cout<<array[i]<<" ";
        if(i==n-1) cout<<endl<<"Sorted Array: ";
    }
    bble_sort(array, n);
    for(int j=0; j <n; j++) { 
        cout<<array[j]<<" ";
    }
    cout<<endl; 
}