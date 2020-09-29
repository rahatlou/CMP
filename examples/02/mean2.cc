// mean2.cc
#include <iostream>

using namespace std;

double mean(const double* data, int nData) {

  double mean = 0.;
  for(int i=0; i<nData; ++i) {
    cout << "data: " << data << ", *data: " << *data << endl;
    mean += *data;
    data++;
  }
  mean /= nData; // divide by number of data points
  return mean;
}

int main() {

   double pressure[] = { 1.2, 0.6, 1.8 }; // only 3 elements
   double average = mean(pressure, 4); // mistake! 

   cout << "average pressure: " << average << endl;

   return 0;
}
