#ifndef Function_h
#define Function_h

#include <string>

class Function {
  public:
    Function(const std::string& name);
    virtual double value(double x) const;
    virtual double derivative(double x) const;
    virtual double integrate(double x1, double x2) const;

    virtual std::string name() const { return name_; }

  private:
    std::string name_;
};
#endif
