#include "FooDatum.h"

FooDatum::FooDatum() { }

FooDatum::FooDatum(double x, double y) {
  value_ = x;
  error_ = y;
}

FooDatum::FooDatum(const FooDatum& datum) {
  value_ = datum.value_;
  error_ = datum.error_;
}

double
significance() {
  return value_/error_;
}
