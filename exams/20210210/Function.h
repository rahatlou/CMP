#ifndef Function_h
#define Function_h

#include <string>
#include <iostream>
class CustomIntegrator;

class Function {
  public:
    Function(const std::string& name) { name_ = name; }
    virtual double value(double x) const = 0;
    virtual void print() const { std::cout << "Function with name " << name_ << std::endl;}
    virtual std::string name() const { return name_; }
    virtual double integrate(double,double) const = 0;
    virtual void setIntegrator(CustomIntegrator* in) {
     engine_ = in;
    }

  private:
    std::string name_;

  protected:
    CustomIntegrator*   engine_;
};
#endif
