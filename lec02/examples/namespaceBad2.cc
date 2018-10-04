// namespaceBad2.cc
#include <iostream>

namespace physics {
  double mean(const double& a, const double& b) { return (a+b)/2.; }
}

namespace foobar {
  double mean(const double& a, const double& b) { return (a*a+b*b)/2.; }
}

using namespace foobar;
using namespace physics;
using namespace std;

int main() {

   double x = 3;
   double y = 4;

   double z1 = mean(x,y);
   cout << "mean(" << x << "," << y << ") = " << z1 
        << endl;

   double z2 = mean(x,y);
   cout << "foobar::mean(" << x << "," << y << ") = " << z2 
        << endl;

   return 0;
}
