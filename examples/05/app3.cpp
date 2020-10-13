// app3.cpp
#include "CounterOld.h" // old counter class
#include <iostream>
using namespace std;

int main() {

  Counter c1;

  c1.increment(); // no argument
  cout << "counter: " << c1.value() << endl;

  c1.increment(14); // provide argument, same function
  cout << "counter: " << c1.value() << endl;

  return 0;
}
