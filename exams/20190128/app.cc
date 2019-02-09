//app.cc
//to compile and link the executable do:
//  g++ -o app app.cc Particle.cc CompositeParticle.cc `root-config --libs --cflags` 



#include <iostream>
#include "Particle.h"
#include "CompositeParticle.h"

using std::cout;
using std::endl;

int main(){
  Particle pion("Pion",0.14,2,0,0);
  Particle kaon("Kaon",0.50,-1,0,0);
  
  CompositeParticle d0=pion+kaon;
  d0.setName("D0");

  cout<<"Particles colliding:"<<endl;
  cout<<d0<<endl;

  
  pion.set3Momentum(0.,0.,0.);
  kaon.set3Momentum(0.,0.,0.);
  cout<<"Particles at rest:"<<endl;
  d0=pion+kaon;
  cout<<d0<<endl;

  
}
