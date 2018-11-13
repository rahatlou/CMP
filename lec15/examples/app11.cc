#include "CustomIntegrator.h"
#include "CustomMCIntegrator.h"
#include "Function.h"
#include "Gauss.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

  CustomMCIntegrator cinteg = CustomMCIntegrator();
  Function*  g1 = new Gauss("g1", 0., 1.);
  cinteg.setIntegrand( g1 );

  double a,b;
  cout << "Program computes integral of the Gaussian function between  a x sigma -> b x sigma" << endl;
  cout << "a: ";
  cin >> a;
  cout << "b: ";
  cin >> b;

  for(int n= 10; n< 1e8; n *=10 ) {
      cinteg.setNPoints(n);
      double sum = cinteg.integrate( a, b ); // integral from a -> b
      cout << "# points: " << setw(10) << n
           << "\t Integral: " << setprecision(6) << sum
           << endl;
  }



}
