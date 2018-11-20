#ifndef Shape_h
#define Shape_h

#include <iostream>
#include <string>

class Shape {
public:
  Shape(const std::string& name) { name_ = name; }
  virtual void draw() const = 0;
  //virtual void move() = 0; // add also move() function
  virtual std::string name() const { return name_; }
  virtual void print() const {
      std::cout << "Shape with name " << name_ << std::endl;
  }
  virtual ~Shape() {}
private:
  std::string name_;
};

#endif
