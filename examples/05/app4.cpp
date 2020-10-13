#include "Datum.h"

int main() {

  Datum d1(-0.23, 0.05); // provide arguments
  d1.print();

  Datum d2(5.23); // default error ...
  d2.print();

  Datum d3; // default value and error!
  d3.print();

  return 0;
}
