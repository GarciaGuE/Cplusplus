#include <iostream>
#include <list>
using namespace std;

int main() {
    list<float> numbers;

    //Add some numbers
    float x=1;
    while(x!=0.0){
        cout<<"Add a number(0.0 to exit): ";
        cin>>x;
        numbers.push_back(x);
    }

    numbers.pop_back();
    int largest = numbers.front(); 

    for (const int& number : numbers) {
        if (number > largest) {
            largest = number;
        }
    }

    cout<<"The largest number is: " <<largest<<endl;

    numbers.remove(largest);

    for (const int& number : numbers) {
        std::cout << number <<endl;
    }

    return 0;
}
