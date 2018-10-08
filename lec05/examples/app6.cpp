// app6.cpp
#include "Counter.h"
#include "Datum.h"
#include <iostream>
using namespace std;

int main() {

  Counter c1("c1");

  Counter* c2 = new Counter("c2");
  c2->increment(6);

  Counter* c3 = new Counter("c3");

  Datum d1(-0.3,0.07);

  Datum* d2 = new Datum( d1 );
  d2->print();

  delete c2; // de-allocate memory!
  delete c3; // de-allocate memory!
  delete d2;

  return 0;
}
