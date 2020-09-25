#include "CompositeSystem.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::list;

CompositeSystem::CompositeSystem(const std::string& name, Body* center) : Body(name){
  bodies_.push_back(center);
  center_ = center;
}

double CompositeSystem::mass() const {
    double m = 0;
    for(list<Body*>::const_iterator i = bodies_.begin(); i != bodies_.end(); ++i) {
      m += (*i)->mass();
    }
    return m;
}

Vector3D CompositeSystem::position() const {
    Vector3D p(0,0,0);
    for(list<Body*>::const_iterator i = bodies_.begin(); i != bodies_.end(); ++i) {
      p += (*i)->mass() * (*i)->position();
    }
    return p/mass();
}

Vector3D CompositeSystem::velocity() const {
    return center_->velocity();
}


void CompositeSystem::move(const Vector3D& F, double dt) {
  for(list<Body*>::iterator i = bodies_.begin(); i != bodies_.end(); ++i) {
    (*i)->move(F, dt);
  }

}

void CompositeSystem::print() const {
  std::cout << "===== class: CompositeSystem  name: " << name()
            << "# bodies: " << bodies_.size() << " ======= "
            << std::endl;
  for(list<Body*>::const_iterator i = bodies_.begin(); i != bodies_.end(); ++i) {
    (*i)->print();
  }
  std::cout << "==============================================" << std::endl;
}

void CompositeSystem::setPosition(const Vector3D& pos) {
  Vector3D dr = pos - center_->position();
  translate( dr );
} // FIXME: change position of center and then find translate to apply

void CompositeSystem::translate(const Vector3D& dr) {
  for(list<Body*>::iterator i = bodies_.begin(); i != bodies_.end(); ++i) {
    (*i)->setPosition( (*i)->position() + dr  );
  }
}

void CompositeSystem::setVelocity(const Vector3D& v) {
  Vector3D dv = v - center_->velocity();
  addVelocity( dv );
}

void CompositeSystem::addVelocity(const Vector3D& dv) {
  for(list<Body*>::iterator i = bodies_.begin(); i != bodies_.end(); ++i) {
    (*i)->setVelocity( (*i)->velocity() + dv  );
  }
}


void CompositeSystem::add(Body* b, const Vector3D& dr, const Vector3D& dv) {
  b->translate(dr);
  b->addVelocity( velocity() + dv );
  bodies_.push_back(b);
}

Vector3D CompositeSystem::forceOn(const Body* obj) const {
  const  double Grav_Const = 6.673e-11; // Newton's constant
  Vector3D force(0,0,0);
  for(list<Body*>::const_iterator i = bodies_.begin(); i != bodies_.end(); ++i) {
    Vector3D dr = (*i)->position() - obj->position();
    force +=  Grav_Const * (*i)->mass() * obj->mass() * dr / pow(dr.mod(),3);
  }
  return force;
}

Vector3D CompositeSystem::forceFrom(const Body* source) const {
  const  double Grav_Const = 6.673e-11; // Newton's constant
  Vector3D force(0,0,0);
  for(list<Body*>::const_iterator i = bodies_.begin(); i != bodies_.end(); ++i) {
    Vector3D dr = source->position() - (*i)->position();
    force +=  Grav_Const * source->mass() * (*i)->mass() * dr / pow(dr.mod(),3);
  }
  return force;
}




void CompositeSystem::evolve(const double& dt) {

  // loop over bodies
  for(list<Body*>::iterator i = bodies_.begin(); i != bodies_.end(); ++i) {

    //compute total force on i from all other bodies
    Vector3D force(0,0,0);
    for(list<Body*>::iterator j = bodies_.begin(); j != bodies_.end() ; ++j) {
      if( j==i ) continue; // no self interaction
      force += (*i)->forceFrom( *j ); // compute force exercised by j on i
    } // 2nd iterator

    // now move i
    (*i)->move(force, dt);
  } // 1st iterator



}
