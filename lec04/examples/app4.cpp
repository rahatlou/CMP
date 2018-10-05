// app4.cpp
#include "Datum.h"
#include <iostream>

void print(Datum& input) {
  using namespace std;
  cout << "input: " << input.value()
       << " +/- " << input.error()
       << endl;
}

#include "Datum.h"

int main() {
  Datum d1(-1.4,0.3);
  print(d1);

  return 0;
}
