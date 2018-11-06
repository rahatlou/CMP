// example2.cpp
#include <string>
#include <iostream>
using namespace std;


class Person {
  public:
    Person(const string& name, int age) {
      name_ = name;
      age_ = age;
      cout << "Person(" << name << ", "
           << age << ") called" << endl;
    }

    ~Person() {
      cout << "~Person() called for " << name_ << endl;
     }

    string name() const { return name_; }
    int age() const { return age_; }
    void print() {
      cout << "I am a Person. name: " << name_
           << " age: " << age_ << endl;
    }

  private:
    string name_;

  protected:
    int age_;

};


class Student : public Person {
  public:
    Student(const string& name, int age, int id) :
      Person(name,age) {
      id_ = id;
      cout << "Student(" << name << ", " << age 
           << ", " << id << ") called" << endl;
    }

    ~Student() {
      cout << "~Student() called for name:" << name()
           << " age: " << age_ << " and id: " << id_ << endl;
    }

    int id() const { return id_; }

  private:
    int id_;
};


int main() {

  Person* john = new Person("John",23);
  john->print();

  Student* susan = new Student("Susan", 21, 123456);
  susan->print();

  delete john;
  delete susan;

  return 0;
}



