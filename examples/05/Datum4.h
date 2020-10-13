#ifndef Datum4_h
#define Datum4_h
// Datum4.h
#include <iostream>
#include <string>
using namespace std;

class Datum {
  public:
    Datum();
    Datum(double x, double y);
    Datum(const Datum& datum);

    double value() const { return value_; }
    double error() const { return error_; }
    double significance() const;

    void print(const std::string& comment) ; // passing by const ref

    void setValue(double x) { value_ = x; }
    void setError(double x) { error_ = x; }

  private:
    double value_;
    double error_;
};
#endif
