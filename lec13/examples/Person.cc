#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(const std::string& name) {
  name_ = name;
  cout << "Person(" << name << ") called" << endl;
}

Person::~Person() {
  cout << "~Person() called for " << name_ << endl;
}

void Person::print() const {
  cout << "I am a Person. My name is " << name_ << endl;
}


