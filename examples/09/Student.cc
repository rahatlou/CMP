#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(const std::string& name, int id) :
  Person(name) {
  id_ = id;
  cout << "Student(" << name << ", " << id << ") called" << endl;
}

Student::~Student() {
  cout << "~Student() called for name:" << name() << " and id: " << id_ << endl;
}

void Student::print() const {
  cout << "I am Student " << name() << " with id " << id_ << endl;
}
