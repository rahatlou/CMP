#ifndef Student_h
#define Student_h

#include "Person.h"
#include <string>

class Student : public Person {
  public:
    Student(const std::string& name, int id);
    ~Student();
    int id() const { return id_; }
    virtual void print() const;

  private:
    int id_;
};
#endif
