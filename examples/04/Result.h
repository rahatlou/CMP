#ifndef Result_h
#define Result_h

class Result {
  public:
    Result();
    Result(double x, double y);
    Result(const Result& Result);
    double mean() { return mean_; }
    double stdDev() { return stdDev_; }
    double significance();
    void display();

  private:
    double mean_;
    double stdDev_;
};
#endif
