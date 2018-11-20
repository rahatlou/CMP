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
Note that in this example we only use a base class for simple shapes and a composite class. So our `Leaf` and `Component` classes are the same.


## Exercise
  1. implement proper constructors to take as argument the information needed to create each type of objects
  2. implement the `move()` method


# Simulation of solar system with composite  pattern
This example is inspired by work described by [Giovanni Organtini](http://www.roma1.infn.it/people/organtini/) in the [freely available appendix](http://www.roma1.infn.it/people/organtini/publications/scientificProgramming++.pdf) to the book [Programmazione Scientifica](www.programmazionescientifica.org/) (by Barone, Marinari,  Organtini, Ricci-Tersenghi). This book is the reference book for the course **Laboratorio di Calcolo** and **Laboratorio di Fisica Comutazionale** in the Laurea Triennale in Fisica in Rome.

The idea is to simulate the motion of the earth around the sun with a simple class representing a generic celestial body subject to the gravitation force. The Euler method is used to integrate the equation of motion. You can use the [Strategy pattern](../lec15/lec15.md) to implement a diffrent integration scheme, eg. with the Runge-Kutta method.

The composite pattern is used to extend the model to simulate the motion of the moon around the Earth. The same model can then be used to add all planets of the solar system and their satellites.

Note that with the addition of many bodies, the simple Euler method wiull become insufficient and better and more precise computation is needed.

However, all classes continue to work and you only need to update or improve the `move()` method or even better use the [Strategy pattern](../lec15/lec15.md).

## generic celestial body
The base class [Body.h](examples/Body.h) is abstract and mainly meant to define the interface for all celestial bodies.

All methods should be usable by both simple and composite objects.

```c++
class Body {
  public:
    Body(const std::string& name) { name_ = name; }
    virtual void move(const Vector3D& Force, double dt) = 0;
    virtual double mass() const = 0;
    virtual Vector3D position() const = 0;
    virtual Vector3D velocity() const = 0;
    virtual void setPosition(const Vector3D& p) = 0;
    virtual void setVelocity(const Vector3D& v) = 0;
    virtual void translate(const Vector3D& dr) = 0;
    virtual void addVelocity(const Vector3D& dv) = 0;

    virtual Vector3D forceOn(const Body* obj) const = 0;
    virtual Vector3D forceFrom(const Body* source) const = 0;

    virtual std::string name() const {
        return name_;
    }

    virtual void print() const {
        std::cout << "class Body with name_: " << name_ << std::endl;
    }

  private:
    std::string name_;
};
```
### Simple body
First we implement the [SimpleBody.h](examples/SimpleBody.h) class to simulate the motion of a body, both planets or satellites.
```c++
class SimpleBody : public Body {
  public:
    SimpleBody(const std::string& name, const double mass, const Vector3D& x0=0);
    virtual void move(const Vector3D& F, double dt);
    virtual double mass() const { return mass_;}
    virtual Vector3D position() const { return pos_; }
    Vector3D velocity() const { return vel_; }
    virtual void setVelocity(const Vector3D& v) { vel_ = v; };
    virtual void setPosition(const Vector3D& pos) {pos_ = pos; };
    virtual void translate(const Vector3D& dr) { pos_ += dr; }
    virtual void addVelocity(const Vector3D& dv) { vel_ += dv; }
    virtual Vector3D forceOn(const Body* obj) const;
    virtual Vector3D forceFrom(const Body* source) const;
    virtual void print() const;

  private:
    Vector3D pos_;
    Vector3D vel_;
    double mass_;
};
```
Note how all methods from `Body` are now implemented. There are no additional methods, but the class is defined by its new data members: the mass, the position, and the velocity.

We are using the [Vector3D](examples/Vector3D.h) class to do vector calculations for position and velocity.
```c++
class Vector3D {
  public:
    Vector3D(const double& x=0, const double& y=0, const double& z=0) ;


    const Vector3D& operator=(const Vector3D& rhs);
    const Vector3D& operator+=(const Vector3D& rhs);

    const Vector3D operator+(const Vector3D& rhs) const;
    const Vector3D operator-(const Vector3D& rhs) const;

    const Vector3D& operator=(const double& a); // set all components  = a

    const Vector3D operator/(const double a) const ; // vector / scalar

    const Vector3D operator*(const double a) const; // scalar x double

    friend const Vector3D operator*(const double a, const Vector3D& rhs); // scalar x vector

    friend  std::ostream& operator<<(std::ostream& os, const Vector3D& rhs);

    double mod() const;
    double distance(const Vector3D& r0) const;

  private:
    double x_[3];

};
```
**NB:** the implementation (.cc file) of `Vector3D` is not provided here. You should by now have already this class implemented. If not, take the header file and implement all the functions as an exercise.

# Composite pattern in High Energy Physics
