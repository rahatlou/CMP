
#include "Vector3D.h"
#include <iostream>
#include <iomanip>
#include "SimpleBody.h"
#include <cmath>

using std::cout;
using std::endl;

int main() {


  double sunMass = 2.e30; // kg
  SimpleBody sun("sun", sunMass, Vector3D(0,0,0) );

  double theta0 = M_PI/10; // random position along the orbit
  double orbitalVel = 30.e3; // 30 km/s
  double astrUnit = 150.e9; // 150 x 10^6 km
  double earthMass = 6.e24; // kg
  SimpleBody earth("earth", earthMass, Vector3D(astrUnit*cos(theta0),astrUnit*sin(theta0),0) );
  earth.setVelocity( Vector3D(-orbitalVel*sin(theta0), orbitalVel*cos(theta0), 0) );

  std::cout << "===== beginning of simulation " << std::endl;
  sun.print();
  earth.print();

  const double G = 6.673e-11; // Newton's constant

  cout << std::setprecision(4) << std::setw(10);

  // estimate position every minute
  int days(380), hours(24), mins(60);
  for(int i=0; i<= days*hours*mins; ++i) {
    // compute force
    Vector3D dr = sun.position() - earth.position();
    Vector3D force =  G * sun.mass() * earth.mass() * dr / pow(dr.mod(),3);
    //force = force/(pow(dr.mod(),3));

    if( i%(hours*mins) == 0 ) {
      cout << " ---- Day " << i/(hours*mins) << " ----- " << endl;
      cout << "earth position: " << earth.position()
           //<< "\t velocity: " << earth.velocity()
           //<< "\t force: " << force << " N"
           << endl;

      //cout << "earth radius: " << earth.position().mod()
        //   << "\t velocity: " <<  earth.velocity().mod()
          // << "\t force: " << force.mod() << endl;
    }
    earth.move(force, 1);
  }
  std::cout << "===== End of simulation " << std::endl;

  earth.print();
  return 0;

}
