#include <iostream>
using namespace std;

int convertor(int celsius) {
int kelvin = celsius + 273;
return kelvin;
}

int main() {
  int celsius;

cout << "enter celsius : ";
cin >>  celsius;


cout <<  "The temperature in Kelvin is: " << convertor(celsius) << endl;

cout << "celius : "  << celsius << endl;

  return 0;
}
