#ifndef BadFunction_h
#define BadFunction_h

#include <string>

class BadFunction {
  public:
    BadFunction(const std::string& name);
    virtual double value(double x) const { return 0; }
    virtual double integrate(double x1, double x2) const { return 0; }

  private:
    std::string name_;
};
#endif
