// mean.cc
#include <iostream>

using namespace std;

void computeMean(const double* data, int nData, double& mean) {

  mean = 0.;
  for(int i=0; i<nData; ++i) {
    cout << "data: " << data << ", *data: " << *data << endl;
    mean += *data;
    data++;
  }
  mean /= nData; // divide by number of data points

}

int main() {

   double pressure[] = { 1.2, 0.9, 1.34, 1.67, 0.87, 1.04, 0.76 };
   double average;

   computeMean( pressure, 7, average );

   cout << "average pressure: " << average << endl;

   return 0;
}
