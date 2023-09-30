#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> numbers;

    //Add some numbers 
    numbers.push_back(10);
    numbers.push_back(25);
    numbers.push_back(5);
    numbers.push_back(100);
    numbers.push_back(50);

    int largest = numbers.front(); 

    for (const int& number : numbers) {
        if (number > largest) {
            largest = number;
        }
    }

    cout<<"The largest number is: " <<largest<<endl;

    numbers.remove(largest);
    numbers.pop_back();

    for (const int& number : numbers) {
        std::cout << number <<endl;
    }

    return 0;
}
