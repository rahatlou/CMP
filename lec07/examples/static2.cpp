// static2.cpp

#include <iostream>
#include <string>
using namespace std;
#include "Unit2.h"


int main() {
  Unit john("John");
  Unit* fra = new Unit("Francesca");
  cout << "john.getCount(): " << john.getCount() << endl;
  cout << "fra->getCount(): " << fra->getCount() << endl;

  delete fra;
  return 0;
}
