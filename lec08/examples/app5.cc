// app5.cc
#include <iostream>
using namespace std;
#include "Datum.h"

int main() {
  Datum d1( 1.2, 0.3 );
  d1.print();

  Datum d3 = 0.5 * d1;
  d3.print();
  cout << d3 << endl;

  return 0;
}
