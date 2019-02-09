//CompositeParticle.h

#ifndef CompositeParticle_h
#define CompositeParticle_h


#include "Particle.h"
#include "TLorentzVector.h"
#include <list>
#include <string>
#include <iostream>

using std::string;
using std::list;
using std::ostream;

class CompositeParticle : public Particle{
 public:
  CompositeParticle(const string& name);
  virtual void print() const;

  void add(Particle* part);
  void remove(Particle* part);
  
  virtual double energy() const;
  virtual double momentum() const;
  
  friend ostream& operator<<(ostream& os, const CompositeParticle& p);
  CompositeParticle operator+(Particle& rhs) const;
  CompositeParticle operator+(CompositeParticle& rhs) const;
  friend CompositeParticle operator+(Particle& lhs, CompositeParticle& rhs);
  
  virtual void boost(const double& bx,const double& by,const double& bz);

  
  
 private:
  list<Particle*> particles_;

};


CompositeParticle operator+(Particle& lhs,Particle& rhs);



#endif
