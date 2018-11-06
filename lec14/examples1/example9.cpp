// example9.cpp
#include <string>
#include <iostream>
using namespace std;

#include "Person.h"
#include "Student.h"

int main() {

  Student* p1  = new Student("Susan", 123456);
  p1->addCourse(string("algebra"));
  p1->addCourse(string("physics"));
  p1->addCourse(string("Art"));
  p1->printCourses();

  Student* paolo   = new Student("Paolo", 9856);
  paolo->addCourse("Music");
  paolo->addCourse("Chemistry");
  Person* p2 = paolo;

  delete p1;
  delete p2;

  return 0;
}
