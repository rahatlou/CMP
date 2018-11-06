#include "ConstantFunction.h"

ConstantFunction::ConstantFunction(const std::string& name, double value) :
  Function(name) {
  value_ = value;
}

double ConstantFunction::value(double x) const {
  return value_;
}

double ConstantFunction::integrate(double x1, double x2) const {
  return (x2-x1)*value_;
}
