#ifndef Datum1_h
#define Datum1_h
// Datum.h
#include <iostream>
using namespace std;

class Datum {
  public:
    Datum();
    Datum(double x=1.0, double y=0.0);
    Datum(const Datum& datum);
    ~Datum() { };

    double value() const { return value_; }
    double error() const { return error_; }
    double significance() const;
    void print() const;

    Datum operator+( const Datum& rhs );

  private:
    double value_;
    double error_;
};
#endif
