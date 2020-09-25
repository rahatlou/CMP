#include "Datum.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::ostream;
using std::endl;

Datum::Datum() {
  value_ = 0.0;
  error_ = 0.0;
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

Datum Datum::operator+( const Datum& rhs) const {

  // sum of central values
  double val = value_ + rhs.value_;
  // assume data are uncorrelated. sum in quadrature of errors
  double err = sqrt( error_*error_ + (rhs.error_)*(rhs.error_) );

  // result of the sum
  return Datum(val,err);
}


Datum Datum::sum( const Datum& rhs) const {

  // sum of central values
  double val = value_ + rhs.value_;
  // assume data are uncorrelated. sum in quadrature of errors
  double err = sqrt( error_*error_ + (rhs.error_)*(rhs.error_) );

  // result of the sum
  return Datum(val,err);
}

const Datum& Datum::operator+=(const Datum& rhs) {
  value_ += rhs.value_;
  error_ = sqrt( rhs.error_*rhs.error_ + error_*error_ );
  return *this;
}

const Datum& Datum::operator=(const Datum& rhs) {
  value_ = rhs.value_;
  error_ = rhs.error_;

  return *this;
}


bool Datum::operator<(const Datum& rhs) const {
  return ( value_ < rhs.value_ );
}


Datum Datum::operator*(const Datum& rhs) const {
  double val = value_*rhs.value_;

  // propagate correctly the error for x*y
  double err = sqrt( rhs.value_*rhs.value_*error_*error_ +
                     rhs.error_*rhs.error_*value_*value_ );
  return Datum(val,err);
}

Datum Datum::operator/(const Datum& rhs) const {
  double val = value_ / rhs.value_;

  // propagate correctly the error for x / y
  double err = fabs(val) * sqrt( (error_/value_)*(error_/value_) +
                           (rhs.error_/rhs.value_)*(rhs.error_/rhs.value_) );

  return Datum(val,err);
}

Datum Datum::operator*(const double& rhs) const {
  return Datum(value_*rhs,error_*rhs);
}

// global functions
Datum productDoubleDatum(const double& lhs, const Datum& rhs){
  return Datum(lhs*rhs.value(), lhs*rhs.error() );
}

Datum operator*(const double& lhs, const Datum& rhs){
  return Datum(lhs*rhs.value(), lhs*rhs.error() );
}

ostream& operator<<(ostream& os, const Datum& rhs){
  using namespace std;
  os << rhs.value() << " +/- " << rhs.error(); // NB: no endl!
  return os;
}
