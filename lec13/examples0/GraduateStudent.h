#ifndef GraduateStudent_h
#define GraduateStudent_h

#include "Student.h"
#include <string>

class GraduateStudent : public Student {
  public:
    GraduateStudent(const std::string& name, int id, const std::string& major);
    ~GraduateStudent();
    std::string getMajor() const { return major_; }
    virtual void print() const;

  private:
    std::string major_;
};
#endif
