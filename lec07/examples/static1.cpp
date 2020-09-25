// static1.cpp

#include <iostream>
#include <string>
using namespace std;
#include "Unit.h"


int main() {
  Unit john("John");
  cout << john << endl;

  cout << "&john.counter_: " << &john.counter_ << endl;

  Unit* fra = new Unit("Francesca");
  Unit pino("Pino");
  cout << "&pino.counter_: " << &pino.counter_ << endl;

  cout << "&(fra->counter_): " << &(fra->counter_) << endl;
  cout << pino << endl;

  delete fra;

  cout << pino << endl;

  return 0;
}
