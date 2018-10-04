#include <iostream>
using std::cout;
using std::endl;

class Datum {
  public:
    Datum() { }
    Datum(double val, double error) {
      value_ = val;
      error_  = error;
    }

  double value() { return value_; }
  double error() { return error_; }

  void setValue(double value) { value_ = value; }
  void setError(double error) { error_ = error; }

  double value_; // public data member!!!

  private:
    double error_; // private data member
};

int main() {

  Datum d1(1.1223,0.23);

  cout << "d1.value(): " << d1.value() 
       << " d1.error(): " << d1.error()
       << endl;


  cout << "d1.value_: " << d1.value_
       << " d1.error_: " << d1.error_
       << endl;

  return 0;
}
