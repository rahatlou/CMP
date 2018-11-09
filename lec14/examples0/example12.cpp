// example12.cpp
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "Person.h"
#include "Student.h"
#include "GraduateStudent.h"

int main() {

 vector<Person*> people;

  Person* john = new Person("John");
  people.push_back(john);

  Student* susan = new Student("Susan", 123456);
  people.push_back(susan);

  GraduateStudent* paolo = new GraduateStudent("Paolo", 9856, "Physics");
  people.push_back(paolo);

  for(int i=0; i< people.size(); ++i) {
    people[i]->print();
  }

  delete john;
  delete susan;
  delete paolo;

  return 0;
}
