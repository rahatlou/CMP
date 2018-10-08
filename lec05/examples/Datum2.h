#ifndef Datum2_h
#define Datum2_h
// Datum2.h
#include <iostream>
using namespace std;

class Datum {
  public:
    Datum();
    Datum(double x, double y);
    Datum(const Datum& datum);

    double value() const { return value_; }
    double error() const { return error_; }
    double significance() const;
    void print() const;

    void setValue(double x) const { value_ = x; }
    void setError(double x) const { error_ = x; }

  private:
    double value_;
    double error_;
};
#endif
