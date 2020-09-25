// app11.cpp
#include <iostream>
using namespace std;
#include "Datum.h"

int main() {
  Datum d1( 1.2, 0.3 );
  Datum d2( 3.1, 0.4 );

  cout << "d1: " << d1 << "\t d2: " << d2 << endl;

  d1 += d2;
  cout << "d1+d2 = " << d1 << endl;

  return 0;
}
