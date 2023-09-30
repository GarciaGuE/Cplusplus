#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main(){
  //Types of Variables
  int i=-1; //+, -, *, / sqrt(x), pow(x)...
  i++;
  i--;
  i+=3;
  i-=1;
  i*=4;
  i/=1;

  unsigned int ui= 1;

  float f=1.1121;

  int a=int(f);

  double d=2.1928128740192;

  float p=d;

  bool b=true;

  char c='a';

  string cad="Hello";

  int* pointer=&i;
  //*pointer=20;

  int array[5]={0,1,2,3,4};

  struct Dog
  {
    string name;
    int weight;
  };
  Dog dog;
  dog.name="Bobby";
  dog.weight=20;

  enum Week {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday}
  Week=Sunday;
  
  int in;
  cout<<"Numeric value: ";
  cin>>in;

  //Print
  cout<<"Int: "<<i<<endl
      <<"Unsigned Int: "<<ui<<endl
      <<"Float: "<<f<<endl
      <<"Cast int: "<<a<<endl
      <<setprecision(15)<<"Double: "<<d<<endl
      <<"Lost of precision: "<<p<<endl
      <<"Bool: "<<b<<endl
      <<"Character: "<<c<<endl
      <<"String: "<<cad<<endl
      <<"Pointer: "<<pointer<<endl
      <<"Array: "<<array[4]<<endl
      <<"Struct: "<<dog.name<<" "<<dog.weight<<endl
      <<"Enum: "<<Week<<endl
      <<"Input: "<<in<<endl;

  return 0;
}
