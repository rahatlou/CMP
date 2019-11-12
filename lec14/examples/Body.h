#ifndef Body_h
#define Body_h

#include <string>
#include <iostream>
#include "Vector3D.h"

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
#endif
