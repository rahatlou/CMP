// bad2.cpp
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
    Student(const string& name, int id) {
      // we forgot to initialize the Person::name_
      // by calling Person(name)
      // so the compiler will give you errors
      id_ = id;
      cout << "Student(" << name << ", " << id << ") called" << endl;
    }

    ~Student() {
      cout << "~Student() called for name:" << name() << " and id: " << id_ << endl;
     }

     int id() const { return id_; }

  private:
    int id_;
};


int main() {

  Person anna("Anna");

  Student* susan = new Student("Susan", 123456);
  susan->print();
  delete susan;

  return 0;
}



