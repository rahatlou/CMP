#ifndef FooDatum_h
#define FooDatum_h
// FooDatum.h

class FooDatum {
  public:
    FooDatum();
    FooDatum(double x, double y);
    FooDatum(const FooDatum& datum);
    double value() { return value_; }
    double error() { return error_; }
    double significance();

  private:
    double value_;
    double error_;
};
#endif
