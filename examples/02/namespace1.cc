// namespace1.cc
#include <iostream>

namespace physics {
  double mean(const double& a, const double& b) {
    return (a+b)/2.;
  }
}

namespace foobar {
  double mean(const double& a, const double& b) {
    return (a*a+b*b)/2.;
  }
}

int main() {

   double x = 3;
   double y = 4;

   double z1 = physics::mean(x,y);
   std::cout << "physics::mean(" << x << "," << y << ") = " << z1 
             << std::endl;

   double z2 = foobar::mean(x,y);
   std::cout << "foobar::mean(" << x << "," << y << ") = " << z2 
             << std::endl;

   return 0;
}
