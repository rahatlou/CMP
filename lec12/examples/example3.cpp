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

  // method in the base classe
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

  // same method (with same arguments) in the derived class for Student objects
    void print() {
      cout << "I am Student " << name() << " with id " << id_ << endl;
    }

  private:
    int id_;
};


int main() {

  Person* john = new Person("John");
  john->print();  // Person::print()

  Student* susan = new Student("Susan", 123456);
  susan->print(); // Student::print()
  susan->Person::print(); // Person::print()

  Person* p2 = susan;
  p2->print(); // Person::print()

  delete john;
  delete susan;

  return 0;
}



