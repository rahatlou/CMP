#include "Gauss.h"
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;
#include "CustomIntegrator.h"

Gauss::Gauss(const std::string& name, double mean, double width) :
  Function(name) {
  mean_ = mean;
  width_ = width;
}

double Gauss::value(double x) const {
  double pull = (x-mean_)/width_;
  double y = (1/sqrt(2.*M_PI*width_)) * exp(-pull*pull/2.);
  return y;
}

void
Gauss::print() const {
  cout << "Gaussian with name: " << name()
       << " mean: " << mean_
       << " width: " << width_
       << endl;
}

double Gauss::integrate(double a,double b) const {
  return engine_->integrate(a,b,this);
}
