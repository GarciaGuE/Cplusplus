#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

template <size_t rows, size_t cols>
void stats(float (&m)[rows] [cols], float* res){
	float s=0;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			s=s+m[i][j];
		}
	}
	res[0]=s/(rows*cols);
	float z=0;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			z=z+(m[i][j]-res[0])*(m[i][j]-res[0]);
		}
	}
	res[1]=sqrt(z/16);
}

int main(){ 
	float matrix[3][3]={
        {3.14, 2.71, 1.62},
        {0.5, 1.0, 2.0},
        {10.5, 7.3, 4.8}
    };
    float statistics[2];
    stats(matrix, statistics);

    cout<<"M="<<statistics[0]<<endl
        <<"σ="<<statistics[1]<<endl;

}
