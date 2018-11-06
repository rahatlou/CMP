// func2.cpp
#include <string>
#include <iostream>
using namespace std;

#include "BadFunction.h"
#include "Gauss.h"

int main() {

  BadFunction f1  = BadFunction("bad");

  Gauss g1("g1",0.,1.);

  cout << "g1.value(2.): " << g1.value(2.) << endl;

  cout << "g1.integrate(0.,1000.): " 
       << g1.integrate(0.,1000.) << endl;

  return 0;
}



