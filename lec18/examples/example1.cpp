// example1.cpp
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

#include "Vector3D.h"

template< typename  T >
void printObject(const T& input) {
  cout << "printObject(const T& input): with T = " << typeid( T ).name() << endl;
  cout << input << endl;
}

int main() {

  int i = 456;
  double x = 1.234;
  float  y = -0.23;
  string name("jane");
  Vector3D v(1.2, -0.3, 4.5);

  printObject( i );
  printObject( x );
  printObject( y );
  printObject( name );
  printObject( v );

  return 0;
}
