#include "Unit.h"
using namespace std;

// init. static data member. NB: No static keyword necessary. Otherwise... compilation error!
int Unit::counter_ = 0;

Unit::Unit(const std::string& name) {
  name_ = name;
  counter_++;
}

Unit::~Unit() {
  counter_--;
}

ostream&
operator<<(ostream& os, const Unit& unit) {
  os << unit.name_ << " Total Units: " << unit.counter_;
  return os;
}



