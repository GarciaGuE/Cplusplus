#include <iostream> 
using namespace std;

// Return how many times we find a number inside a matrix
template <size_t rows, size_t cols>
int find_in_matrix(float (&m)[rows][cols], float value){
	int n=0;
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
			if (m[i][j]==value) n++;
    cout<<n<<endl;
	return n;
}

// Testing
bool test_find_in_matrix(){
    cerr<<"testing..."<<__func__<<": ";
    float m[6][6]={ {1,1,1,1,1,1},{2,2,2,2,2,2},{3,3,3,3,3,3},{4,4,4,4,4,4},{5,5,5,5,5,5},{-1,6,6,6,6,6}};
    float m2[5][6]={ {1,1,1,1,1,1},{2,2,2,2,2,2},{3,3,3,3,3,3},{4,4,4,4,44,4},{5,5,5,5,5,5}};
    if (find_in_matrix(m,3)!=6)return false;
    if (find_in_matrix(m,-1)!=1)return false;
    if (find_in_matrix(m2,44)!=1)return false;
    return true;
}

// Main program
int main(){
		if( test_find_in_matrix()) cout<<"Correcto"<<endl;
		else cout<<"Error"<<endl;
}