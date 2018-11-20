
#include "Vector3D.h"
#include <iostream>
#include <iomanip>
#include "SimpleBody.h"
#include "CompositeSystem.h"

#include <cmath>

using std::cout;
using std::endl;

int main() {



  double theta0 = M_PI/10; // random position along the orbit
  double earthVel = 30.e3; // 30 km/s
  double astrUnit = 150.e9; // 150 x 10^6 km
  double earthMass = 6.e24; // kg
  SimpleBody earth("earth", earthMass, Vector3D(0,0,0) );
  earth.setVelocity( Vector3D(0, 0, 0) );

  double moonVel = 1.e3; // 1 km/s
  double moonDist = 384399.e3; // 384 399 km
  double moonMass = 7.e22; // kg
  SimpleBody moon("moon", moonMass, Vector3D(moonDist*cos(theta0),moonDist*sin(theta0),0) );
  moon.setVelocity( Vector3D(-moonVel*sin(theta0), moonVel*cos(theta0), 0) );

  CompositeSystem earthSystem("earth+moon", &earth);
  earthSystem.add(&moon);


  double sunMass = 2.e30; // kg
  SimpleBody sun("sun", sunMass, Vector3D(0,0,0) );


  CompositeSystem solarSystem("solarSystem", &sun);
  solarSystem.add( &earthSystem,
                   Vector3D(astrUnit*cos(theta0),astrUnit*sin(theta0),0),
                   Vector3D(-earthVel*sin(theta0), earthVel*cos(theta0), 0) );

  solarSystem.print();


  cout << std::setprecision(4) << std::setw(10);

  // estimate position every minute
  int days(600), hours(24), mins(60);
  for(int i=0; i<= days*hours*mins; ++i) {

    if( i%(hours*mins*10) == 0 ) {
      cout << " ---- Day " << i/(hours*mins) << " ----- " << endl;
      cout << "earth position: " << earth.position()
           << endl;
    }
    solarSystem.evolve(60);
  }
  solarSystem.print();

  return 0;

}
