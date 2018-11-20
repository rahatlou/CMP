#include<iostream>
#include "Picture.h"
#include "Shape.h"

class Rectangle : public Shape {
public:
  Rectangle(const std::string& name) : Shape(name) {}
  virtual void draw() const {
      std::cout << "calling Rectangle::draw() for " << name() << std::endl;
  }
};

class Circle : public Shape {
public:
  Circle(const std::string& name) : Shape(name) {}
  virtual void draw() const {
      std::cout << "calling Circle::draw() for " << name() << std::endl;
  }
};

class Line : public Shape {
public:
  Line(const std::string& name) : Shape(name) {}
  virtual void draw() const {
      std::cout << "calling Line::draw() for " << name() << std::endl;
  }
};



int main() {

  Rectangle rect1("r1");
  Circle cir1("cir1");

  Rectangle rect2("r2");
  Circle cir2("cir2");
  Line l2("l2");

  Picture pic1("pic1");
  pic1.add( &rect2);
  pic1.add( &cir2);
  pic1.add( &l2);

  rect1.draw();
  cir1.draw();

  pic1.draw();

    return 0;

}
