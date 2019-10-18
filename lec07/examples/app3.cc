// app10.cpp
#include <iostream>
using namespace std;
#include "Datum.h"

int main() {
  Datum d1( 1.2, 0.3 );
  d1.print();

  // global function for double * Datum
  Datum d3 = productDoubleDatum(0.5, d1);
  d3.print();

  return 0;
}
