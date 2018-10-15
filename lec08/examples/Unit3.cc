#include "Unit3.h"
using namespace std;

// init. static data member
int Unit::counter_ = 0;

Unit::Unit(const std::string& name) {
  name_ = name;
  counter_++;
  cout << "Unit(" << name
       <<") called. Total Units: "
       << counter_ << endl;
}

Unit::~Unit() {
  counter_--;
  cout << "~Unit() called for "
       <<  name_ << ". Total Units: "
       << counter_ << endl;
}

ostream&
operator<<(ostream& os, const Unit& unit) {
  os << "My name is " << unit.name_
     << "! Total Units: " << unit.counter_;
  return os;
}



