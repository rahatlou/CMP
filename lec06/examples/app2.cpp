// app1.cpp
#include <iostream>
using namespace std;

#include "Datum.h"


int main() {
  Datum d1( 1.2, 0.3 );
  Datum d2( -0.4, 0.4 );

  Datum d3 = d1 + d2;
  Datum d4 = d1.sum( d2 );
  d3.print();
  d4.print();

  return 0;
}
