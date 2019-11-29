#include "MCIntegrator.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

  MCIntegrator mcalgo(100);
  mcalgo.setIntegrand(exp);

  double a,b;
  cout << "Program computes integral of the exponential function between  a->b" << endl;
  cout << "a: ";
  cin >> a;
  cout << "b: ";
  cin >> b;

  double analyticalIntegral = mcalgo.integrand(b) - mcalgo.integrand(a);
  cout << "analytical integral: " << analyticalIntegral << endl;


  for(int n= 10; n< 1e8; n *=10 ) {
      mcalgo.setNPoints(n);
      double sum = mcalgo.integrate( a, b ); // integral from a -> b
      cout << "# points: " << setw(10) << n
           << "\t Integral: " << setprecision(6) << sum
           << "\t residual: "
           << sum - analyticalIntegral
           << "\t fractional difference: " << setprecision(3) << 100*(sum - analyticalIntegral)/analyticalIntegral << " %"
           << endl;
  }



}
