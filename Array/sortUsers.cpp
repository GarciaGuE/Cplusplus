#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Person{
    string name;
    int age;
    string favoriteColor;
};

// Sort Container by name function
bool sortByName(const Person &lhs, const Person &rhs) { return lhs.name < rhs.name; }

// Sort Container by age function
bool sortByAge(const Person &lhs, const Person &rhs) { return lhs.age < rhs.age; }

// Sort Container by favorite color
// We can just sort alphabetically and then it will group the
// color together.
bool sortByColor(const Person &lhs, const Person &rhs) { return lhs.favoriteColor < rhs.favoriteColor; }

// A global const variable to hold how many people to ask for input for.
const unsigned numberOfPeople=2;

int main(){
    vector<Person> people(numberOfPeople);

    for(vector<Person>::size_type i=0; i!=numberOfPeople; ++i){
        cout<<"Person #"<<i+1<<" name: ";
        cin>>people[i].name;

        cout<<"Person #"<<i+1<<" age: ";
        cin>>people[i].age;

        cout<<"Person #"<<i+1<<" favorite color: ";
        cin>>people[i].favoriteColor;
    }

    cout<<"\n\n";

    // Sort by name
    sort(people.begin(), people.end(), sortByName);
    cout<<"Sorted by name: ";
    for(Person &n : people)
        cout<<n.name<<" ";

    cout<<endl;

    // Sory by age
    sort(people.begin(), people.end(), sortByAge);
    cout<<"Sorted by age: ";
    for(Person &n : people)
        cout<<n.age<<" ";

    cout<<endl;

    // Sort by color
    sort(people.begin(), people.end(), sortByColor);
    cout<<"Sorted by favorite color: ";
    for(Person &n : people)
        cout<<n.favoriteColor<<" ";

    cout<<endl;
    return 0;
}