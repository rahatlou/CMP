// namespaceBad.cc
#include <iostream>

namespace physics {
  double mean(const double& a, const double& b) {
    return (a+b)/2.;
  }
}

int main() {

   double x = 3;
   double y = 4;

   double z1 = mean(x,y);
   cout << "physics::mean(" << x << "," << y << ") = " << z1 
             << std::endl;

   return 0;
}
