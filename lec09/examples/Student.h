#ifndef Student_h
#define Student_h

#include<string>

class Student {
public:
  Student(const std::string& name, int id) {
    name_ = name;
    id_ = id;
  }

  bool operator<(const Student& rhs) const {
    return id_ < rhs.id_;
  }

  std::string name() const {
    return name_;
  }

  int id() const {
    return id_;
  }

private:
  std::string name_;
  int id_;
};
#endif
