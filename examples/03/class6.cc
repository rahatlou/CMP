// class6.cc
#include <iostream>
using namespace std;

class Datum {
  public:
    Datum(double val, double error) {
      value_ = val;
      error_  = error;
    }

    double value() { return value_; }
    double error() { return error_; }

    void setValue(double value) { value_ = value; }
    void setError(double error) { error_ = error; }

    void print() {
      cout << "datum: " << value_ << " +/- " << error_ << endl;
    }

  //private:       // alla data are public!
    double value_;
    double error_;
};


int main() {

  Datum d1(1.1223,0.23);
  double x = d1.value();
  double y = d1.error_;

  cout << "x: " << x << "\t y: " << y << endl;

  return 0;
}
