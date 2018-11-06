// example4.cpp
#include <string>
#include <iostream>
using namespace std;

#include "Person.h"
#include "Student.h"
#include "GraduateStudent.h"

int main() {

  Person* john = new Person("John");
  Person* susan = new Student("Susan", 123456);
  Person* paolo = new GraduateStudent("Paolo", 9856, "Physics");

  (*john).print();
  (*susan).print();
  (*paolo).print();

  john->print();
  susan->print();
  paolo->print();

  delete john;
  delete susan;
  delete paolo;

  return 0;
}
