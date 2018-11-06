#include "GraduateStudent.h"
#include <iostream>
using namespace std;

GraduateStudent::GraduateStudent(const std::string& name, int id, const std::string& major) :
  Student(name,id) {
  major_ = major;
  cout << "GraduateStudent(" << name << ", " << id << "," << major << ") called" << endl;
}

GraduateStudent::~GraduateStudent() {
  cout << "~GraduateStudent() called for name:" << name()
       << " id: " << id()
       << " major: " << major_ << endl;
}

void GraduateStudent::print() const {
  cout << "I am GraduateStudent " << name() << " with id " << id()
       << " major in " << major_ << endl;
}
