//Particle.h

#ifndef Particle_h
#define Particle_h

#include <string>
#include <iostream>
#include"TLorentzVector.h"


using std::string;
using std::ostream;


class Particle{
 public:
  Particle(const string& name, const TLorentzVector& momentum);
  Particle(const string& name, const double& mass, const double& px=0., const double& py=0., const double& pz=0.);
  virtual void print() const;

  void setName(const string& name);
  void setMass(const double& mass);
  void set4Momentum(const TLorentzVector& momentum);
  void set3Momentum(const double& px, const double& py, const double& pz);
  string name() const{ return name_;}
  double mass() const{ return mass_;}
  virtual TLorentzVector fourMomentum() const{ return momentum_;}
  virtual double energy() const;
  virtual double momentum() const;

  friend ostream& operator<<(ostream& os, const Particle& p);
  virtual void boost(const double& bx,const double& by,const double& bz);
  


 private:
  string name_;
  double mass_;
  TLorentzVector momentum_;

};










#endif
