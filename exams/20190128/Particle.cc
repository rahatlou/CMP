//Particle.cc

#include <string>
#include <iostream>
#include "Particle.h"

using std::cout;
using std::endl;
using std::string;
using std::ostream;


Particle::Particle(const string& name, const TLorentzVector& momentum){
  name_=name;
  mass_=sqrt(momentum.E()*momentum.E()-momentum.P()*momentum.P());
  momentum_=momentum;
}

Particle::Particle(const string& name, const double& mass, const double& px, const double& py, const double& pz){
  name_=name;
  mass_=mass;
  momentum_=TLorentzVector(px,py,pz,sqrt(mass*mass+px*px+py*py+pz*pz));
}
     

void Particle::setName(const string& name){
  name_=name;
}

void Particle::setMass(const double& mass){
  mass_=mass;
  momentum_=TLorentzVector(momentum_.Px(),momentum_.Py(),momentum_.Pz(),sqrt(mass*mass+momentum_.P()*momentum_.P()));
}

void Particle::set4Momentum(const TLorentzVector& momentum){
  momentum_=momentum;
 
}

void Particle::set3Momentum(const double& px, const double& py, const double& pz){
  momentum_=TLorentzVector(px,py,pz,sqrt(mass_*mass_+px*px+py*py+pz*pz));
}
		   


double Particle::energy() const{
  return momentum_.E();
}

double Particle::momentum() const{
  return momentum_.P();
}

ostream& operator<<(ostream& os, const Particle& p){
  
  os<<"Particle: "<<p.name()<<" with mass= "<<p.mass()<<" GeV,  momentum= "<<p.momentum()<<" GeV and energy:"<<p.energy()<<" GeV";
  return os;
}

void Particle::print() const{
  cout<<"Particle: "<<name_<<" with mass= "<<mass_<<" GeV and momentum= "<<momentum()<<" GeV"<<endl;
}


void Particle::boost(const double& bx,const double& by,const double& bz){
  momentum_.Boost(bx,by,bz);
}
