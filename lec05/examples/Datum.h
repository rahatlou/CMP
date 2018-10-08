#ifndef Datum_h
#define Datum_h
// Datum.h
#include <iostream>
using namespace std;

class Datum {
  public:
    //Datum();
    Datum(double x=1.0, double y=0.0);
    Datum(const Datum& datum);
    double value() { return value_; }
    double error() { return error_; }
    double significance();
    void print();

  private:
    double value_;
    double error_;
};
#endif
