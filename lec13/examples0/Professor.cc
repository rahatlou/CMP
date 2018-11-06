#include "Professor.h"
#include <iostream>
using namespace std;

Professor::Professor(const std::string& name, const std::string& department) :
  Person(name) {
  department_ = department;
  cout << "Professor(" << name << ", " << department << ") called" << endl;
}

Professor::~Professor() {
  cout << "~Professor() called for name:" << name() << " and department: " << department_ << endl;
}
