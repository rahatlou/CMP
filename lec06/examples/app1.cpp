// app1.cpp
#include <iostream>
using namespace std;

#include "Datum.h"


int main() {
  Datum d1( 1.2, 0.3 );
  Datum d2( -0.4, 0.4 );

  cout << "input data d1 and d2: " << endl;
  d1.print();
  d2.print();


  Datum d3 = d1 + d2;

  
  cout << "output d3 = d1+d2 " << endl;
  d3.print();

  Datum d4 = d1.operator+( d2 );
  d4.print();


  return 0;
}
