// example5-bad.cpp
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

#include "DummyBis.h"

int main() {
  DummyBis<std::string> d1( std::string("test") );

  double x = 1.23;
  DummyBis<double> d2( x );

  d1.print();
  d2.print();

  return 0;
}
