#ifndef Professor_h
#define Professor_h

#include "Person.h"
#include <string>

class Professor : public Person {
  public:
    Professor(const std::string& name, const std::string& department);
    ~Professor();
    std::string department() const { return department_; }
    //virtual void print() const;  // will use Person::Print()

  private:
    std::string department_;
};
#endif
