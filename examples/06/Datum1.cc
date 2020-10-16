#include "Datum1.h"
#include <iostream>
#include <cmath>

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

Datum Datum::operator+( const Datum& rhs) {

  // sum of central values
  double val = value_ + rhs.value_;
  // assume data are uncorrelated. sum in quadrature of errors
  double err = sqrt( error_*error_ + (rhs.error_)*(rhs.error_) );

  // result of the sum
  return Datum(val,err);
}
