// example6.cpp
#include <string>
#include <iostream>
using namespace std;

#include "Person.h"
#include "Student.h"
#include "GraduateStudent.h"
#include "Professor.h"

int main() {

  Person* p = 0;
  
  int value = 0;
  while(value<1 || value>10) {
    cout << "Give me a number [1,10]: ";
    cin >> value;
  }
  cout << flush;

  cout << "make a new derived object..." << endl;

  if(value>5) p = new Student("Susan", 123456);
  else        p = new GraduateStudent("Paolo", 9856, "Physics");


  cout << "call print() method ..." << endl;

  p->print();

  delete p;

  return 0;
}



