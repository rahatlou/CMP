#include "Datum2.h"
#include <iostream>

Datum::Datum() {
  value_ = 0.;
  error_ = 0.;
}

Datum::Datum(double x, double y) {
  value_ = x;
  error_ = y;
}

Datum::Datum(const Datum& datum) {
  value_ = datum.value_;
  error_ = datum.error_;
}

double
Datum::significance() const {
  return value_/error_;
}

void Datum::print() const {
  using namespace std;
  cout << "datum: " << value_ 
       << " +/- " << error_ << endl;
}
