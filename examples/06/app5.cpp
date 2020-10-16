// app5.cpp
#include <iostream>
using namespace std;

#include "Datum.h"


int main() {
  Datum d1( 1.2, 0.3 );
  const Datum d2 = d1; // OK.. init the constant

  Datum d3( -0.2, 1.1 );
  d2 = d3; // error!

  return 0;
}
