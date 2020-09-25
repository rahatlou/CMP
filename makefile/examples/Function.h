#ifndef Function_h
#define Function_h

#include <string>

class Function {
  public:
    Function(const std::string& name);
    virtual double value(double x) const = 0;
    virtual void print() const;
    virtual std::string name() const { return name_; }

  private:
    std::string name_;
};
#endif
