#ifndef Picture_h
#define Picture_h

#include "Shape.h"
#include <list>
#include <iostream>

class Picture : public Shape {
public:
  Picture(const std::string& name) : Shape(name) {}
  void draw() const {
    // call  draw() for each shape in the list
    std::cout << "drawing picture " << name() << std::endl;
    for( std::list<Shape*>::const_iterator it = shapes_.begin();
      it != shapes_.end(); it++ )  {
          (*it)->draw();
    }
  }

  void add(Shape *s) {
    shapes_.push_back(s);
  }

  virtual void print() const {
    std::cout << "Composite object of type Picture and name "
        << name() << " with " << shapes_.size() << "shapes: " << std::endl;
        for( std::list<Shape*>::const_iterator it = shapes_.begin();
          it != shapes_.end(); it++ )  {
              (*it)->print();
        }



  }

private:
  std::list<Shape*> shapes_;
};

#endif
