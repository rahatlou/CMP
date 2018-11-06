// example3.cpp
#include <string>
#include <iostream>
using namespace std;


class Person {
  public:
    Person(const string& name) {
      name_ = name;
      cout << "Person(" << name << ") called" << endl;
    }

    ~Person() {
      cout << "~Person() called for " << name_ << endl;
     }

    string name() const { return name_; }

    void print() {
      cout << "I am a Person. My name is " << name_ << endl;
    }

  private:
    string name_;
};


class Student : public Person {
  public:
    Student(const string& name, int id) :
      Person(name) {
      id_ = id;
      cout << "Student(" << name << ", " << id << ") called" << endl;
    }

    ~Student() {
      cout << "~Student() called for name:" << name() << " and id: " << id_ << endl;
    }

    int id() const { return id_; }

    void print() {
      cout << "I am Student " << name() << " with id " << id_ << endl;
    }

  private:
    int id_;
};


int main() {

  Person john("John");
  john.print();  // Person::print()

  Student susan("Susan", 123456);
  susan.print(); // calls Student::print()
  susan.Person::print(); // explicitly call Person::print()

  // using base class pointer
  cout << "-- using base class pointer" << endl;
  Person* p2 = &susan;
  p2->print(); // calls Person::print()

  //using derived class pointer
  cout << "-- using derived class pointer" << endl;
  Student* sp = &susan;
  sp->print(); // calls Student::print()

  // using base class reference
  cout << "-- base class reference" << endl;
  Person& p3 = susan; 
  p3.print(); // calls Person::print()

  // behavior of print() depends on the type of pointer determined at compilation time
  
  return 0;
}



