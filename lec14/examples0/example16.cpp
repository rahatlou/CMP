// example5.cpp
#include <string>
#include <iostream>
using namespace std;

#include "Person.h"
#include "Student.h"
#include "GraduateStudent.h"
#include "Professor.h"

int main() {

  Person john("John");
  Student susan("Susan", 123456);
  GraduateStudent paolo("Paolo", 9856, "Physics");
  Professor bob("Robert", "Biology");

  john.print();
  susan.print();
  paolo.print();
  bob.print();

  return 0;
}



