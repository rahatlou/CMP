// class7.cc
#include <iostream>
using namespace std;

class Datum {
  public:
    Datum(double val, double error) {
      val_ = val;
      err_  = error;
    }

    double value() { return val_; }
    double error() { return err_; }

    void setValue(double value) { val_ = value; }
    void setError(double error) { err_ = error; }

    void print() {
      cout << "datum: " << val_ << " +/- " << err_ << endl;
    }

  //private:       // alla data are public!
    double val_;
    double err_;
};


int main() {

  Datum d1(1.1223,0.23);
  double x = d1.value();
  double y = d1.error_;

  cout << "x: " << x << "\t y: " << y << endl;

  return 0;
}
