// intro1.cc
#include <iostream>

using namespace std;

void computeMean(const double* data, int nData, double& mean, double& stdDev) {
 // two variables passed by reference to void function
}


double meanWithStdDev(const double* data, int nData, double& stdDev) {
  // error passed by reference to mean function! ugly!! anti-intuitive
}

double mean(const double* data, int nData, double& mean) {
  // one method to compute only average
}

double stdDev(const double* data, int nData, double& stdDev) {
  // one method to compute standard deviation
}
