#ifndef Gauss_h
#define Gauss_h

#include <string>
#include "Function.h"

class Gauss : public Function {
  public:
    Gauss(const std::string& name, double mean, double width);

    virtual double value(double x) const;
    virtual void print() const;

  private:
    double mean_;
    double width_;
};
#endif
