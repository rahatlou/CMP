#ifndef Person_h
#define Person_h

#include <string>

class Person {
  public:
    Person(const std::string& name);
    ~Person();
    std::string name() const { return name_; }
    virtual void print() const;

  private:
    std::string name_;
};
#endif
