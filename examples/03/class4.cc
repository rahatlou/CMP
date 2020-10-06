// class4.cc
#include <iostream>
using namespace std;

class Datum {
  public:
    Datum() { reset(); } // reset data members

    double value() { return value_; }
    double error() { return error_; }

    void setValue(double value) { value_ = value; }
    void setError(double error) { error_ = error; }

    void print() {
      cout << "datum: " << value_ << " +/- " << error_ << endl;
    }

  private:
    void reset() {
      value_ = 0.0;
      error_ = 0.0;
    }

    double value_;
    double error_;
};


int main() {

  Datum d1;
  d1.setValue( 8.563 );
  d1.print();
  d1.reset();

  return 0;
}
