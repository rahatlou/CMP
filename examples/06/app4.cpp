// app4.cpp
#include <iostream>
using namespace std;

#include "Datum.h"


int main() {
  const Datum d1( 1.2, 0.3 );
  Datum d2( -0.4, 0.4 );

  Datum d3 = d1;
  d3.print();

  Datum d4;
  d4.operator=(d2);
  d4.print();

  return 0;
}
