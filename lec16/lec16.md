# Composite Pattern (Composition)

[Composition](https://en.wikipedia.org/wiki/Composite_pattern) is a design
patten to treat a group of objects the same way as a
single object. It is an example of a part-whole hierarchy where simple objects
 are composed into a composite object. Clients treat simple and composite objects share
 the same interface.

The UML diagram for the composite pattern is
![Composite Pattern](Composite_UML_class_diagram.png "Composite Pattern")

A [simple example of composition](https://www.bogotobogo.com/DesignPatterns/composite.php) is with graphical objects, e.g. square, circle, rectangle, as basic objects and a picture as a composed object containing a list of simple of objects.

Simple objects inherit from (examples/Shape.h)
```c++
class Shape {
public:
  virtual void draw() const = 0;
  virtual void move() = 0;
  virtual ~Shape() {}
};
```

The composite objects such as [Picture](examples/Picture.h) contain a list of pointers (not  copies) of simple objects in order to allow us to take advantage of polymorphic behavior of different objects.
```c++
class Picture : public Shape {
public:
  void draw() const {
    // call  draw() for each shape in the list
    for( std::list<Shape*>::const_iterator it = shapes_.begin();
      it != shapes_.end(); it++ )  {
          it->Draw();
    }
  }

  void add(Shape *s) {
    shapes_.push_back(s);
  }

private:
  std::list<Shape*> shapes_;
};
```

Now we can define a bunch of specific shapes
```c++
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
```
and now we can test the application [appShapes.cc](examples/appShapes.cc)
```c++
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
```
we can now link and run the example
```
$ g++ -o /tmp/appShapes appShapes.cc
$ /tmp/appShapes
calling Rectangle::draw() for r1
calling Circle::draw() for cir1
drawing picture pic1
calling Rectangle::draw() for r2
calling Circle::draw() for cir2
calling Line::draw() for l2
```
## Exercise
  1. implement proper constructors to take as argument the information needed to create each type of objects
  2. implement the `move()` method
