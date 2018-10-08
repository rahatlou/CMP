#include "Datum.h"
#include <iostream>

Datum::Datum(double x, double y) {
  value_ = x;
  error_ = y;
}

Datum::Datum(const Datum& datum) {
  value_ = datum.value_;
  error_ = datum.error_;
}

double
Datum::significance() {
  return value_/error_;
}

void Datum::print() {
  using namespace std;
  cout << "datum: " << value_ 
       << " +/- " << error_ << endl;
}
