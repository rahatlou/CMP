#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(const std::string& name, int id) :
  Person(name) {
  id_ = id;
  courses_ = new std::vector<std::string>();
  cout << "Student(" << name << ", " << id << ") called" << endl;
}

Student::~Student() {
  delete courses_;
  courses_ = 0;
  cout << "~Student() called for name:" << name() << " and id: " << id_ << endl;
}

void Student::print() const {
  cout << "I am Student " << name() << " with id " << id_ << endl;
  cout << "I am now enrolled in " << courses_->size() << " courses." << endl;
}

void Student::addCourse(const std::string& course) {
  courses_->push_back( course );
}

void
Student::printCourses() const {
  cout << "student " << name()
       << " currently enrolled in following courses:"
       << endl;

  for(int i=0; i<courses_->size(); ++i) {
    cout << (*courses_)[i] << endl;
  }
}

const std::vector<std::string>*
Student::getCourses() const {
  return courses_;
}
