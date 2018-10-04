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
