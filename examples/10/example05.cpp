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

  int itype;
  do{
    cout << "Choose class to allocate a dynamic object. 1: Person 2: Student" << endl;
    cin >> itype;
  } while (itype != 1 && itype!=2);

  Person* p;


  if(itype==1) {
    p = new Person("john");
  } else {
    p = new Student("Susan", 123456);
  }

  // calling print()
  cout << "calling print() on a Person* pointer" << endl;
  p->print();

  cout << "delete the object" << endl;
  delete p;
  
  return 0;
}



