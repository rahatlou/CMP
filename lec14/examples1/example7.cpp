// example7.cpp
#include <string>
#include <iostream>
using namespace std;

#include "Person.h"
#include "Student.h"
#include "GraduateStudent.h"

int main() {

  Person* p1  = new Student("Susan", 123456);
  Person* p2   = new GraduateStudent("Paolo", 9856, "Physics");

  delete p1;
  delete p2;

  return 0;
}
