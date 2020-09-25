// app9.cpp
#include <iostream>
using namespace std;
#include "Datum.h"

int main() {
  Datum d1( 1.2, 0.3 );
  d1.print();

  Datum d2 = d1 * 1.5;
  d2.print();

  return 0;
}
