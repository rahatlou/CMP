#ifndef PARALLEL_H
#define PARALLEL_H
#include "Resistor.h"
#include<iostream>
#include<list>

class Parallel : public Resistor {
public:
  Parallel(const std::string name="") : Resistor(name) {};

  void add(Resistor* a) {
    if(_elements.size()==0) setName( a->name());
    else setName( name()+"||"+a->name());
    _elements.push_back(a);
  }

  virtual double value() const {
    double R = 0;
    for(std::list<Resistor*>::const_iterator it = _elements.begin(); it != _elements.end(); ++it ) {
        R += 1./(*it)->value();
    }
    return 1/R;
  }

  friend std::ostream& operator<<(std::ostream& os, const Parallel& rhs) {
    os << rhs.name() + ": " << rhs.value() << " ohm" << std::endl;
    for(std::list<Resistor*>::const_iterator it = rhs._elements.begin(); it != rhs._elements.end(); ++it ) {
        os << "\t" << **it << std::endl;
    }
    return os;
  }

  virtual void print(const std::string& offset="") const {
    std::cout << offset << name() + ": " << value() << " ohm" << std::endl;
    for(std::list<Resistor*>::const_iterator it = _elements.begin(); it != _elements.end(); ++it ) {
        (*it)->print(offset+"  ");
    }
  }


private:
  std::list<Resistor*> _elements;

};
#endif
