#ifndef Datum3_h
#define Datum3_h
// Datum3.h
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

    void print(std::string comment) const; // pasing by value

    void setValue(double x) { value_ = x; }
    void setError(double x) { error_ = x; }

  private:
    double value_;
    double error_;
};
#endif
