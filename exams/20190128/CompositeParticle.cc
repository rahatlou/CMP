//CompositeParticle.cc


#include "CompositeParticle.h"
#include <iostream>
#include <string>    
#include <list>

using std::cout;
using std::endl;
using std::list;
using std::string;    
using std::ostream;


CompositeParticle::CompositeParticle(const string& name):Particle(name,0.){}

void CompositeParticle::add(Particle* part){
  particles_.push_back(part);
  TLorentzVector vec=fourMomentum();
  setMass(mass()+part->mass());
  set4Momentum(vec+part->fourMomentum());
  
}

void CompositeParticle::remove(Particle* part){
  particles_.remove(part);
  TLorentzVector vec=fourMomentum();
  setMass(mass()-part->mass());
  set4Momentum(vec-part->fourMomentum());
}

ostream& operator<<(ostream& os, const CompositeParticle& p){
  os<<"CompositeParticle: "<<p.name()<<", #particles "<<p.particles_.size()<<"\n Total mass: "<<p.mass()<<" GeV, momentum of the cm: "<<p.momentum()<<" GeV and energy in the cm: "<<p.energy()<<" GeV";
  
  return os;
}
  
double CompositeParticle::energy() const{
  //energy in the center of mass (invariant mass)
  return sqrt(fourMomentum().E()*fourMomentum().E()-fourMomentum().P()*fourMomentum().P());
}

double CompositeParticle::momentum() const{
  //modulus of the total 3momentum of the center of mass 
  return fourMomentum().P();
}

void CompositeParticle::print() const{
  cout<<"CompositeParticle "<<name()<<" made by:"<<endl;
  for(list<Particle*>::const_iterator i = particles_.begin(); i != particles_.end(); ++i) {
    (*i)->print();
  }
  
}

CompositeParticle CompositeParticle::operator+(  Particle& rhs ) const{
  CompositeParticle sum("sum");
  for(list<Particle*>::const_iterator i = particles_.begin(); i != particles_.end(); ++i) {
    sum.add(*i);
  }
  sum.add(&rhs);
  return sum;
}
  
CompositeParticle CompositeParticle::operator+(  CompositeParticle& rhs ) const{
  CompositeParticle sum("sum");
  for(list<Particle*>::const_iterator i = particles_.begin(); i != particles_.end(); ++i) {
    sum.add(*i);
  }
  for(list<Particle*>::const_iterator i = rhs.particles_.begin(); i != rhs.particles_.end(); ++i) {
    sum.add(*i);
  }
  return sum;
}

CompositeParticle operator+(Particle& lhs, CompositeParticle& rhs){
  CompositeParticle sum("sum");
  sum.add(&lhs);
  for(list<Particle*>::const_iterator i = rhs.particles_.begin(); i != rhs.particles_.end(); ++i) {
    sum.add(*i);
  }
  
  return sum;
}

CompositeParticle operator+(Particle& lhs,Particle& rhs){
  CompositeParticle sum("sum");
  sum.add(&rhs);
  sum.add(&lhs);
  return sum;
}


void CompositeParticle::boost(const double& bx,const double& by,const double& bz){
  TLorentzVector vec=fourMomentum();
  vec.Boost(bx,by,bz);
  set4Momentum(vec);
  for(list<Particle*>::const_iterator i = particles_.begin(); i != particles_.end(); ++i) {
    (*i)->boost(bx,by,bz);
  }
}
