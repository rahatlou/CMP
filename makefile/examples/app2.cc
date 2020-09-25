#include "MCIntegrator.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

  MCIntegrator mcalgo(100);
  mcalgo.setIntegrand(sin);

  double a,b;
  cout << "Program computes integral of the sinus function between  a x Pi -> b x Pi" << endl;
  cout << "a: ";
  cin >> a;
  cout << "b: ";
  cin >> b;

  double analyticalIntegral = -cos(b*M_PI) - (-cos(a*M_PI));
  cout << "analytical integral: " << analyticalIntegral << endl;


  for(int n= 10; n< 1e8; n *=10 ) {
      mcalgo.setNPoints(n);
      double sum = mcalgo.integrate( a*M_PI, b*M_PI ); // integral from a -> b
      cout << "# points: " << setw(10) << n
           << "\t Integral: " << setprecision(6) << sum
           << "\t residual: "
           << sum - analyticalIntegral
           << "\t fractional difference: " << setprecision(3) << 100*(sum - analyticalIntegral)/analyticalIntegral << " %"
           << endl;
  }



}
