#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

template <size_t rows, size_t cols>
void transpose(float (&m)[rows][cols]){
	for(int i=0; i<rows; i++){
		for(int j=i; j<cols; j++){
			if(i!=j){
			    swap(m[i] [j], m[j] [i]);
			}
		}
	}
}
 
int main(){ 
	float matrix[6][6]={
        {3, 8, 1, 9, 5, 7},
        {2, 4, 6, 8, 2, 1},
        {7, 9, 3, 6, 4, 5},
        {5, 2, 8, 1, 9, 3},
        {6, 3, 7, 4, 8, 2},
        {1, 5, 9, 7, 6, 4}};
    transpose(matrix);

    cout<<"Transpose: "<<endl;
	for(int i=0; i<6; i++){
		for(int j=0; j<6; j++){
			cout<<matrix[i][j]<<" ";
		}
        cout<<endl;
	}
}