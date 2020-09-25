// static2.cpp

#include <iostream>
#include <string>
using namespace std;
#include "Unit3.h"


int main() {
  cout << "units: " << Unit::getCount() << endl;

  Unit john("John");
  Unit* fra = new Unit("Francesca");

  cout << "john.getCount(): " << john.getCount() << endl;
  cout << "fra->getCount(): " << fra->getCount() << endl;
  delete fra;

  cout << "units: " << Unit::getCount() << endl;

  return 0;
}
