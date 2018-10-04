// class2.cc
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

  private:
    double value_;
    double error_;
};


int main() {

  Datum d1(1.1223,0.23);
  d1.setValue( 8.563 ); // setter with no return value
  double x = d1.value(); // getter to acces private data

  cout << "d1.value(): " << d1.value() 
       << " d1.error(): " << d1.error() << endl;

  d1.print();

  return 0;
}
