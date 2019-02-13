#ifndef RESISTOR_H
#define RESISTOR_H
#include<iostream>
#include<string>

class Resistor{
public:
  Resistor(const std::string& name="", double val=0){ _name = name; _R = val;}
  virtual double value() const { return _R; }
  virtual std::string name() const { return _name; }
  void setName(const std::string& name)  {  _name = name; }

  Resistor operator||(const Resistor& rhs) const {
    double R = 1/ (1./_R + 1./rhs.value());
    return Resistor("("+_name+"||"+rhs._name+")", R);
  }

  Resistor operator+(const Resistor& rhs) const {
    return Resistor("("+_name+"+"+rhs._name+")", _R+rhs.value());
  }

  friend  std::ostream& operator<<(std::ostream& os, const Resistor& rhs) {
    os << rhs.name() + ": " << rhs.value() << " ohm ";
    return os;
  }

  virtual void print(const std::string& offset="") const {
    std::cout << offset << name() + ": " << value() << " ohm " << std::endl;
  }

private:
  double _R;
  std::string _name;
};
#endif
