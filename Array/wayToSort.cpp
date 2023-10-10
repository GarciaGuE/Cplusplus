#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//Establish a descending order
bool wayToSort(int i, int j){return i>j;}

int main(){
    vector<int> intVec ={56, 32, -43, 23, 12, 93, 132, -154};
    
    //Sorting the int vector and passing the function wayToSort as a parameter
    sort(intVec.begin(), intVec.end(), wayToSort);

    for(int i : intVec)
        cout<<i<<" ";
    
    cout<<endl;
    return 0;
}