// app8.cpp
#include <iostream>
using namespace std;

#include "Datum.h"


int main() {
  Datum d1( 1.2, 0.3 );
  Datum d2( -3.4, 0.7 );
  d1.print();
  d2.print();

  Datum d3 = d1 * d2;
  Datum d4 = d1.operator*(d2);

  d3.print();
  d4.print();

  Datum d5 = d1 / d2;
  Datum d6 = d2/d1 ;
  d5.print();
  d6.print();

  return 0;
}
