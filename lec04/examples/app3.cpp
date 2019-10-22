// app3.cpp
#include <iostream>
using namespace std;
#include "Counter.h"

Counter makeCounter() {
  Counter c;
  return c;
}

void printCounter(Counter& counter)  {
  cout << "counter value: " << counter.value() << endl;
}

void printByPtr(Counter* counter)  {
  cout << "counter value: " << counter->value() << endl;
}

#include "Counter.h"

int main() {
  Counter counter;
  counter.increment(7);

  Counter c2 = makeCounter();
  c2.increment();

  printCounter( counter );
  printCounter( c2 );

  return 0;
}
