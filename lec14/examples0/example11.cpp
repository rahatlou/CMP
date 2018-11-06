// example11.cpp
#include <string>
#include <iostream>
using namespace std;

#include "Person.h"
#include "Student.h"
#include "GraduateStudent.h"

int main() {

  Person* john = new Person("John");
  john->print();  // Person::print()

  Student* susan = new Student("Susan", 123456);
  susan->print(); // Student::print()
  susan->Person::print(); // Person::print()

  Person* p2 = susan;
  p2->print(); // Person::print()

  GraduateStudent* paolo = new GraduateStudent("Paolo", 9856, "Physics");
  paolo->print();

  Person* p3 = paolo;
  p3->print();


  delete john;
  delete susan;

  return 0;
}



