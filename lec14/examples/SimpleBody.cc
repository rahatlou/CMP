#include "SimpleBody.h"

#include<iostream>
#include<cmath>

SimpleBody::SimpleBody(const std::string& name, const double mass, const Vector3D& x0) : Body(name) {
    mass_ = mass;
    pos_ = x0;
}


void SimpleBody::move(const Vector3D& F, double dt) {
  pos_ += vel_ * dt;
  Vector3D acc = F/mass_;
  vel_ += acc * dt;

}

Vector3D SimpleBody::forceOn(const Body* obj) const {
  const  double Grav_Const = 6.673e-11; // Newton's constant
  Vector3D dr = position() - obj->position();
  Vector3D force =  Grav_Const * mass() * obj->mass() * dr / pow(dr.mod(),3);
  return force;
}

Vector3D SimpleBody::forceFrom(const Body* source) const {
  const  double Grav_Const = 6.673e-11; // Newton's constant
  Vector3D dr = source->position() - position();
  Vector3D force =  Grav_Const * source->mass() * mass() * dr / pow(dr.mod(),3);
  return force;
}



void SimpleBody::print() const {
    std::cout << "===== class: SimpleBody  name: " << name()
              << "\t mass: " << mass_ << " kg" << " ===== " << std::endl
              << "current position " << pos_ << "\t distance from origin: "
              << pos_.mod() << " m" << std::endl
              << "current velocity " << vel_ <<  "\t "
              << vel_.mod()
              <<  " m/s" << std::endl;

}
