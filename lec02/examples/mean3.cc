// mean3.cc
#include <iostream>
#include <cmath>
using namespace std;

double mean(const double* data, int nData) {
  double m = 0.;
  for(int i=0; i<nData; ++i) {
    m += *data;
    data++;
  }
  m /= nData; // divide by number of data points
  return m;
}

double stdDev(const double* data, int nData) {
  double m = mean(data, nData); // use mean() method. No code duplication!
  double stdDev = 0.;
  for(int i=0; i<nData; ++i) {
    stdDev += pow(*data-m,2.);
    data++;
  }
  stdDev /= (nData-1); // divide by n -1
  stdDev = sqrt( stdDev ); // finally compute the stdDev
  return stdDev;
}

int main() {

   double pressure[] = { 1.2, 0.6, 1.8 }; // only 3 elements
   double average = mean(pressure, 3);
   double dev = stdDev(pressure, 3);

   cout << "average pressure: " << average << " with std deviation: " << dev << endl;

   return 0;
}
