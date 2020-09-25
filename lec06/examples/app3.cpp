// app3.cpp
#include <iostream>
using namespace std;

#include "Datum1.h"


int main() {
  const Datum d1( 1.2, 0.3 );
  const Datum d2( -0.4, 0.4 );

  Datum d3 = d1 + d2;
  d3.print();

  return 0;
}
