#include <iostream>
using namespace std;

class Result {
  public:

   // constructors
   Result() { };
   Result(const double& mean, const double& stdDev) {
     mean_ = mean;
     stdDev_ = stdDev;
   }

   // accessors
   double getMean() { return mean_; };
   double getStdDev() { return stdDev_; };

  private:
   double mean_;
   double stdDev_;
};

int main() {

  Result r1;
  cout << "r1, mean: " << r1.getMean()
       << ", stdDev: " << r1.getStdDev()
       << endl;

  Result r2(1.1,0.234);
  cout << "r2, mean: " << r2.getMean()
       << ", stdDev: " << r2.getStdDev()
       << endl;

  return 0;
}
