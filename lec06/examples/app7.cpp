// app7.cpp
#include <iostream>
using namespace std;

#include "Datum.h"


int main() {
  Datum d1( 1.2, 0.3 );
  Datum d3( -0.2, 1.1 );

  d1 += d3;

  if( d1 <= d3 ) {
    cout << "d1 < d3. d1 is:" << endl;
  } else {
    cout << "d3 < d1. d3 is:" << endl;
  }

  return 0;
}
